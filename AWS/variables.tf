# variables.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-15

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
