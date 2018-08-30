// utility.c
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-05-03
//
// Description: Additional utility functions

#include <stdbool.h>
#include <string.h>
#include "open62541.h"
#include "util.h"

//-------------------------------
// Additional utility functions:
//-------------------------------


extern char *String_fromUA_String(UA_String *uastring){
  // without malloc the returned string is NULL.
  // with malloc, the memory never gets freed, if not done so externally.
  // Alternatives?
  char *string = (char*)malloc(sizeof(uastring->length + 1));

  for (int i = 0; i < uastring->length; i++)
    string[i] = uastring->data[i];

  string[uastring->length] = NULL;
  return string;
}

extern UA_NodeId UA_NodeId_fromString(char *string){
  // pattern: "ns=1;s=O_1" or "ns=1;i=1001"
  if (!(string[0] == 'n' && string[1] == 's' && string[2] == '='))
    return UA_NODEID_NULL;

  char* substring;
  int namespace = (int)strtol(&string[3], &substring, 10);

  if (!(substring[0] == ';' && substring[2] == '='))
    return UA_NODEID_NULL;

  if (substring[1] == 'i') {
    int nodeId = (int)strtol(&substring[3], NULL, 10);
    return UA_NODEID_NUMERIC(namespace, nodeId);
  }
  else if (substring[1] == 's')
    return UA_NODEID_STRING(namespace, &substring[3]);
  else
    return UA_NODEID_NULL;
}

extern UA_NodeId UA_NodeId_fromUA_String(UA_String *uastring){
  return UA_NodeId_fromString(String_fromUA_String(uastring));
}

extern UA_StatusCode
findChildByBrowsename(UA_Server *server, const UA_NodeId *searchInstance,
                      const UA_QualifiedName *browseName,
                      UA_NodeId *outInstanceNodeId) {
    UA_BrowseDescription bd;
    UA_BrowseDescription_init(&bd);
    bd.nodeId = *searchInstance;
    bd.referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_AGGREGATES);
    bd.includeSubtypes = true;
    bd.browseDirection = UA_BROWSEDIRECTION_FORWARD;
    bd.nodeClassMask = UA_NODECLASS_OBJECT | UA_NODECLASS_VARIABLE | UA_NODECLASS_METHOD;
    bd.resultMask = UA_BROWSERESULTMASK_NODECLASS | UA_BROWSERESULTMASK_BROWSENAME;

    UA_BrowseResult br;
    UA_BrowseResult_init(&br);
    br = UA_Server_browse(server, 5, &bd); // TODO: check if 2nd argument is ok!

    if (br.statusCode != UA_STATUSCODE_GOOD) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "findChildByBrowsename: UA_Server_browse returned StatusCode %s",
                     UA_StatusCode_name(br.statusCode));
        return br.statusCode;
    }

    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    for (size_t i = 0; i < br.referencesSize; ++i) {
        UA_ReferenceDescription *rd = &br.references[i];

        UA_LOG_DEBUG(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                   "findChildByBrowsename: UA_Server_browse result %i of %i: %s (%i:%i)",
                   br.referencesSize, i, String_fromUA_String(&rd->browseName.name),
                   rd->nodeId.nodeId.namespaceIndex, rd->nodeId.nodeId.identifier);

        if(rd->browseName.namespaceIndex == browseName->namespaceIndex &&
           UA_String_equal(&rd->browseName.name, &browseName->name)) {
             retval |= UA_NodeId_copy(&rd->nodeId.nodeId, outInstanceNodeId);
             break;
        }
    }

    UA_BrowseResult_deleteMembers(&br);
    return retval;
}

extern UA_StatusCode
findSiblingByBrowsename(UA_Server *server, const UA_NodeId *searchInstance,
                      const UA_QualifiedName *browseName,
                      UA_NodeId *outInstanceNodeId){

    /* Find the NodeId of the parent */
    UA_NodeId *parentNodeId;
    UA_BrowseDescription bd;
    UA_BrowseDescription_init(&bd);

    bd.nodeId = *searchInstance;
    //bd.referenceTypeId = UA_NODEID_NUMERIC(0, UA_NS0ID_AGGREGATES);
    bd.includeSubtypes = true;
    bd.browseDirection = UA_BROWSEDIRECTION_INVERSE;
    //bd.nodeClassMask = UA_NODECLASS_OBJECT;
    bd.resultMask = UA_BROWSERESULTMASK_BROWSENAME;

    UA_BrowseResult br;
    UA_BrowseResult_init(&br);

    br = UA_Server_browse(server, 1, &bd); // TODO: check if 2nd argument is ok!

    if(br.statusCode != UA_STATUSCODE_GOOD){
      UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                 "findSiblingByBrowsename: UA_Server_browse returned StatusCode %s", UA_StatusCode_name(br.statusCode));
      return br.statusCode;
    }

    UA_ReferenceDescription *rd = &br.references[0];
    parentNodeId = &rd->nodeId.nodeId;
    UA_LOG_DEBUG(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                 "findSiblingByBrowsename: UA_Server_browse result: %s", String_fromUA_String(&rd->browseName.name));

    return findChildByBrowsename(server, parentNodeId, browseName, outInstanceNodeId);
}


