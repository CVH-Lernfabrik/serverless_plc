# variables.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-06-12

# File in which the user credentials are stored
variable "shared_credentials_file" {
    default = "/home/$(whoami)/.aws/credentials"
}

# Profile to use in ${shared_credentials_file}
variable "profile" {
    default = "cvh-lernfabrik"
}

# AWS region in which the infrastructure is to be deployed
variable "region" {
    default = "eu-central-1"
}

# Name of the Lambda function
variable "lambda_name" {
    default = "hello_world_template"
}

# Path to the .zip archive of the Lambda
variable "lambda_zip_path" {
    default = "hello_world_template.zip"
}

# Lambda-on-Greengrass role arn
variable "gg_lambda_role_arn" {
    default = ""
}

# S3 bucket to store the Lambdas
variable "gg_lambda_bucket_name" {
    default = ""
}

# Redefinition of depends_on to be able to create inter-module dependencies
# Note: This is a workaround since Terraform currently doesn't support
# depends_on on a module level.
variable "depends_on" {
    default = [],
    type    = "list"
}
