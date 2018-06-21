#!/bin/bash

# iot_greengrass.sh
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-25

# Initialize and configure the Greengrass Core device as well as the associated
# resources (Greengrass Group, Lambdas, etc.)


############
# Deletion:
############

# Delete the Greengrass Group as well as all associated resources if it already exists

# Group
GGG_ID=$(aws --profile ${1} --region ${2} greengrass list-groups | jq -r '.Groups[] | select(.Name == "serverless-plc-group") | .Id')
aws --profile ${1} --region ${2} greengrass delete-group --group-id ${GGG_ID}

# GGC definition
GGC_DEFINITION_ID=$(aws --profile ${1} --region ${2} greengrass list-core-definitions | jq -r '.Definitions[] | select(.Name == "serverless-plc-ggc-definition") | .Id')
aws --profile ${1} --region ${2} greengrass delete-core-definition --core-definition-id ${GGC_DEFINITION_ID}

# Logger defintion
GGG_LOGGER_ID=$(aws --profile ${1} --region ${2} greengrass list-logger-definitions | jq -r '.Definitions[] | select(.Name == "serverless-plc-logger-definition") | .Id')
aws --profile ${1} --region ${2} greengrass delete-logger-definition --logger-definition-id ${GGG_LOGGER_ID}

#################
# (Re-)Creation:
#################

# (Re-)Create the Greengrass Group as well as all asscociated resources

# Create the Greengrass Group and store the ID to be able to reference this
# group in further operations
GGG_ID=$(aws --profile ${1} --region ${2} greengrass create-group --name serverless-plc-group | jq -r ".Id")

# Create the GGC definition and store the Arn to be able to reference this
# resource in further operations
GGC_DEFINITION_ARN=$(aws --profile ${1} --region ${2} greengrass create-core-definition --name serverless-plc-ggc-definition --initial-version Cores="[{CertificateArn=${GGC_CERT_ARN},Id=${GGG_ID},SyncShadow=true,ThingArn=${GGC_THING_ARN}}]" | jq -r '.LatestVersionArn')

# Create the logger definition and store the Arn to be able to reference this
# resource in further operations
GGG_LOGGER_ARN=$(aws --profile ${1} --region ${2} greengrass create-logger-definition --name serverless-plc-logger-definition --initial-version Loggers="[{Component=GreengrassSystem,Id=${GGG_ID}-1,Level=DEBUG,Space=4096,Type=FileSystem},{Component=GreengrassSystem,Id=${GGG_ID}-2,Level=INFO,Type=AWSCloudWatch},{Component=Lambda,Id=${GGG_ID}-3,Level=DEBUG,Space=4096,Type=FileSystem},{Component=Lambda,Id=${GGG_ID}-4,Level=INFO,Type=AWSCloudWatch}]" | jq -r '.LatestVersionArn')

# Update the Greengrass group w/ the GGC and logger definitions and store the
# ID to be able to reference this group version in further operations
GGG_VERSION_ID=$(aws --profile ${1} --region ${2} greengrass create-group-version --group-id ${GGG_ID} --core-definition-version-arn ${GGC_DEFINITION_ARN} --logger-definition-version-arn ${GGG_LOGGER_ARN} | jq -r '.Version')

##############
# Deployment:
##############

# Deploy the group version to the GGC
aws --profile ${1} --region ${2} greengrass create-deployment --group-id ${GGG_ID} --deployment-type NewDeployment --group-version-id ${GGG_VERSION_ID}
