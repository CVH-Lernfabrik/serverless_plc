#!/bin/bash

# parse_model.sh
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-03
#
# Description: Bash file to parse a given OPC UA XML model using the open62541
# nodeset compiler

# Path to open62541
OPEN62541_PATH=/usr/local/OPC_UA/open62541

python ${OPEN62541_PATH}/tools/nodeset_compiler/nodeset_compiler.py --types-array=UA_TYPES \
    --existing ${OPEN62541_PATH}/deps/ua-nodeset/Schema/Opc.Ua.NodeSet2.xml \
    --xml model.xml model
