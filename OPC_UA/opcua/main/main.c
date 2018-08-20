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
#include "model.h"

#include "util.h"
#include "user_config.h"

//--------------------------
// Definition of functions:
//--------------------------

// Callback-functions:
static void stopHandler(int sig);

// Initialization and configuration:
static UA_StatusCode createSecurityPolicyBasic256Sha256Endpoint(UA_ServerConfig *const conf,
                                                                UA_Endpoint *endpoint,
                                                                UA_MessageSecurityMode securityMode,
                                                                const UA_ByteString certificate,
                                                                const UA_ByteString privateKey);
static UA_ServerConfig * UA_ServerConfig_Basic256Sha256_custom(UA_UInt16 portNumber,
                                                               const UA_ByteString *certificate,
                                                               const UA_ByteString *privateKey,
                                                               const UA_ByteString *trustList,
                                                               size_t trustListSize,
                                                               const UA_ByteString *revocationList,
                                                               size_t revocationListSize);
int main(int argc, char* argv[]);

//---------
// Macros:
//---------

// Note: Struct initialization works across ANSI C/C99/C++ if it is done when the
// variable is first declared. Assigning values to existing structs is heterogeneous
// across the two.

static UA_INLINE UA_UInt32Range UA_UINT32RANGE(UA_UInt32 min, UA_UInt32 max)
{
    UA_UInt32Range range = {min, max};
    return range;
}

static UA_INLINE UA_DurationRange UA_DURATIONRANGE(UA_Duration min, UA_Duration max)
{
    UA_DurationRange range = {min, max};
    return range;
}

// Neat version formatting
#define STRINGIFY(arg) #arg
#define VERSION(MAJOR, MINOR, PATCH, LABEL) \
        STRINGIFY(MAJOR) "." STRINGIFY(MINOR) "." STRINGIFY(PATCH) LABEL

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
 * Creates a new Basic256Sha256-secured endpoint
 *
 * @param   config          server configuration
 * @param   endpoint        server endpoint (usually config->endpoint)
 * @param   securityMode    UA security mode
 * @param   certificate     server certificate
 * @param   privateKey      server private key
 * @return                  status code
 */
static UA_StatusCode createSecurityPolicyBasic256Sha256Endpoint(UA_ServerConfig *const config,
                                                                UA_Endpoint *endpoint,
                                                                UA_MessageSecurityMode securityMode,
                                                                const UA_ByteString certificate,
                                                                const UA_ByteString privateKey)
{
    if (!config || !endpoint || sizeof(certificate) == 0 || sizeof(privateKey) == 0) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "createSecurityPolicyBasic256Sha256Endpoint: Invalid transfer parameters!");
        return UA_STATUSCODE_BADINTERNALERROR;
    }

    UA_StatusCode rc;

    // Initialize the endpoint description
    UA_EndpointDescription_init(&endpoint->endpointDescription);

    // Create a new Basic256Sha256 security policy and attach it to the endpoint
    rc = UA_SecurityPolicy_Basic256Sha256(&endpoint->securityPolicy,
                                          &config->certificateVerification,
                                          certificate, privateKey,
                                          config->logger);
    if (rc != UA_STATUSCODE_GOOD) {
        endpoint->securityPolicy.deleteMembers(&endpoint->securityPolicy);
        return rc;
    }

    // Set the security mode
    endpoint->endpointDescription.securityMode = securityMode;

    // Set the URIs for the security policy as well as for the transport profile
    endpoint->endpointDescription.securityPolicyUri =
        UA_STRING_ALLOC("http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256");
    endpoint->endpointDescription.transportProfileUri =
        UA_STRING_ALLOC("http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");

    // Enable login mechanisms from the access control plugin
    rc = UA_Array_copy(config->accessControl.userTokenPolicies,
                       config->accessControl.userTokenPoliciesSize,
                       (void **) &endpoint->endpointDescription.userIdentityTokens,
                       &UA_TYPES[UA_TYPES_USERTOKENPOLICY]);
    if (rc != UA_STATUSCODE_GOOD) {
        return rc;
    }
    endpoint->endpointDescription.userIdentityTokensSize =
        config->accessControl.userTokenPoliciesSize;

    // Attach the server certificate to the endpoint
    UA_String_copy(&certificate, &endpoint->endpointDescription.serverCertificate);

    // Copy the application description deposited in the configuration to the
    // endpoint description
    UA_ApplicationDescription_copy(&config->applicationDescription,
                                   &endpoint->endpointDescription.server);

    return UA_STATUSCODE_GOOD;
 }

 /**
  * Creates a new custom OPC UA-server configuration with Basic256Sha256
  * security policy attached
  *
  * @param  portNumber          port number of the OPC UA-server
  * @param  certificate         server certificate
  * @param  privateKey          server private key
  * @param  trustList           list containing all trusted (client) certificates
  * @param  trustListSize       number of entries in the trust list
  * @param  revocationList      list containing all revoked (client) certificates
  * @param  revocationListSize  number of entries in the revocation list
  * @return                     status code
  */
