#!/bin/bash

# deploy.sh
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-06-20

# Deploy the Lambda to the GGC and set up the corresponding subscriptions

#######################
# Reference resolving:
#######################

# Obtain the IDs / ARNs of the various resources associated to the GGG for
# later referencing

# Group
GGG_ID=$(aws --profile ${1} --region ${2} greengrass list-groups | jq -r '.Groups[]  | select(.Name == "serverless-plc-group") | .Id')

# GGC definition
GGC_DEFINITION_ARN=$(aws --profile ${1} --region ${2} greengrass list-core-definitions | jq -r '.Definitions[] | select(.Name == "serverless-plc-ggc-definition") | .LatestVersionArn')

# Logger defintion
GGG_LOGGER_ARN=$(aws --profile ${1} --region ${2} greengrass list-logger-definitions | jq -r '.Definitions[] | select(.Name == "serverless-plc-logger-definition") | .LatestVersionArn')

# GGG devices

# mps_conveyor
MPS_CONVEYOR_ARN=$(aws --profile ${1} --region ${2} iot list-things | jq -r '.things[] | select(.thingName == "mps_conveyor") | .thingArn')
MPS_CONVEYOR_CERT_ARN=$(aws --profile ${1} --region ${2} iot list-thing-principals --thing-name mps_conveyor | jq -r ".principals[]")

# mps_ejector
MPS_EJECTOR_ARN=$(aws --profile ${1} --region ${2} iot list-things | jq -r '.things[] | select(.thingName == "mps_ejector") | .thingArn')
MPS_EJECTOR_CERT_ARN=$(aws --profile ${1} --region ${2} iot list-thing-principals --thing-name mps_ejector | jq -r ".principals[]")

# mps_hmi
MPS_HMI_ARN=$(aws --profile ${1} --region ${2} iot list-things | jq -r '.things[] | select(.thingName == "mps_hmi") | .thingArn')
MPS_HMI_CERT_ARN=$(aws --profile ${1} --region ${2} iot list-thing-principals --thing-name mps_hmi | jq -r ".principals[]")

# mps_magazine
MPS_MAGAZINE_ARN=$(aws --profile ${1} --region ${2} iot list-things | jq -r '.things[] | select(.thingName == "mps_magazine") | .thingArn')
MPS_MAGAZINE_CERT_ARN=$(aws --profile ${1} --region ${2} iot list-thing-principals --thing-name mps_magazine | jq -r ".principals[]")

# mps_plc
MPS_PLC_ARN=$(aws --profile ${1} --region ${2} iot list-things | jq -r '.things[] | select(.thingName == "mps_plc") | .thingArn')
MPS_PLC_CERT_ARN=$(aws --profile ${1} --region ${2} iot list-thing-principals --thing-name mps_plc | jq -r ".principals[]")

############
# Deletion:
############

# Disassociate the IAM role currenctly attached to the Greengrass Group
aws --profile ${1} --region ${2} greengrass disassociate-role-from-group --group-id ${GGG_ID} 2> /dev/null

#################
# (Re-)Creation:
#################

# Attach the (new) IAM role to the Greengrass Group
aws --profile ${1} --region ${2} greengrass associate-role-to-group --group-id ${GGG_ID} --role-arn ${GGG_ROLE_ARN}

# (Re-)Create the function definition, set up the corresponding subscriptions
# and add the associated devices to the Greengrass Group

# Create / Update the Lambda function definition and store the ARN to be able to
# reference this resource in further operations
GGC_FNC_ID=$(aws --profile ${1} --region ${2} greengrass list-function-definitions | jq -r '.Definitions[] | select(.Name == "opcua-gw-lambda") | .Id')
if [ -z "${GGC_FNC_ID}" ]; then
    GGC_FNC_ID=$(aws --profile ${1} --region ${2} greengrass create-function-definition --name opcua-gw-lambda | jq -r '.Id')
