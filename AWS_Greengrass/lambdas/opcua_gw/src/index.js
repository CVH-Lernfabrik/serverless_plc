// index.js
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-08-14
//
// Description: OPC UA gateway functionality and state synchronization w/ AWS
// using the AWS Shadow Engine -- Master process --

'use strict';

//----------------------------------
// Requirements and initialization:
//----------------------------------

require('requirish')._(module);

const child_process = require('child_process');

//--------------
// Definitions:
//--------------

// Variables
let worker;

//----------
// Loggers:
//----------

// Annotation: Even though uppercase for an object may appear like a break w/
// the JS style guide, this notation is retained in analogy to C / C++ macros.
const LOGGER = {};
['log', 'warn', 'error'].forEach( (logLevel) => {
    LOGGER[logLevel.toUpperCase()] = console[logLevel];
});

//------------------------
// Worker initialization:
//------------------------

LOGGER.LOG('Master with PID', process.pid, 'started!');

worker = child_process.fork('worker.js');

worker.on('exit', (code, signal) => {
    LOGGER.ERROR('OPC UA gateway with PID', worker.pid , 'died with RC:', code, '! Restarting!');
    var worker_old  = worker;
    worker          = child_process.fork('worker.js');

    // Inherit the event listeners from the old worker process
    worker_old.eventNames().forEach( (eventName) => {
        if ( eventName != 'internalMessage' ) {
            worker_old.listeners(eventName).forEach( (listener) => {
                worker.on(eventName, listener);
            });
        }
    });
});

worker.on('message', (msg) => {
    if ( !msg.hasOwnProperty('type')
        || !msg.hasOwnProperty('msg')
    ) {
        LOGGER.ERROR('Invalid message received from the worker process!');
        return;
    }

    if ( msg.type == 'log' ) {
        LOGGER.LOG(msg.msg);
    }
    else if ( msg.type == 'warn' ) {
        LOGGER.WARN(msg.msg);
    }
    else if ( msg.type == 'error' ) {
        LOGGER.ERROR(msg.msg);
    }
    else {
        LOGGER.LOG('Invalid message type!');
    }
});

//-----------------------
// Lambda event handler:
//-----------------------

/*
 * Description: Handles events forwarded to the Lambda function by the Greengrass
 *              Core; listenes to Shadow Delta messages and initiates the write
 *              process to set the OPC UA server to the desired state
 *
 * @param {Object} event    - event forwarded to the Lambda function by the GGC
 * @param {Object} context  - context of the event (incl. e.g. subject name)
 */
exports.handler = (event, context) => {
    LOGGER.LOG('Received event:', JSON.stringify(event, null, 2), 'on context:', JSON.stringify(context, null, 2));

    if ( !event.hasOwnProperty('state') ) {
        LOGGER.ERROR('Invalid event passed!');
        context.fail();
    }
    if ( !context.hasOwnProperty('clientContext')
        || !context.clientContext.hasOwnProperty('Custom')
        || !context.clientContext.Custom.hasOwnProperty('subject')
    ) {
        LOGGER.ERROR('Invalid context!');
        context.fail();
    }

    // Extract the thing name and the payload from the event
    const subject   = context.clientContext.Custom.subject;
    const thingName = subject.split('/')[2];
    const payload   = event.state;

    for (var path in payload) {
        var value = payload[path];

        LOGGER.LOG('Setting', thingName + '.' + path, 'to', value + '...');

        // Forward the event to the OPC UA gateway process to initiate the
        // write operation
        worker.send({
            'thingName': thingName,
            'path': path,
            'value': value
        });
    }
    context.succeed();
};
