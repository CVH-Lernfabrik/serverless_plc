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

    if ( !client || !gateway ) {
        console.error('client and gateway need to be initialized before interacting w/ the OPC UA server!');
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
        // Resolve the ID of the OPC UA node belonging to the specified thing
        // name + property name combination and set the respective node to the
        // desired value

        // Resolve the node(s) matching the specified pattern
        var nodes = subscriptions.subscriptions.filter((node) => {
            return ( (node.thingName == thingName) && node.propertyName == propertyName) );
        });

        // Annotation: The enclosing for-loop is solely for the case that the
        // specified thing name + property name combination is not unique to
        // one node ID. In this case, all nodes matching the pattern are set
        // to the desired value.
        for (var node in nodes) {
            // Set the specified node to the desired state
            rc = gateway.writeNode(node.nodeId, payload[propertyName]);
            if (rc) {
                console.error('Failed to set node', nodeId, 'to', value, '! RC:', rc);
                context.fail();
            }
            else {
                console.log('Successfully set node', nodeId, 'to', value, '!');
                context.succeed();
            }
        }
    }




    TODO:
    // 1. Network Interface -> Greengrass sporadischer Ausfall
    // 2. Worker Killed bei Start der Gateway Lambda




};
