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

# HMI (Human-Machine Interface)
resource "aws_iot_thing" "iot_mps_hmi" {
    name = "mps_hmi"
    thing_type_name = "station"
}

# Magazine
resource "aws_iot_thing" "iot_mps_magazine" {
    name = "mps_magazine"
    thing_type_name = "station"
}

# PLC (Programmable Logic Controller)
resource "aws_iot_thing" "iot_mps_plc" {
    name = "mps_plc"
    thing_type_name = "plc"
    attributes = {
        manufacturer = "Kunbus",
        model = "RevPi Core 3"
    }
}
