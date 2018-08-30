// user_config.h
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-04-27

#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

//-----------
// Includes:
//-----------

#include "open62541.h"

//--------------------
// Login credentials:
//--------------------

    // To enable login via credentials, uncomment the following line
    // Attention: It is generally advised AGAINST doing so besides for testing
    // purposes as OPC UA does not support simultaneous credentials based
    // authentication and message encryption. The default Basic256Sha256
    // endpoint will stay active in parallel.
    #define INSECURE_MODE

    #define CREDENTIALS_SIZE                2

    #define UA_LOGLEVEL = 200

    // Set the login credentials clients can use to access the server
    // Note: Only the first CREDENTIALS_SIZE entries will be valid. Every further
    // username / password combination will be ignored.
    UA_UsernamePasswordLogin loginCredentials[CREDENTIALS_SIZE] = {
        {UA_STRING_STATIC("clemens"), UA_STRING_STATIC("falkenhain")},
        {UA_STRING_STATIC("jan"), UA_STRING_STATIC("faller")}
    };

//------------------------
// General configuration:
//------------------------

    // Number of threads the OPC UA-server will be using
    #define NO_THREADS                      1

    // Default logging output
    #define DEFAULT_LOG                     UA_Log_Stdout

//---------------------
// Server description:
//---------------------

    // Meta-level description of the OPC UA-server
    #define MANUFACTURER_NAME               "CVH-Lernfabrik"
    #define PRODUCT_NAME                    "Serverless PLC OPC UA-server"
    #define PRODUCT_URI                     "https://cvh-lernfabrik.github.io"
    #define APPLICATION_NAME                "open62541-based OPC UA-server"
    #define APPLICATION_URI                 "https://cvh-lernfabrik.github.io/UA/"

//---------
// Limits:
//---------

    // Secure channels
    #define MAX_SECURE_CHANNELS             40
    #define MAX_SECURITY_TOKEN_LIFETIME     10 * 60 * 1000

    // Sessions
    #define MAX_SESSIONS                    100
    #define SESSION_TIMEOUT_THRESHOLD       60.0 * 60.0 * 1000.0

    // Subscriptions
    #define PUBLISHING_INTERVAL_LIMITS_MIN  100.0
    #define PUBLISHING_INTERVAL_LIMITS_MAX  60.0 * 60.0 * 1000.0
    #define LIFETIME_COUNT_LIMITS_MIN       3
    #define LIFETIME_COUNT_LIMITS_MAX       15000
    #define KEEP_ALIVE_COUNT_LIMITS_MIN     1
    #define KEEP_ALIVE_COUNT_LIMITS_MAX     100
    #define MAX_NOTIFICATIONS_PER_PUBLISH   1000
    #define MAX_RETRANSMISSION_QUEUE_SIZE   0

    // MonitoredItems
    #define SAMPLING_INTERVAL_LIMITS_MIN    60.0
    #define SAMPLING_INTERVAL_LIMITS_MAX    60.0 * 60.0 * 24.0 * 1000.0
    #define QUEUE_SIZE_LIMITS_MIN           1
    #define QUEUE_SIZE_LIMITS_MAX           100

    // Network:
    #define SEND_BUFFER_SIZE                65535
    #define RECV_BUFFER_SIZE                65535
    #define MAX_MESSAGE_SIZE                0
    #define MAX_CHUNK_COUNT                 0

#endif
