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

const IotData       = require('aws-greengrass-core-sdk').IoTData;
const device        = new IotData();

const Gateway       = require('gateway');
const OPCUAGateway  = Gateway.OPCUAGateway;

const subscriptions = require('subscriptions.json');
const config        = require('config.json');

Gateway.setOpcua(opcua);
Gateway.setIoTDevice(device);

//-------------------------
// Cluster initialization:
//-------------------------

if (cluster.isMaster) {
    console.log("Master with PID", process.pid, "started!");

    cluster.fork();

    cluster.on('exit', (worker, code, signal) => {
        console.log("OPC UA client with PID", worker.process.pid , "died! Restarting!");
        cluster.fork();
    });
}
else {
    console.log("Setting up OPC UA client!");

    var client = new opcua.OPCUAClient(config.ClientParameters);
    var gateway = new OPCUAGateway(
        client,
        config.ServerParameters,
        config.SubscriptionParameters,
        config.MonitoringParameters,
        subscriptions.Subscriptions
    );
    gateway.connect();

    console.log("OPC UA client with PID", process.pid , "started!");
}

//-----------------------
// Lambda event handler:
//-----------------------

exports.handler = (event, context) => {
    console.log('--- TBA ---');
};