static UA_ServerConfig * UA_ServerConfig_Basic256Sha256_custom(UA_UInt16 portNumber,
                                                               const UA_ByteString *certificate,
                                                               const UA_ByteString *privateKey,
                                                               const UA_ByteString *trustList,
                                                               size_t trustListSize,
                                                               const UA_ByteString *revocationList,
                                                               size_t revocationListSize)
{
    if (!certificate || !privateKey) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "UA_ServerConfig_Basic256Sha256_custom: Invalid transfer parameters!");
        return NULL;
    }

    UA_StatusCode rc;

    // Allocate memory for the server configuration
    UA_ServerConfig *config = (UA_ServerConfig *) UA_malloc(sizeof(UA_ServerConfig));
    if(!config) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_ServerConfig_Basic256Sha256_custom: " \
                     "Error while initializing the server configuration! Aborting!");

        return NULL;
    }

    // Zero out the server configuration to guarantee unambiguous default values
    memset(config, 0, sizeof(UA_ServerConfig));

    /* General configuration */

    // Set the number of threads as well as the default logging output
    config->nThreads = NO_THREADS;
    config->logger = DEFAULT_LOG;

    // Set constructor and destructor functions for the global node lifecycle
    config->nodeLifecycle.constructor = NULL;
    config->nodeLifecycle.destructor = NULL;

    rc = UA_Nodestore_default_new(&config->nodestore);
    if (rc != UA_STATUSCODE_GOOD) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_ServerConfig_Basic256Sha256_custom: " \
                     "Error while initializing the nodestore! Aborting configuration!");

        UA_ServerConfig_delete(config);
        return NULL;
    }

    /* Server description */

    // Build info
    config->buildInfo.productUri = UA_STRING_ALLOC(PRODUCT_URI);
    config->buildInfo.manufacturerName = UA_STRING_ALLOC(MANUFACTURER_NAME);
    config->buildInfo.productName = UA_STRING_ALLOC(PRODUCT_NAME);
    config->buildInfo.softwareVersion =
        UA_STRING_ALLOC(VERSION(UA_OPEN62541_VER_MAJOR, UA_OPEN62541_VER_MINOR,
                                UA_OPEN62541_VER_PATCH, UA_OPEN62541_VER_LABEL));
    config->buildInfo.buildNumber = UA_STRING_ALLOC(__DATE__
                                                      " "
                                                      __TIME__);
    config->buildInfo.buildDate = 0;

    // Application description
    config->applicationDescription.applicationUri = UA_STRING_ALLOC(APPLICATION_URI);
    config->applicationDescription.productUri = UA_STRING_ALLOC(PRODUCT_URI);
    config->applicationDescription.applicationName = UA_LOCALIZEDTEXT_ALLOC("en", APPLICATION_NAME);
    config->applicationDescription.applicationType = UA_APPLICATIONTYPE_SERVER;

    /* Limits */

    // SecureChannels
    config->maxSecureChannels = MAX_SECURE_CHANNELS;
    config->maxSecurityTokenLifetime = MAX_SECURITY_TOKEN_LIFETIME;

    // Sessions
    config->maxSessions = MAX_SESSIONS;
    config->maxSessionTimeout = SESSION_TIMEOUT_THRESHOLD;

    // Subscriptions
    config->publishingIntervalLimits = UA_DURATIONRANGE(PUBLISHING_INTERVAL_LIMITS_MIN, \
                                                        PUBLISHING_INTERVAL_LIMITS_MAX);
    config->lifeTimeCountLimits = UA_UINT32RANGE(LIFETIME_COUNT_LIMITS_MIN, \
                                                 LIFETIME_COUNT_LIMITS_MAX);
    config->keepAliveCountLimits = UA_UINT32RANGE(KEEP_ALIVE_COUNT_LIMITS_MIN, \
                                                  KEEP_ALIVE_COUNT_LIMITS_MAX);
    config->maxNotificationsPerPublish = MAX_NOTIFICATIONS_PER_PUBLISH;
    config->maxRetransmissionQueueSize = MAX_RETRANSMISSION_QUEUE_SIZE;

    // MonitoredItems
    config->samplingIntervalLimits = UA_DURATIONRANGE(SAMPLING_INTERVAL_LIMITS_MIN, \
                                                      SAMPLING_INTERVAL_LIMITS_MAX);
    config->queueSizeLimits = UA_UINT32RANGE(QUEUE_SIZE_LIMITS_MIN, QUEUE_SIZE_LIMITS_MAX);

    /* Security */

    // Initialize the access control plugin
    config->accessControl = UA_AccessControl_default(true, CREDENTIALS_SIZE, \
                                                     loginCredentials);

    // Initalize the trust and revocation list
    // Note: Revocation list currently unsuported in open62541 v1.04
    rc = UA_CertificateVerification_Trustlist(&config->certificateVerification,
                                              trustList, trustListSize,
                                              revocationList, revocationListSize);
    if (rc != UA_STATUSCODE_GOOD) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_ServerConfig_Basic256Sha256_custom: " \
                     "Error while initializing the trust and revocation list! Aborting configuration!");

        UA_ServerConfig_delete(config);
        return NULL;
    }

    if (trustListSize == 0) {
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "No CA trust-list " \
                       "provided. Any remote certificate will be accepted.");
    }

    /* Networking */

    // Initialize the connection configuration
    const UA_ConnectionConfig connection_config = {
        0,
        SEND_BUFFER_SIZE,
        RECV_BUFFER_SIZE,
        MAX_MESSAGE_SIZE,
        MAX_CHUNK_COUNT
    };

    // Add network layer
    config->networkLayers = (UA_ServerNetworkLayer *) UA_malloc( sizeof(UA_ServerNetworkLayer) );
    if (config->networkLayers) {
        *config->networkLayers = UA_ServerNetworkLayerTCP(connection_config, \
                                                          portNumber, config->logger);
        config->networkLayersSize = 1;
    }
    else {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_ServerConfig_Basic256Sha256_custom: " \
                     "Error while adding network layer! Aborting configuration!");

        UA_ServerConfig_delete(config);
        return NULL;
    }

    // Allocate the endpoint
    config->endpointsSize = 1;
    config->endpoints = (UA_Endpoint *) UA_malloc(sizeof(UA_Endpoint));
    if (!config->endpoints) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_ServerConfig_Basic256Sha256_custom: " \
                     "Error while initializing the endpoint! Aborting configuration!");

        UA_ServerConfig_delete(config);
        return NULL;
    }

    // Create a new endpoint with Basic256Sha256 security policy attached
    rc = createSecurityPolicyBasic256Sha256Endpoint(config, config->endpoints,
                                                    UA_MESSAGESECURITYMODE_SIGNANDENCRYPT,
                                                    *certificate, *privateKey);
    if (rc != UA_STATUSCODE_GOOD) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_ServerConfig_Basic256Sha256_custom: " \
                     "Error while creating the Basic256Sha256 endpoint! Aborting configuration!");

        UA_ServerConfig_delete(config);
        return NULL;
    }

    return config;
}

