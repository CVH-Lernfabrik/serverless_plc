# main.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-06-12

# Initialize the AWS provider
provider "aws" {
    version = "~> 1.18"

    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"
}

# Load the Null provider to be able to use null_resource for the execution of
# local commands or scripts
provider "null" {
    version = "~> 1.0"
}
