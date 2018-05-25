# iot_mps_stations.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-21

# Initialize the AWS representation of the individual stations of the
# Festo Didactic MPS (Modular Production System)

# Conveyor
resource "aws_iot_thing" "iot_mps_conveyor" {
    name = "mps_conveyor"
    thing_type_name = "station"
}

# Ejector
resource "aws_iot_thing" "iot_mps_ejector" {
    name = "mps_ejector"
    thing_type_name = "station"
}

# Magazine
resource "aws_iot_thing" "iot_mps_magazine" {
    name = "mps_magazine"
    thing_type_name = "station"
}

# HMI (Human-Machine Interface)
resource "aws_iot_thing" "iot_mps_hmi" {
    name = "mps_hmi"
    thing_type_name = "hmi"
}

# PLC (Programmable Logic Controller)
resource "aws_iot_thing" "iot_mps_plc" {
    name = "mps_plc"
    thing_type_name = "plc"
    attributes {
        manufacturer = "Kunbus",
        model = "RevPi_Core_3"
    }
}

# (Re-)Create the superordinate group that represents the MPS in AWS and add the
# individual modules
# Note: This resource is triggered whenever the ARN of one of the modules changes.
resource "null_resource" "iot_mps_grouping" {
    triggers {
        mps_conveyor_arn    = "aws_iot_thing.iot_mps_conveyor.arn",
        mps_ejector_arn     = "aws_iot_thing.iot_mps_ejector.arn",
        mps_magazine_arn    = "aws_iot_thing.iot_mps_magazine.arn",
        mps_hmi_arn         = "aws_iot_thing.iot_mps_hmi.arn",
        mps_plc_arn         = "aws_iot_thing.iot_mps_plc.arn",
    }

    provisioner "local-exec" {
        command       = "iot_mps/iot_mps_grouping.sh ${var.profile} ${var.region}"
        interpreter   = [ "bash", "-c" ]
    }
}
