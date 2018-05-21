# main.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-15

# Initialize the AWS provider
provider "aws" {
    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"
}

# Initialize the common meta elements for the IoT service (types, policies, etc.)
module "iot_base" {
    source = "./iot_base"
}

# Initialize the AWS representation of the individual components of the
# Festo Didactic MPS (Modular Production System)
module "iot_mps" {
    source = "./iot_mps"
}

# Initialize and configure the Greengrass Core device as well as the associated
# resources (Greengrass Group, Lambdas, etc.)
module "iot_greengrass" {
    source = "./iot_greengrass"
}
