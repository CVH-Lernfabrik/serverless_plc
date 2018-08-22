// worker.js
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-08-14
//
// Description: OPC UA gateway functionality and state synchronization w/ AWS
// using the AWS Shadow Engine -- Worker process --

'use strict';

//----------------------------------
// Requirements and initialization:
//----------------------------------

require('requirish')._(module);

const opcua         = require('node-opcua');

const ggSDK         = require('aws-greengrass-core-sdk');
const device        = new ggSDK.IotData();

const gateway       = require('gateway');
const OPCUAGateway  = gateway.OPCUAGateway;

const nodeset       = require('nodeset.json');
const config        = require('config.json');

gateway.setOpcua(opcua);
gateway.setIoTData(device);

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

//-------------------------
// Gateway initialization:
//-------------------------

LOGGER.LOG('Setting up OPC UA client and gateway!');

// Set up the OPC UA client and the gateway
const client  = new opcua.OPCUAClient(config.clientParameters);
const gw = new OPCUAGateway(
    client,
    nodeset,
    config.connectionParameters,
    config.subscriptionParameters,
    config.monitoringParameters
);

// Register the write callback
process.on('message', (msg) => {
    if ( !msg.hasOwnProperty('thingName') || !msg.hasOwnProperty('propertyName') || !msg.hasOwnProperty('value') ) {
        LOGGER.ERROR('Invalid message received from the master process!');
        return;
    }

    var thingName       = msg.thingName;
    var propertyName    = msg.propertyName;
    var value           = msg.value;

    // Set the node(s) matching the specified pattern to the desired state
    gw.writeNode(thingName, propertyName, value);
});

// Initiate the connection to the specified OPC UA server
gw.connect();

LOGGER.LOG('OPC UA gateway with PID ' + process.pid + ' started!');
