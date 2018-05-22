# variables.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-22

# File in which the user credentials are stored
variable "shared_credentials_file" {}

# Profile to use in ${shared_credentials_file}
variable "profile" {}

# AWS region in which the infrastructure is to be deployed
variable "region" {}
