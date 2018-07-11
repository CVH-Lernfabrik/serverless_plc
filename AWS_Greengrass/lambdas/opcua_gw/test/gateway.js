// gateway.js
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-06-28
//
// Description: This class implements a simple OPC UA gateway functionality
// with integrated synchronization with AWS using the AWS IoT Shadow Engine.

'use strict';

//---------------
// Requirements:
//---------------

require('requirish')._(module);

const util = require('util');
const EventEmitter = require('events');

//--------------
// Definitions:
//--------------

// Error codes
const PARAM_ERR             = 0x01;
const CONNECTION_ERR        = 0x02;
const SESSION_CREATE_ERR    = 0x03;
const SUBSCRIPTION_ERR      = 0x04;

let Opcua;

//----------
// Gateway:
//----------

/*
 * Description: This class implements a simple OPC UA gateway functionality with
 *              integrated synchronization with AWS using the AWS IoT Shadow
 *              Engine.
 *
 * @augments EventEmitter
 */
class OPCUAGateway {

    /*
     * Description: Constructor for the class OPCUAGateway
     *
     * @constructs OPCUAGateway
     *
     * @param {Object} client                   - OPC UA client object
     * @param {Object} serverParameters         - Name and URL of the OPC UA
     *                                            server to connect to
     * @param {Object} subscriptionParameters   - Subscription parameters
     * @param {Object} monitoringParameters     - Monitoring parameters
     * @param {Object} listOfMonitoredItems     - List including the server-side
     *                                            nodes to monitor
     */
    constructor(client, serverParameters, subscriptionParameters, monitoringParameters, listOfMonitoredItems) {
        if ( !(client instanceof Opcua.OPCUAClient)
            || !(typeof serverParameters === 'object')
            || !(typeof subscriptionParameters === 'object')
            || !(typeof monitoringParameters === 'object')
            || !(typeof listOfMonitoredItems === 'object')
        ) {
            console.log('OPCUAGateway: Invalid transfer parameters! Exiting!');
            process.exit(PARAM_ERR);
        }
        if ( (Opcua == null) ) {
            console.log('OPCUAGateway: Please set Opcua before initializing OPCUAGateway!');
            process.exit(PARAM_ERR);
        }

        this._client                    = client;
        this._serverParameters          = serverParameters;
        this._subscriptionParameters    = subscriptionParameters;
        this._listOfMonitoredItems      = listOfMonitoredItems;

        this._isConnected               = false;

        // Associate the callbacks to the individual events
        this.on('connect', () => {
            this.createSession();
        });
        this.on('session_created', () => {
            this.createSubscription();
        });
        this.on('subscribed', () => {
            this.monitorNodes();
        });
    }

    /*
     * Description: Returns the current connection status
     */
    getConnectionStatus() {
        return this._isConnected;
    }

    /*
     * Description: Tries to establish a connection to the specified OPC UA server
     *
     * @fires connect
     */
    connect() {
        console.log('connect: Connecting to the server!');

        this._client.connect(this._serverParameters.url, (connectError) => {
            if (connectError) {
                console.error('connect: Failed to establish connection to ', this._serverParameters.url, '! Exiting! RC: ', connectError);
                process.exit(CONNECTION_ERR);
            }

            // Watchdog callback; try to reconnect to the server if the connection
            // is lost
            this._client.on('close', () => {
                console.error('OPCUAGateway: Connection to the server lost! Trying to reconnect!');

                this._isConnected = false;

                this._client.off('close');
                this.connect();
            });

            console.log('connect: Successfully connected to the server!');
            this.emit('connect');
        });
    }

    /*
     * Description: Tries to initiate an OPC UA session w/ the server
     *
     * @listens connect
     * @fires session_created
     */
    createSession() {
        console.log('createSession: Establishing session!');

        const userIdentity = null;
        this._client.createSession(userIdentity, (createSessionError, session) => {
            if (createSessionError) {
                console.error('createSession: Failed to create the session! Exiting! RC: ', createSessionError);
                process.exit(SESSION_CREATE_ERR);
            }

            this._session = session;
            this._isConnected = true;

            // Watchdog callbacks; try to reestablish the session if a timeout
            // occures or the server force-closes the session
            this._session.on('keepalive_failure', () => {
                console.error('OPCUAGateway: Session timed out! Trying to reestablish!');

                this._isConnected = false;

                this._session.off('keepalive_failure');
                this.createSession();
            });
            this._session.on('session_closed', () => {
                console.error('OPCUAGateway: Session closed! Trying to reestablish!');

                this._isConnected = false;

                this._session.off('keepalive_failure');
                this.createSession();
            });

            console.log('createSession: Session created successfully!');
            console.log('createSession: SessionId: ', session.sessionId.toString());
            this.emit('session_created');
        });
    }

    /*
     * Description: Tries to create a client subscription that allows for
     *              callbacks to be attached to server-side nodes for monitoring
     *              purposes (cf. monitorNodes)
     *
     * @listens session_created
     * @listens started
     * @listens internal_error
     * @listens status_changed
     * @fires subscribed
     */
    createSubscription() {
        console.log('createSubscription: Initializing subscription!');
        
        this._subscription = new Opcua.ClientSubscription(this._session, this._subscriptionParameters);
        this._subscription.on('started', () => {
            console.log('createSubscription: Started subscription: ', this._subscription.subscriptionId);
            this.emit('subscribed');
        }).on('status_changed', (rc, v) => {
            console.log('createSubscription: Status changed! RC: ', rc, ' Value: ', v);
        }).on('internal_error', (rc) => {
            console.error('createSubscription: Internal error! Exiting! RC: ', rc.message);
            process.exit(SUBSCRIPTION_ERR);
        });
    }

    /*
     * Description: Attaches monitoring callbacks to each specified node and
     *              synchronizes their states w/ AWS IoT
     *
     * @listens subscribed
     * @listens initialized
     * @listens changed
     * @listens err
     */
    monitorNodes() {
        this._listOfMonitoredItems.forEach((monitoredNode) => {
            console.log('monitorNodes: Initializing monitoring of node: ', monitoredNode.nodeId);

            // Initialize the (periodical) monitoring of the specified node
            const monitoredItem = this._subscription.monitor(
                {
                    nodeId: monitoredNode.nodeId,
                    attributeId: Opcua.AttributeIds.Value,
                },
                this._monitoringParameters
            );

            monitoredItem.on('initialized', () => {
                console.log('monitorNodes: Successfully initialized monitoredItem!');
            });

            // Callback for synchronizing state changes w/ AWS IoT
            monitoredItem.on('changed', (dataValue) => {
                const payload_json = {
                    thingName: monitoredNode.thingName,
                    payload: {
                        "state": {
                            "reported": {
                                [monitoredNode.propertyName]: dataValue.value.value
                            }
                        }
                    }
                };
                const payload_string = JSON.stringify(payload_json);
                console.log(payload_string);
            });

            // Callback for logging errors occuring during the monitoring process
            monitoredItem.on('err', (errorMessage) => {
                console.error(monitoredItem.itemToMonitor.nodeId.toString(), ': Error! RC: ', errorMessage);
            });
        });
    }
}

// Inheritance from EventEmitter to allow for a reacitve programming paradigm
util.inherits(OPCUAGateway, EventEmitter);

//----------
// Exports:
//----------

module.exports = {
    OPCUAGateway: OPCUAGateway,
    setOpcua: (opcua) => {
        if (opcua instanceof Object) {
            Opcua = opcua;
        }
        else {
            console.error('setOpcua: Invalid type for opcua! Exiting!');
            return PARAM_ERR;
        }
    },
};
