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
const eventEmitter = require('events');

//--------------
// Definitions:
//--------------

// Error codes
const STATUS_OK             = 0x00;
const PARAM_ERR             = 0x01;
const CONNECTION_ERR        = 0x02;
const SESSION_CREATE_ERR    = 0x03;
const SUBSCRIPTION_ERR      = 0x04;

// Variables
let opcua;
let IoTData;

//----------
// Loggers:
//----------

// Annotation: Even though uppercase for an object may appear like a break w/
// the JS style guide, this notation is retained in analogy to C / C++ macros.
const LOGGER = {};
['log', 'warn', 'error'].forEach( (logLevel) => {
    LOGGER[logLevel.toUpperCase()] = function (msg) {
        process.send({
            'type': logLevel,
            'msg': msg
        });
    };
});

//----------
// Gateway:
//----------

/*
 * Description: This class implements a simple OPC UA gateway functionality with
 *              integrated synchronization with AWS using the AWS IoT Shadow
 *              Engine.
 *
 * @augments eventEmitter
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
        if ( !(client instanceof opcua.OPCUAClient)
            || !(typeof serverParameters === 'object')
            || !(typeof subscriptionParameters === 'object')
            || !(typeof monitoringParameters === 'object')
            || !(typeof listOfMonitoredItems === 'object')
        ) {
            LOGGER.ERROR('OPCUAGateway: Invalid transfer parameters! Exiting!');
            process.exit(PARAM_ERR);
        }
        if ( (opcua == null) || (IoTData == null) ) {
            LOGGER.ERROR('OPCUAGateway: Please set opcua and IoTData before initializing OPCUAGateway!');
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
     * Description: Returns the current OPC UA session w/ the server
     */
    getSession() {
        if (this._isConnected) {
            return this._session;
        }
        else {
            return null;
        }
    }

    /*
     * Description: Tries to establish a connection to the specified OPC UA server
     *
     * @fires connect
     */
    connect() {
        LOGGER.LOG('connect: Connecting to the server!');

        this._client.connect(this._serverParameters.url, (connectError) => {
            if (connectError) {
                LOGGER.ERROR('connect: Failed to establish connection to ', this._serverParameters.url, '! Exiting! RC: ', connectError);
                process.exit(CONNECTION_ERR);
            }

            // Watchdog callback; try to reconnect to the server if the connection
            // is lost
            this._client.on('close', () => {
                LOGGER.ERROR('OPCUAGateway: Connection to the server lost! Trying to reconnect!');

                this._isConnected = false;

                this._client.removeAllListeners('close');
                this.connect();
            });

            LOGGER.LOG('connect: Successfully connected to the server!');
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
        LOGGER.LOG('createSession: Establishing session!');

        const userIdentity = null;
        this._client.createSession(userIdentity, (createSessionError, session) => {
            if (createSessionError) {
                LOGGER.ERROR('createSession: Failed to create the session! Exiting! RC: ', createSessionError);
                process.exit(SESSION_CREATE_ERR);
            }

            this._session = session;
            this._isConnected = true;

            // Watchdog callbacks; try to reestablish the session if a timeout
            // occures or the server force-closes the session
            this._session.on('keepalive_failure', () => {
                LOGGER.ERROR('OPCUAGateway: Session timed out! Trying to reestablish!');

                this._isConnected = false;

                this._session.removeAllListeners('keepalive_failure');
                this.createSession();
            }).on('session_closed', () => {
                LOGGER.ERROR('OPCUAGateway: Session closed! Trying to reestablish!');

                this._isConnected = false;

                this._session.removeAllListeners('session_closed');
                this.createSession();
            });

            LOGGER.LOG('createSession: Session created successfully!');
            LOGGER.LOG('createSession: SessionId: ', session.sessionId.toString());
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
        LOGGER.LOG('createSubscription: Initializing subscription!');

        this._subscription = new opcua.ClientSubscription(this._session, this._subscriptionParameters);
        this._subscription.on('started', () => {
            LOGGER.LOG('createSubscription: Started subscription: ', this._subscription.subscriptionId);
            this.emit('subscribed');
        }).on('status_changed', (rc, v) => {
            LOGGER.LOG('createSubscription: Status changed! RC: ', rc, ' Value: ', v);
        }).on('internal_error', (rc) => {
            LOGGER.ERROR('createSubscription: Internal error! Exiting! RC: ', rc.message);
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
            LOGGER.LOG('monitorNodes: Initializing monitoring of node: ', monitoredNode.nodeId);

            // Initialize the (periodical) monitoring of the specified node
            const monitoredItem = this._subscription.monitor(
                {
                    nodeId: monitoredNode.nodeId,
                    attributeId: opcua.AttributeIds.Value,
                },
                this._monitoringParameters
            );

            monitoredItem.on('initialized', () => {
                LOGGER.LOG('monitorNodes: Successfully initialized monitoredItem!');
            });

            // Callback for synchronizing state changes w/ the local device Shadow
            monitoredItem.on('changed', (dataValue) => {
                const payload_json = {
                    "state": {
                        "reported": {
                            [monitoredNode.propertyName]: dataValue.value.value
                        }
                    }
                };
                const payload_string = JSON.stringify(payload_json);

                // Update the local Shadow representation
                IoTData.publish(
                    {
                        topic: monitoredNode.topic,
                        payload: payload_string,
                    },
                    (rc) => {
                        if (rc) {
                           LOGGER.ERROR(monitoredItem.itemToMonitor.nodeId.toString(), ': Failed to update local Shadow of thing', monitoredNode.thingName, 'with state', payload_string, '. RC: ', rc);
                        }
                    }
                );
            });

            // Callback for logging errors occuring during the monitoring process
            monitoredItem.on('err', (errorMessage) => {
                LOGGER.ERROR(monitoredItem.itemToMonitor.nodeId.toString(), ': Error! RC: ', errorMessage);
            });
        });
    }

    /*
     * Description: Sets the OPC UA node(s) matching the specified pattern to
     *              the desired value
     *
     * @param {String} thingName    - Identifier of the (logically) superordinate
     *                                instance / object of the OPC UA node to
     *                                write, that, in combination with propertyName,
     *                                can be resolved to the unique nodeId
     * @param {String} propertyName - Identifier of the logical equivalent of the
     *                                OPC UA node to write, that, in combination
     *                                with thingName, can be resolved to the
     *                                unique nodeId
     * @param {Object} value        - Desired value to write to the specified node
     *
     * @returns {number}            - Status / Return code of the write operation
     */
    writeNode(thingName, propertyName, value) {
        if ( !(typeof thingName === 'string')
            || !(typeof propertyName === 'string')
        ) {
            LOGGER.ERROR('writeNode: Invalid transfer parameters!');
            return PARAM_ERR;
        }
        if ( !this._isConnected
            || (typeof this._session === 'undefined')
        ) {
            LOGGER.ERROR('writeNode: No active connection / session!');
            return CONNECTION_ERR;
        }

        // Resolve the node(s) matching the specified pattern
        var nodes = this._listOfMonitoredItems.filter( (node) => {
            return ( (node.thingName == thingName) && (node.propertyName == propertyName) );
        });

        // Annotation: The enclosing for-loop is solely for the case that the
        // specified thing name + property name combination is not unique to
        // one node ID. In this case, all nodes matching the pattern are set
        // to the desired value.
        for (var idx in nodes) {
            var nodeId      = nodes[idx].nodeId;
            var dataType    = opcua.DataType.enums.filter( (type) => {
                return (type.key == nodes[idx].UADataType);
            })[0];
            var value       = {
                    'dataType': dataType,
                    'value': value
            };

            // Set the specified node to the desired state
            this._session.writeSingleNode(
                nodeId,
                value,
                (err, rc) => {
                    if (err) {
                        LOGGER.ERROR('Error occured during write operation! Err:', err, 'RC:', rc);
                    }
                    else {
                        LOGGER.LOG('Write operation successful! RC:', rc);
                    }
                }
            );
        }
        return STATUS_OK;
    }
}

// Inheritance from eventEmitter to allow for a reacitve programming paradigm
util.inherits(OPCUAGateway, eventEmitter);

//----------
// Exports:
//----------

module.exports = {
    OPCUAGateway: OPCUAGateway,
    setOpcua: (node_opcua) => {
        if (node_opcua instanceof Object) {
            opcua = node_opcua;
        }
        else {
            LOGGER.ERROR('setOpcua: Invalid type for node_opcua! Exiting!');
            return PARAM_ERR;
        }
    },
    setIoTData: (device) => {
        if ( (device instanceof Object) && (typeof device.publish === 'function')) {
            IoTData = device;
        }
        else {
            LOGGER.ERROR('setIoTData: Invalid type for device! Exiting!');
            return PARAM_ERR;
        }
    }
};
