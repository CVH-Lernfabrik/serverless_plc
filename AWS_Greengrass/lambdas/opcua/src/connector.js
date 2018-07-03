// connector.js
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-07-03
//





// Description: This class implements a simple OPC UA subscription functionality
// with integrated synchronization with AWS using the AWS IoT Shadow Engine. The
// configuration (including the user-defineable list of items / nodes to monitor)
// is provided in form of a JSON file (cf. config.json).




'use strict';

//---------------
// Requirements:
//---------------

require('requirish')._(module);

const util = require('util');
const EventEmitter = require('events');

const Subscriber = require('subscriber');

const config = require('config.json');

//--------------
// Definitions:
//--------------

let Opcua;
let IoTDevice;

//-------------
// Connector:
//-------------

/*
 * Description: This class implements a simple OPC UA subscription functionality
 *              with integrated synchronization with AWS using the AWS IoT Shadow
 *              Engine.
 *
 * @augments EventEmitter
 */
class OPCUAConnector {

    /*
     * Description: Constructor for the class OPCUAConnector
     *
     * @constructs OPCUAConnector
     *
     * @param {Object} session - (Established) OPC UA session w/ the server
     */
    constructor(client) {
        if ( !(session instanceof ClientSession) ) {
            console.log('OPCUASubscriber: Invalid type for session! Exiting!');
            process.exit(1);
        }

        this._session = session;

        // Associate the callbacks to the individual events
        this.on('connect', () => {
            this.createSession();
        });
        this.on('session_created', () => {
            this.subscribe();
        });
    }

    /*
     * Description: Tries to establish a connection to the specified OPC UA server
     *
     * @fires connect
     */
    connect() {
        this._client.connect(config.Server.url, (connectError) => {
            if (connectError) {
                console.log('connect: Failed to establish connecting to ', config.Server.url, '! RC: ', connectError);
                return;
            }
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
        const userIdentity = null;
        this._client.createSession(userIdentity, (createSessionError, session) => {
            if (!createSessionError) {
                this._session = session;
                console.log('createSession: Session created Successfully!');
                console.log('createSession: SessionId: ', session.sessionId.toString());
                this.emit('session_created');
            } else {
                console.log('createSession: Failed to create the session! RC: ', createSessionError);
            }
        });
    }

    /*
     * Description: Tries to create a client subscription that allows for
     *              callbacks to be attached to server-side nodes for monitoring
     *              purposes (cf. monitorNodes)
     *
     */
    subscribe() {
        this._subscriber = new
    }

// Inheritance from EventEmitter to allow for a reacitve programming paradigm
util.inherits(OPCUAConnector, EventEmitter);

//----------
// Exports:
//----------

module.exports = {
    OPCUAConnector: OPCUAConnector,
    setOPCUA: (opcua) => {
        Opcua = opcua;
    },
    setIoTData: (device) => {
        IoTData = device;
    }
};
