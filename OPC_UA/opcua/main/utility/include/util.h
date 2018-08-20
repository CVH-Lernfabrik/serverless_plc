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

#include "open62541.h"

//------------
// Functions:
//------------

UA_ByteString UA_loadPEMFile(const char *const path);
UA_Boolean UA_isPEM(const UA_ByteString * const buffer);
UA_ByteString UA_parsePEMtoDER(const UA_ByteString * const buffer_PEM);

#endif
