// main.c
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-04-27
//
// Description: This file implements a simple OPC UA-server based on
//
//     open62541 (cf. https://github.com/open62541/open62541)
//
// that acts as an interface between the MPS (Modular Production System) from
// Festo Didactic and AWS Greengrass. The nodeset is derived from an external
// XML file using the open62541 XML Nodeset Compiler.
// The key feature of this implementation is that the access model is lifted
// to the API level decentralization of the process logic, thus enabling the
// usage of highly modular architecture patterns that are well-suited for modern
// IIot (Industrial Internet of Things) applications.

#include <signal.h>
#include "open62541.h"

//--------------------------
// Definition of functions:
//--------------------------

// Callback-functions:
static void stopHandler(int sig);

// Initialization and configuration:
int main(void);

//----------------------------------------------
// Declaration and initialization of variables:
//----------------------------------------------

UA_Boolean server_running = true;

//---------------------
// Callback-functions:
//---------------------

/**
 * Signalizes the server to stop running
 *
 * @param   sig   signal received
 */
static void stopHandler(int sig)
{
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "stopHandler: Terminating the server!");
    server_running = false;
}

//-----------------------------------
// Initialization and configuration:
//-----------------------------------

/**
 * Program entry point; initializes the OPC-server and loads the nodeset
 *
 * @return  status code
 */
int main(void)
{
    // Attach the stopHandler to SIGINT and SIGTERM so that the OPC-server will
    // be terminated if one of these signals is received (e.g. by pressing ctrl-c)
    signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);

    // Initialize the OPC UA-server
    UA_ServerConfig *config = UA_ServerConfig_new_default();
    UA_Server *server = UA_Server_new(config);

    UA_StatusCode rc;

    // Load the nodeset and create the nodes
    rc = model(server);
    if (rc != UA_STATUSCODE_GOOD) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "main: Failed to load "
                     "the nodeset! Exiting the program!");
        rc = UA_STATUSCODE_BADUNEXPECTEDERROR;
    }
    else {
        // Start the OPC-server as a daemon (background process)
        rc = UA_Server_run(server, &server_running);
        if (rc != US_STATUSCODE_GOOD) {
            UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "main: Failed to " \
                         "start the OPC-server! RC: %x", rc);
        }

        // Free all occupied resources (not needed anymore since the server is
        // running in the background)
        UA_Server_delete(server);
        UA_ServerConfig_delete(config);
    }

    return (int)rc;
}
