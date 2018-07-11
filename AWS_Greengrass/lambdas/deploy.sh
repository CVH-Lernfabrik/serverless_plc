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

# (Re-)Create the function definition and set up the corresponding subscriptions

# Create / Update the Lambda function definition and store the ARN to be able to
# reference this resource in further operations
GGC_FNC_ID=$(aws --profile ${1} --region ${2} greengrass list-function-definitions | jq -r '.Definitions[] | select(.Name == "opcua-gw-lambda") | .Id')
if [ -z "${GGC_FNC_ID}" ]; then
    GGC_FNC_ID=$(aws --profile ${1} --region ${2} greengrass create-function-definition --name opcua-gw-lambda | jq -r '.Id')
fi
GGC_FNC_ARN=$(aws --profile cvh-lernfabrik --region eu-central-1 greengrass create-function-definition-version --function-definition-id ${GGC_FNC_ID} --functions Id="${GGC_FNC_ID}",FunctionArn="${LAMBDA_ARN}",FunctionConfiguration="{Pinned=true,Executable=index.handler,MemorySize=4096,Timeout=300,EncodingType=json}" | jq -r '.Arn')

# Create / Update the subscription definition(s) and store the Arn(s) to be able
# to reference this (these) resource(s) in further operations
GGC_SUB_ID=$(aws --profile ${1} --region ${2} greengrass list-subscription-definitions | jq -r '.Definitions[] | select(.Name == "opcua-gw-subscription") | .Id')
if [ -z "${GGC_SUB_ID}" ]; then
    GGC_SUB_ID=$(aws --profile ${1} --region ${2} greengrass create-subscription-definition --name opcua-gw-subscription | jq -r '.Id')
fi
GGC_SUB_ARN=$(aws --profile ${1} --region ${2} greengrass create-subscription-definition-version --subscription-definition-id ${GGC_SUB_ID} --subscriptions Id="${GGC_SUB_ID}-1",Source="${LAMBDA_ARN}",Subject="#",Target="GGShadowService" Id="${GGC_SUB_ID}-2",Source="GGShadowService",Subject="#",Target="cloud" | jq -r '.Arn')

# Update the Greengrass group w/ the GGC and logger definitions and store the
# ID to be able to reference this group version in further operations
GGG_VERSION_ID=$(aws --profile ${1} --region ${2} greengrass create-group-version --group-id ${GGG_ID} --core-definition-version-arn ${GGC_DEFINITION_ARN} --logger-definition-version-arn ${GGG_LOGGER_ARN} --function-definition-version-arn ${GGC_FNC_ARN} --subscription-definition-version-arn ${GGC_SUB_ARN} | jq -r '.Version')

##############
# Deployment:
##############

# Deploy the group version to the GGC
aws --profile ${1} --region ${2} greengrass create-deployment --group-id ${GGG_ID} --deployment-type NewDeployment --group-version-id ${GGG_VERSION_ID}
