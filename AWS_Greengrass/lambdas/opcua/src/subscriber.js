// subscriber.js
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-06-28
//
// Description: This class implements a simple OPC UA subscription functionality
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

let Opcua;
let IoTData;

//-------------
// Subscriber:
//-------------

/*
 * Description: This class implements a simple OPC UA subscription functionality
 *              with integrated synchronization with AWS using the AWS IoT Shadow
 *              Engine.
 *
 * @augments EventEmitter
 */
class OPCUASubscriber {

    /*
     * Description: Constructor for the class OPCUASubscriber
     *
     * @constructs OPCUASubscriber
     *
     * @param {Object} session - (Established) OPC UA session w/ the server
     */
    constructor(session, subscriptionParameters, listOfMonitoredItems) {
        if ( !(session instanceof ClientSession) || !(subscriptionParameters typeof 'string') || !(listOfMonitoredItems typeof 'string') ) {
            console.log('OPCUASubscriber: Invalid transfer parameters! Exiting!');
            process.exit(1);
        }

        this._session                   = session;
        this._subscriptionParameters    = subscriptionParameters;
        this._listOfMonitoredItems      = listOfMonitoredItems;

        // Associate the callbacks to the individual events
        this.on('subscribed', () => {
            this.monitorNodes();
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
        this._subscription = new Opcua.ClientSubscription(this._session, this._subscriptionParameters);
        this._subscription.on('started', () => {
            console.log('createSubscription: Started subscription: ', this._subscription.subscriptionId);
            this.emit('subscribed');
        }).on('internal_error', (rc) => {
            console.log('createSubscription: Internal error! RC: ', rc.message);
        }).on('status_changed', (rc, v) => {
            console.log('createSubscription: Status changed! RC: ', rc, ' Value: ', v);
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
                config.MonitoringParameters
            );

            monitoredItem.on('initialized', () => {
                console.log('monitorNodes: Successfully initialized monitoredItem!');
            });

            // Callback for synchronizing state changes w/ AWS IoT
            monitoredItem.on('changed', (dataValue) => {
                const monitoredNodeName = monitoredNode.name;
                const serverName = config.Server.name;
                const nodeId = monitoredItem.itemToMonitor.nodeId.toString();
                const payload = {
                    id: nodeId,
                    value: dataValue.value,
                };
                const topic = '/opcua/${serverName}/node/${monitoredNodeName}';
                const payloadStr = JSON.stringify(payload);
                IoTData.publish(
                    {
                        topic: topic,
                        payload: payloadStr
                    },
                    (rc) => {
                        if (rc) {
                           console.log(monitoredItem.itemToMonitor.nodeId.toString(), ': Failed to publish ', payloadStr, ' on ', topic'. RC: ', rc);
                        }
                    });
            });

            // Callback for logging errors occuring during the monitoring process
            monitoredItem.on('err', (errorMessage) => {
                console.log(monitoredItem.itemToMonitor.nodeId.toString(), ': Error! RC: ', errorMessage);
            });
        });
    }
}

// Inheritance from EventEmitter to allow for a reacitve programming paradigm
util.inherits(OPCUASubscriber, EventEmitter);

//----------
// Exports:
//----------

module.exports = {
    OPCUASubscriber: OPCUASubscriber,
    setOPCUA: (opcua) => {
        Opcua = opcua;
    },
    setIoTData: (device) => {
        if (device instanceof IotData) {
            IoTData = device;
        }
        else {
            console.log('setIoTData: Invalid type for opcua! Exiting!');
            process.exit(1);
        }
    }
};