/**
 * Program entry point; initializes the OPC-server and loads the nodeset
 *
 * @return  status code
 */
int main(int argc, char* argv[])
{
    if (argc < 3) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "main: Missing transfer parameters. Arguments are: " \
                     "<certificate.pem.crt> <private.pem.key> " \
                     "[<trustlist1.pem.crt>, ...]");
        return 1;
    }

    // Attach the stopHandler to SIGTERM so that the OPC-server can be terminated
    // by e.g. a kill command
    signal(SIGTERM, stopHandler);

    // Load the server certificate and private key
    UA_ByteString certificate = UA_loadFile(argv[1]);
    UA_ByteString privateKey = UA_loadFile(argv[2]);

    // Parse certificate and private key to DER in case either was given in PEM
    // format
    // Annotation: This is necessary as open62541 does currently (2018-08-18)
    // not parse the server certificate on runtime. This results in a corrupted
    // certificate thumbprint, thus preventing a secure channel between client
    // and server to be established.
    if (UA_isPEM(&certificate)) {
        UA_ByteString * certificate_raw = &certificate;
        certificate = UA_parsePEMtoDER(certificate_raw);
        UA_ByteString_delete(certificate_raw);
    }
    if (UA_isPEM(&privateKey)) {
        UA_ByteString * privateKey_raw = &privateKey;
        privateKey = UA_parsePEMtoDER(&privateKey_raw);
        UA_ByteString_delete(privateKey_raw);
    }

    // Initialize the trust list from the transfer parameters
    size_t trustListSize = 0;
    if (argc > 3) {
        trustListSize = (size_t) argc - 3;
    }
    UA_STACKARRAY(UA_ByteString, trustList, trustListSize);
    for (size_t i = 0; i < trustListSize; i++) {
        trustList[i] = UA_loadPEMFile(argv[i + 3]);
    }

    // Note: Revocation list currently unsuported in open62541 v1.04
    UA_ByteString *revocationList = NULL;
    size_t revocationListSize = 0;

    // Create a new configuration w/ Basic256Sha256 security policy attached
    UA_ServerConfig *config = UA_ServerConfig_Basic256Sha256_custom(4840, \
                                                                    &certificate, &privateKey, \
                                                                    trustList, trustListSize, \
                                                                    revocationList, revocationListSize);
    if (!config) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "main: Error while initializing "
                     "the server configuration! Exiting the program!");
        return 1;
    }

    // Initialize the OPC UA-server
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
        if (rc != UA_STATUSCODE_GOOD) {
            UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "main: Failed to " \
                         "start the OPC-server! RC: %x", rc);
        }
    }

    /* Free all occupied resources */

    UA_Server_delete(server);
    UA_ServerConfig_delete(config);

    UA_ByteString_deleteMembers(&certificate);
    UA_ByteString_deleteMembers(&privateKey);

    for (size_t i = 0; i < trustListSize; i++) {
        UA_ByteString_deleteMembers(&trustList[i]);
    }

    return (int) rc;
}
