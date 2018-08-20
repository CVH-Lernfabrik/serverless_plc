// utility.c
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-05-03
//
// Description: Additional utility functions

#include "util.h"

//-------------------------------
// Additional utility functions:
//-------------------------------

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
        return buffer_PEM;
    }

    UA_StatusCode rc;
    UA_ByteString buffer_DER = UA_STRING_NULL;

    // Initialize the mbedTLS PEM context
    mbedtls_pem_context pem;
    mbedtls_pem_init(&pem);

    // Determine the type of the PEM element and parse it to DER
    if (strstr(certificate.data, "-----BEGIN CERTIFICATE-----") != NULL) {
        // Parse the certificate to DER
        rc = mbedtls_pem_read_buffer(&pem,
                       "-----BEGIN CERTIFICATE-----",
                       "-----END CERTIFICATE-----",
                       buffer_PEM->data, NULL, 0, &buffer_PEM->length);
        if (rc) {
            UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_parsePEMtoDER: " \
                         "Failed to parse the given certificate from PEM to DER " \
                         "format! RC: %x", rc);
        }
    }
    else if (strstr(certificate.data, "-----BEGIN PRIVATE KEY-----") != NULL) {
        // Parse the private key to DER
        rc = mbedtls_pem_read_buffer(&pem,
                       "-----BEGIN PRIVATE KEY-----",
                       "-----END PRIVATE KEY-----",
                       buffer_PEM->data, NULL, 0, &buffer_PEM->length);
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