/**
 * Loads a given file and returns its contents as UA_ByteString
 *
 * @param   path    path to file to load
 * @return          file content
 */
UA_ByteString UA_loadFile(const char * const path)
{
    if (!path || sizeof(path) == 0) {
        UA_LOG_FATAL(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "UA_loadFile: No file specified! Aborting!");
        return UA_STRING_NULL;
    }

    UA_ByteString fileContents = UA_STRING_NULL;

    // Open the specified file
    FILE *f = fopen(path, "rb");

    if (f) {
        // Get the file length
        fseek(f, 0, SEEK_END);
        fileContents.length = (size_t) ftell(f);

        // Read the content of the file
        fileContents.data = (UA_Byte *) UA_malloc(fileContents.length * sizeof(UA_Byte));
        if(fileContents.data) {
            fseek(f, 0, SEEK_SET);
            size_t read = fread(fileContents.data, sizeof(UA_Byte), fileContents.length, f);
            if(read != fileContents.length) {
                UA_ByteString_deleteMembers(&fileContents);
            }
        }
        else {
            fileContents.length = 0;
        }
        fclose(f);
    }

    return fileContents;
}

/**
 * Checks if a given string buffer contains an element (certificate
 * resp. private key used for asymmetric encryption) in PEM format
 *
 * @param   buffer  string buffer to check
 * @return          indicator if the string contains an element in PEM format
 */
UA_Boolean UA_isPEM(const UA_ByteString * const buffer)
{
    if (!buffer) {
        UA_LOG_FATAL(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "UA_isPEM: No string buffer specified!");
        return UA_FALSE;
    }

    return (strstr((const char *) buffer->data, "-----BEGIN") != NULL
            && strstr((const char *) buffer->data, "-----END") != NULL);
}

/**
 * Parses a given element (certificate resp. private key used for asymmetric
 * encryption) from PEM to DER format
 *
 * @param   buffer_PEM  string buffer containing the PEM element to parse
 * @return              element in DER format
 */
UA_ByteString UA_parsePEMtoDER(const UA_ByteString * const buffer_PEM)
{
    if (!buffer_PEM) {
        UA_LOG_FATAL(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "UA_parsePEMtoDER: No string buffer specified! Aborting!");
        return UA_STRING_NULL;
    }
    if (!UA_isPEM(buffer_PEM)) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "UA_parsePEMtoDER: String buffer does not contain any " \
                     "element in PEM format!");
        return *buffer_PEM;
    }

    UA_StatusCode rc;
    UA_ByteString buffer_DER = UA_STRING_NULL;

    // Initialize the mbedTLS PEM context
    mbedtls_pem_context pem;
    mbedtls_pem_init(&pem);

    // Determine the type of the PEM element and parse it to DER
    if (strstr((const char *) buffer_PEM->data, "-----BEGIN CERTIFICATE-----") != NULL) {
        // Parse the certificate to DER
        rc = mbedtls_pem_read_buffer(&pem,
                       "-----BEGIN CERTIFICATE-----",
                       "-----END CERTIFICATE-----",
                       buffer_PEM->data, NULL, 0, (size_t *) &buffer_PEM->length);
        if (rc) {
            UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_parsePEMtoDER: " \
                         "Failed to parse the given certificate from PEM to DER " \
                         "format! RC: %x", rc);
        }
    }
    else if (strstr((const char *) buffer_PEM->data, "-----BEGIN PRIVATE KEY-----") != NULL) {
        // Parse the private key to DER
        rc = mbedtls_pem_read_buffer(&pem,
                       "-----BEGIN PRIVATE KEY-----",
                       "-----END PRIVATE KEY-----",
                       buffer_PEM->data, NULL, 0, (size_t *) &buffer_PEM->length);
       if (rc) {
           UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_parsePEMtoDER: " \
                        "Failed to parse the given private key from PEM to DER " \
                        "format! RC: %x", rc);
       }
    }
    else {
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_parsePEMtoDER: " \
                       "Given PEM element is neither certificate nor private key! " \
                       "Aborting!");
        rc = UA_STATUSCODE_BADUNEXPECTEDERROR;
    }

    // Copy the parsed element from the mbedTLS PEM context to the DER buffer
    if (!rc) {
        buffer_DER.data = (UA_Byte *) UA_malloc(pem.buflen * sizeof(UA_Byte));
        if (buffer_DER.data) {
            memcpy(buffer_DER.data, pem.buf, pem.buflen);
            buffer_DER.length = pem.buflen;
        }
        else {
            buffer_DER.length = 0;
        }
    }

    // Free the allocated resources
    mbedtls_pem_free(&pem);

    return buffer_DER;
}
