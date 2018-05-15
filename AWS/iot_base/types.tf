# policies.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-15

resource "aws_iot_thing_type" "edge_device" {
    name        = "edge_device"
    description = <<EOF
An edge device is a device which is located at the edge of a local enterprise or
service provider core network and acts as a gateway towards the internet. In an
IoT-context, it usually adds a layer of pre-processing to the data before it is
sent into the cloud. An edge device can furthermore serve as a buffer between
the local network and the internet, thus decoupling both sides and allowing each
of them to function independently. Another advantage of edge devices in an
IoT-sense is, that they can drastically lower the (internal) network latency
since the processing happens locally and not in the cloud.
EOF
}

resource "aws_iot_thing_type" "plant" {
    name        = "plant"
    description = <<EOF
A plant (usually as in production plant) is a superordinate unit in a production
resp. value creation process in general.

single task

usually consists of multiple stations that all complete an individual subtask
resp. production step

Usually, a production plant (as well as the subordinate stations) is controlled via one or multiple PLCs (Programmable Logic Controller).
EOF
}

resource "aws_iot_thing_type" "station" {
    name        = "station"
    description = <<EOF
A station is a (modular) part of a superordinate plant.

responsible for a single subtask resp. production step of the overall production
process

smallest logical unit

in an iot context, a station usually consists of multiple sensor and actor devices

Usually, a station is controlled via a PLC (Programmable Logic Controller).
EOF
}

resource "aws_iot_thing_type" "sensor" {
    name                    = "sensor"
    description             = <<EOF
A sensor is a device, module, or subsystem whose purpose is to detect events or
changes in its environment and send the information to other electronics. In an
IoT-context, a sensor is usually connected to a computing unit like e.g. a
microcontroller or a PLC (Programmable Logic Controller). If this CPU's only
purpose is to read out the sensor and to move the thereby generated data to its
designated destination (local or e.g. in the cloud), the whole unit as one can
be referred to as "Sensor Unit".
EOF
    searchable_attributes   = { "type" }
}

resource "aws_iot_thing_type" "actor" {
    name                    = "actor"
    description             = <<EOF
An actor is a device, module, or subsystem whose purpose is to interact with the
real world, possibly controlled by other electronics. In an IoT-context, an
actor is usually connected to a computing unit like e.g. a microcontroller or a
PLC (Programmable Logic Controller). If this CPU's only purpose is to control
the actor and (optionally) communicate the actor's state to its designated
destination (local or e.g. in the cloud), the whole unit as one can be referred
to as "Actor Unit".
EOF
    searchable_attributes   = { "type" }
}
