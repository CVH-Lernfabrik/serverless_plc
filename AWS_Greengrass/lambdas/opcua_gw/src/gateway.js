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

require('json_utils');

//--------------
// Definitions:
//--------------

// Error codes
const STATUS_OK             = 0x00;
const PARAM_ERR             = 0x01;
const CONNECTION_ERR        = 0x02;
const SESSION_CREATE_ERR    = 0x03;
const SUBSCRIPTION_ERR      = 0x04;
const WRITE_ERR             = 0x05;

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
     * @param {Object} nodeset                  - Mapping between client- and
     *                                            server-side representation
     *                                            of the OPC UA nodeset
     * @param {Object} monitoredNodes           - List of OPC UA nodes to monitor
     * @param {Object} connectionParameters     - Name and URL of the OPC UA
     *                                            server to connect to as well
     *                                            as potential security settings
     *                                            for the connection
     * @param {Object} subscriptionParameters   - Subscription parameters
     * @param {Object} monitoringParameters     - Monitoring parameters
     */
    constructor(client, nodeset, monitoredNodes, connectionParameters, subscriptionParameters, monitoringParameters) {
        if ( !(client instanceof opcua.OPCUAClient)
            || !(typeof nodeset === 'object')
            || !(typeof monitoredNodes === 'object')
            || !(typeof connectionParameters === 'object')
            || !(typeof subscriptionParameters === 'object')
            || !(typeof monitoringParameters === 'object')
        ) {
            LOGGER.ERROR('OPCUAGateway: Invalid transfer parameters! Exiting!');
            process.exit(PARAM_ERR);
        }
        if ( (opcua == null)
            || (IoTData == null)
        ) {
            LOGGER.ERROR('OPCUAGateway: Please set opcua and IoTData before initializing OPCUAGateway!');
            process.exit(PARAM_ERR);
        }

        this._client                    = client;
        this._nodeset                   = nodeset;
        this._monitoredNodes            = monitoredNodes;
        this._connectionParameters      = connectionParameters;
        this._subscriptionParameters    = subscriptionParameters;

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

        // Resolve the specified security settings
        this._client.securityMode   = opcua.MessageSecurityMode.get(this._connectionParameters.securityMode);
        this._client.securityPolicy = opcua.SecurityPolicy.get(this._connectionParameters.securityPolicy);

        // Get the server certificate if the former is self-signed and the
        // specified security mode is higher than NONE
        if ( this._connectionParameters.serverCertificateSelfSigned
            && (this._connectionParameters.securityMode != 'NONE')
        ) {
            try {
                this._client.serverCertificate  = opcua.crypto_utils.readCertificate(this._connectionParameters.serverCertificate);
            }
            catch (e) {
                LOGGER.ERROR('Invalid server certificate specified! Exception: ' + e);
                LOGGER.WARN('Falling back to security mode NONE!');

                this._client.securityMode       = opcua.MessageSecurityMode.get('NONE');
                this._client.securityPolicy     = opcua.SecurityPolicy.get('None');
            }
        }

        // Try to establish a connection to the server
        this._client.connect(this._connectionParameters.url, (connectError) => {
            if (connectError) {
                LOGGER.ERROR('connect: Failed to establish connection to ' + this._connectionParameters.url + '! Exiting! RC: ' + connectError);
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

        var userIdentity = null;
        if ( this._connectionParameters.username
            && this._connectionParameters.password
        ) {
            userIdentity = {
                userName: this._connectionParameters.username,
                password: this._connectionParameters.password
            };
        }

        this._client.createSession(userIdentity, (createSessionError, session) => {
            if (createSessionError) {
                LOGGER.ERROR('createSession: Failed to create the session! Exiting! RC: ' + createSessionError);
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
            LOGGER.LOG('createSession: SessionId: ' + session.sessionId.toString());
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
        if ( !(this._session instanceof opcua.ClientSession) ) {
            LOGGER.ERROR('createSubscription: No active session!');
            return SESSION_CREATE_ERR;
        }

        LOGGER.LOG('createSubscription: Initializing subscription!');

        this._subscription = new opcua.ClientSubscription(this._session, this._subscriptionParameters);
        this._subscription.on('started', () => {
            LOGGER.LOG('createSubscription: Started subscription: ' + this._subscription.subscriptionId);
            this.emit('subscribed');
        }).on('status_changed', (rc, v) => {
            LOGGER.LOG('createSubscription: Status changed! RC: ' + rc + ' Value: ' + v);
        }).on('internal_error', (rc) => {
            LOGGER.ERROR('createSubscription: Internal error! Exiting! RC: ' + rc.message);
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
        if ( !this._isConnected
            || !(this._subscription instanceof opcua.ClientSubscription)
        ) {
            LOGGER.ERROR('monitorNodes: No active connection / subscription!');
            return CONNECTION_ERR;
        }

        this._monitoredNodes.forEach( (element) => {
            // Parse the format in case the absolute path was specified
            if (typeof element === 'string') {
                var absPath = element.split('.');
                element = {
                    "thingName": absPath[0],
                    "subscriptions": [absPath.slice(2, absPath.length)]
                }
            }

            // Resolve the superordinate thing by thingName
            var thing = this._nodeset.filter( (thing) => {
                return (thing.thingName == element.thingName);
            })[0];
            if (!thing) {
                LOGGER.WARN('monitorNodes: Invalid thing specified: ' + element.thingName);
                return;
            }

            element.subscriptions.forEach( (path) => {
                // Resolve the node to subscribe by path
                const monitoredNode = JSON.getObjectByPath(thing.UANodes, path);
                if ( !monitoredNode
                    || (monitoredNode.UANodeClass != 'Variable')
                    || !(Object.prototype.hasOwnProperty.call(monitoredNode, 'nodeId'))
                ) {
                    LOGGER.WARN('monitorNodes: Invalid item specified: ' + path);
                    return;
                }

                LOGGER.LOG('monitorNodes: Initializing monitoring of node: ' + monitoredNode.nodeId);

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
                            "reported": JSON.createObjectFromPath(path, dataValue.value.value)
                        }
                    };
                    const payload_string = JSON.stringify(payload_json);

                    // Update the local Shadow representation
                    IoTData.publish(
                        {
                            topic: thing.topic,
                            payload: payload_string,
                        },
                        (rc) => {
                            if (rc) {
                                LOGGER.ERROR(monitoredItem.itemToMonitor.nodeId.toString() + ': Failed to update local Shadow of thing ' + thing.thingName + ' with state ' + payload_string + '. RC: ' + rc);
                            }
                            else {
                                LOGGER.LOG(monitoredItem.itemToMonitor.nodeId.toString() + ': Successfully updated local Shadow of thing ' + thing.thingName + ' with  ' + payload_string + '. RC: ' + rc);
                            }
                        }
                    );
                });

                // Callback for logging errors occuring during the monitoring process
                monitoredItem.on('err', (errorMessage) => {
                    LOGGER.ERROR(monitoredItem.itemToMonitor.nodeId.toString() + ': Error! RC: ' + errorMessage);
                });
            });
        });
    }

    /*
     * Description: Sets the OPC UA node(s) matching the specified pattern to
     *              the desired value resp. calls the respective OPC UA method(s)
     *
     * @param {String} thingName    - Identifier of the (logically) superordinate
     *                                instance / object of the OPC UA node to
     *                                write, that, in combination with path,
     *                                can be resolved to the unique nodeId
     * @param {String} path         - Unique identifier of the logical equivalent
     *                                of the OPC UA node (resp. method) to write
     *                                in the form of the object path within the
     *                                nodeset hierarchy, that, in combination
     *                                with thingName, can be resolved to the
     *                                unique node / method ID
     * @param {Object} value        - Desired value to write to the specified node;
     *                                serve(s) as input argument(s) in case the
     *                                target is a method and no object node
     *
     * @returns {number}            - Status / Return code of the write operation
     */
    writeNode(thingName, path, value) {
        if ( !(typeof thingName === 'string')
            || !(typeof path === 'string')
        ) {
            LOGGER.ERROR('writeNode: Invalid transfer parameters!');
            return PARAM_ERR;
        }
        if ( !this._isConnected
            || !(this._session instanceof opcua.ClientSession)
        ) {
            LOGGER.ERROR('writeNode: No active connection / session!');
            return CONNECTION_ERR;
        }

        // Resolve the thing matching the specified name
        var thing = this._nodeset.filter( (thing) => {
            return (thing.thingName == thingName);
        })[0];

        // Resolve the node to write resp. the method to call by path
        const node = JSON.getObjectByPath(thing.UANodes, path);
        if ( !node
            || !(Object.prototype.hasOwnProperty.call(node, 'nodeId'))
        ) {
            LOGGER.WARN('writeNode: Invalid item specified: ' + path);
            return PARAM_ERR;
        }

        // The call for the write operation differs depending on whether
        // the concerned node is a method or an object node.
        if ( node.UANodeClass == 'Method' ) {
            if ( node.inputArguments.length != value.length ) {
                LOGGER.WARN('Skipping method ' + node.nodeId + ' as the number of given arguments does not match the required number of transfer parameters!');
                return PARAM_ERR;
            }

            // Get the parent node of the method (resp. the superordinate object
            // the method is an element of)
            // Annotation: Assumes that no methods may be located on the highest
            // hierarchy level of the nodeset
            const parentPath    = path.split('.').slice(0, -2).join('.');
            const parent        = JSON.getObjectByPath(thing.UANodes, parentPath);
            if ( !parent
                || !(Object.prototype.hasOwnProperty.call(parent, 'nodeId'))
            ) {
                LOGGER.WARN('Skipping method ' + node.nodeId + ' as no valid parent node could be found!');
                return WRITE_ERR;
            }

            var objectId        = parent.nodeId
            var methodId        = node.nodeId;
            var inputArguments  = [];
            node.inputArguments.forEach( (inputArgument) => {
                inputArguments = inputArguments.concat({
                    'dataType': opcua.DataType.get(inputArgument.UADataType),
                    'value': value[node.inputArguments.indexOf(inputArgument)]
                });
            });
            const methodToCall = {
                'objectId': objectId,
                'methodId': methodId,
                'inputArguments': inputArguments
            };

            // Call the specified method w/ the corresponding transfer parameters
            this._session.call(
                methodToCall,
                (err, rc) => {
                    if (err) {
                        LOGGER.ERROR('Error occured during method call! Err: ' + err + ' RC: ' + rc);
                    }
                    else {
                        LOGGER.LOG('Method call successful! RC: ' + rc);
                    }
                }
            );
        }
        else {
            var nodeId      = node.nodeId;
            var dataType    = opcua.DataType.get(node.UADataType);
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
                        LOGGER.ERROR('Error occured during write operation! Err: ' + err + ' RC: ' + rc);
                    }
                    else {
                        LOGGER.LOG('Write operation successful! RC: ' + rc);
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
        if ( node_opcua instanceof Object ) {
            opcua = node_opcua;
        }
        else {
            LOGGER.ERROR('setOpcua: Invalid type for node_opcua! Exiting!');
            return PARAM_ERR;
        }
    },
    setIoTData: (device) => {
        if ( (device instanceof Object)
            && (typeof device.publish === 'function')
        ) {
            IoTData = device;
        }
        else {
            LOGGER.ERROR('setIoTData: Invalid type for device! Exiting!');
            return PARAM_ERR;
        }
    }
};
