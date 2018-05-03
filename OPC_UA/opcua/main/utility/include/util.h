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

#include "open62541.h"

//------------
// Functions:
//------------

UA_ByteString UA_loadFile(const char *const path);

#endif
