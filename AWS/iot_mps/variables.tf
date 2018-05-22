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

# Varbiables used to establish dependencies between the different modules
# Note: This is a workaround since Terraform currently doesn't support
# depends_on on a module level.
variable "thing_type_plc_arn" {}
variable "thing_type_station_arn" {}
variable "thing_type_hmi_arn" {}
