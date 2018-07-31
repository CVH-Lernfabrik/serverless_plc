// index.js
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-06-28
//
// Description: OPC UA gateway functionality and state synchronization w/ AWS
// using the AWS Shadow Engine

'use strict';

//----------------------------------
// Requirements and initialization:
//----------------------------------

require('requirish')._(module);

const cluster       = require('cluster');
const opcua         = require('node-opcua');

const ggSDK         = require('aws-greengrass-core-sdk');
const device        = new ggSDK.IotData();

const Gateway       = require('gateway');
const OPCUAGateway  = Gateway.OPCUAGateway;

const subscriptions = require('subscriptions.json');
const config        = require('config.json');

Gateway.setOpcua(opcua);
Gateway.setIoTData(device);

//--------------
// Definitions:
//--------------

let client;
let gateway;

//-------------------------
// Cluster initialization:
//-------------------------

if (cluster.isMaster) {
    console.log('Master with PID', process.pid, 'started!');

    cluster.fork();

    cluster.on('exit', (worker, code, signal) => {
        console.error('OPC UA client with PID', worker.process.pid , 'died with RC:', code, '! Restarting!');
        cluster.fork();
    });
}
else {
    console.log('Setting up OPC UA client!');

    client  = new opcua.OPCUAClient(config.clientParameters);
    gateway = new OPCUAGateway(
        client,
        config.serverParameters,
        config.subscriptionParameters,
        config.monitoringParameters,
        subscriptions.subscriptions
    );
    gateway.connect();

    console.log('OPC UA client with PID', process.pid , 'started!');
}

//-----------------------
// Lambda event handler:
//-----------------------

exports.handler = (event, context) => {
    console.log('Received event:', JSON.stringify(event, null, 2), 'on context:', JSON.stringify(context, null, 2));

    if ( !client || !gateway ) {
        context.fail('client and gateway need to be initialized before interacting w/ the OPC UA server!');
    }
    if ( !gateway.getConnectionStatus() ) {
        context.fail('Currently no connection to the OPC UA server!');
    }
    if ( !event.hasOwnProperty('state') ) {
        context.fail('Invalid event passed!');
    }

    const payload = event.state;

    if ( !payload.hasOwnProperty('delta') ) {
        context.succeed('Nothing to synchronize!');
    }

    // Try to set the OPC UA server to the desired state
    payload.delta.forEach((thingName) => {
        // Resolve the node ID of the OPC UA object belonging to
    });

};