fi
GGC_FNC_ARN=$(aws --profile ${1} --region ${2} greengrass create-function-definition-version --function-definition-id ${GGC_FNC_ID} --functions Id="${GGC_FNC_ID}-1",FunctionArn="${OPCUA_GW_ARN}",FunctionConfiguration="{Pinned=true,Executable=index.handler,MemorySize=65536,Timeout=300,EncodingType=json}" | jq -r '.Arn')

# Create / Update the subscription definition(s) and store the Arn(s) to be able
# to reference this (these) resource(s) in further operations
GGC_SUB_ID=$(aws --profile ${1} --region ${2} greengrass list-subscription-definitions | jq -r '.Definitions[] | select(.Name == "opcua-gw-subscription") | .Id')
if [ -z "${GGC_SUB_ID}" ]; then
    GGC_SUB_ID=$(aws --profile ${1} --region ${2} greengrass create-subscription-definition --name opcua-gw-subscription | jq -r '.Id')
fi
GGC_SUB_ARN=$(aws --profile ${1} --region ${2} greengrass create-subscription-definition-version --subscription-definition-id ${GGC_SUB_ID} --subscriptions Id="${GGC_SUB_ID}-1",Source="GGShadowService",Subject="$aws/things/+/shadow/update/delta",Target="${OPCUA_GW_ARN}" | jq -r '.Arn')

# Create / Update the device definition(s) and store the Arn(s) to be able
# to reference this (these) resource(s) in further operations
GGC_DEV_ID=$(aws --profile ${1} --region ${2} greengrass list-device-definitions | jq -r '.Definitions[] | select(.Name == "opcua-gw-device") | .Id')
if [ -z "${GGC_DEV_ID}" ]; then
    GGC_DEV_ID=$(aws --profile ${1} --region ${2} greengrass create-device-definition --name opcua-gw-device | jq -r '.Id')
fi
GGC_DEV_ARN=$(aws --profile ${1} --region ${2} greengrass create-device-definition-version --device-definition-id ${GGC_DEV_ID} --devices CertificateArn="${MPS_CONVEYOR_CERT_ARN}",Id="${GGC_DEV_ID}-1",SyncShadow=true,ThingArn="${MPS_CONVEYOR_ARN}" CertificateArn="${MPS_EJECTOR_CERT_ARN}",Id="${GGC_DEV_ID}-2",SyncShadow=true,ThingArn="${MPS_EJECTOR_ARN}" CertificateArn="${MPS_HMI_CERT_ARN}",Id="${GGC_DEV_ID}-3",SyncShadow=true,ThingArn="${MPS_HMI_ARN}" CertificateArn="${MPS_MAGAZINE_CERT_ARN}",Id="${GGC_DEV_ID}-4",SyncShadow=true,ThingArn="${MPS_MAGAZINE_ARN}" CertificateArn="${MPS_PLC_CERT_ARN}",Id="${GGC_DEV_ID}-5",SyncShadow=true,ThingArn="${MPS_PLC_ARN}" | jq -r '.Arn')

# Update the Greengrass group w/ the GGC and logger definitions and store the
# ID to be able to reference this group version in further operations
GGG_VERSION_ID=$(aws --profile ${1} --region ${2} greengrass create-group-version --group-id ${GGG_ID} --core-definition-version-arn ${GGC_DEFINITION_ARN} --logger-definition-version-arn ${GGG_LOGGER_ARN} --function-definition-version-arn ${GGC_FNC_ARN} --subscription-definition-version-arn ${GGC_SUB_ARN} --device-definition-version-arn ${GGC_DEV_ARN} | jq -r '.Version')

##############
# Deployment:
##############

# Deploy the group version to the GGC
aws --profile ${1} --region ${2} greengrass create-deployment --group-id ${GGG_ID} --deployment-type NewDeployment --group-version-id ${GGG_VERSION_ID}
