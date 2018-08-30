// util.h
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-05-03

#ifndef __UTIL_H__
#define __UTIL_H__

//-----------
// Includes:
//-----------

#include <stdio.h>

#include <mbedtls/x509_crt.h>
#include <mbedtls/pem.h>

#include "open62541.h"

//------------
// Functions:
//------------

extern UA_StatusCode
findChildByBrowsename(UA_Server *server,
                      const UA_NodeId *searchInstance,
                      const UA_QualifiedName *browseName,
                      UA_NodeId *outInstanceNodeId);
extern UA_StatusCode
findSiblingByBrowsename(UA_Server *server,
                      const UA_NodeId *searchInstance,
                      const UA_QualifiedName *browseName,
                      UA_NodeId *outInstanceNodeId);

extern char *String_fromUA_String(UA_String *uastring);
extern UA_NodeId UA_NodeId_fromString(char *string);
extern UA_NodeId UA_NodeId_fromUA_String(UA_String *uastring);

UA_ByteString UA_loadFile(const char *const path);
UA_Boolean UA_isPEM(const UA_ByteString * const buffer);
UA_ByteString UA_parsePEMtoDER(const UA_ByteString * const buffer_PEM);

#endif
