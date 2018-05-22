# main.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-15

# Initialize the common meta elements for the IoT service (types, policies, etc.)
module "iot_base" {
    source = "./iot_base"

    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"
}

# Initialize the AWS representation of the individual components of the
# Festo Didactic MPS (Modular Production System)
module "iot_mps" {
    source = "./iot_mps"

    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"

    thing_type_plc_arn      = "${module.iot_base.plc_arn}"
    thing_type_station_arn  = "${module.iot_base.station_arn}"
    thing_type_hmi_arn      = "${module.iot_base.hmi_arn}"
}

# Initialize and configure the Greengrass Core device as well as the associated
# resources (Greengrass Group, Lambdas, etc.)
module "iot_greengrass" {
    source = "./iot_greengrass"

    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"

    ggc_default_policy_arn  = "${module.iot_base.ggc_default_policy_arn}"
}
