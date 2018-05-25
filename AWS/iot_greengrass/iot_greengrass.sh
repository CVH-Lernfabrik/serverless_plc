#!/bin/bash

# iot_greengrass.sh
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-25

# Initialize and configure the Greengrass Core device as well as the associated
# resources (Greengrass Group, Lambdas, etc.)

# Delete the group if it already exists
GGG_ID=$(aws --profile cvh-lernfabrik --region eu-central-1 greengrass list-groups | jq -r '.Groups[]  | select(.Name == "serverless-plc-group") | .Id')
aws --profile ${1} --region ${2} greengrass delete-group --group-id ${GGG_ID}

# (Re-)Create the Greengrass Group and store the ID to be able to reference this
# group in further operations
GGG_ID=$(aws --profile ${1} --region ${2} greengrass create-group --name serverless-plc-group | jq -r ".Id")

# (Re-)Create the GGC description


# Attach the necessary policies to the Greengrass Group
