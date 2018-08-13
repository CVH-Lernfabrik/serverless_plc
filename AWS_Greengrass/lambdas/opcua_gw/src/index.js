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

/*
 * Description: Handles events forwarded to the Lambda function by the Greengrass
 *              Core; listenes to Shadow Delta messages and sets the OPC UA
 *              server to the desired state
 *
 * @param {Object} event    - event forwarded to the Lambda function by the GGC
 * @param {Object} context  - context of the event (incl. e.g. subject name)
 */
exports.handler = (event, context) => {
    console.log('Received event:', JSON.stringify(event, null, 2), 'on context:', JSON.stringify(context, null, 2));

    if ( (typeof gateway === 'undefined') ) {
        console.error('The gateway needs to be initialized before interacting w/ the OPC UA server!');
        context.fail();
    }
    if ( !event.hasOwnProperty('state') ) {
        console.error('Invalid event passed!');
        context.fail();
    }
    if ( !context.hasOwnProperty('clientContext') || !context.clientContext.hasOwnProperty('Custom') || !context.clientContext.Custom.hasOwnProperty('subject') ) {
        console.error('Invalid context!');
        context.fail();
    }

    // Extract the thing name and the payload from the event
    const subject   = context.clientContext.Custom.subject;
    const thingName = subject.split('/')[2];
    const payload   = event.state;

    for (var propertyName in payload) {
        var value = payload[propertyName];

        // Set the node(s) matching the specified pattern to the desired state
        var rc = gateway.writeNode(thingName, propertyName, value);
        if (rc) {
            console.error('Failed to initiate write operation to set', thingName + '.' + propertyName, 'to', value + '! RC:', rc);
            context.fail();
        }
        else {
            console.log('Successfully initiated write operation to set', thingName + '.' + propertyName, 'to', value + '!');
            context.succeed();
        }
    }
};
