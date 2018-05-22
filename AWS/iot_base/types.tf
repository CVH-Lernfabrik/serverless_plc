# policies.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-15

# Set up the type descriptions for the different categories of IoT devices that
# are relevant for this application

resource "aws_iot_thing_type" "edge_device" {
    name        = "edge_device"
    properties  = {
        description =
            "An edge device is a device which is located at the edge of a local enterprise or service provider core network and acts as a gateway towards the internet. In an IoT-context, it usually adds a layer of pre-processing to the data before it is sent into the cloud. An edge device can furthermore serve as a buffer between the local network and the internet, thus decoupling both sides and allowing each of them to function independently. Another advantage of edge devices in an IoT-sense is, that they can drastically lower the (internal) network latency since the processing happens locally and not in the cloud."
    }
}
output "edge_device_arn" {
    value = "${aws_iot_thing_type.edge_device.arn}"
}

resource "aws_iot_thing_type" "plc" {
    name        = "plc"
    properties  = {
        description =
            "A PLC (Programmable Logic Controller) is a digital computer for industrial use which has been ruggedized and adapted for the control of manufacturing processes, such as assembly lines, or robotic devices, or any activity that requires high reliability control and ease of programming and process fault diagnosis. Usually, the superordinate process logic of a production plant is divided and distributed among multiple logically interlinked (e.g. by the means of standards like OPC UA) PLCs with each controlling an individual station or subtask. A PLC is designed and optimized for tasks with (hard) real-time requirements down to low millisecond range, thus distinguishing it from the common personal computer. The programming is usually done in the form of e.g. \"Ladder Diagrams\", \"Functional Block Diagrams\" or \"Structural Text\" as described in IEC 61131-3, with recent developments additionally enabling the support of classical programming languages like C, C++ or JavaScript."
        searchable_attributes = [ "manufacturer", "model" ]
    }
}
output "plc_arn" {
    value = "${aws_iot_thing_type.plc.arn}"
}

resource "aws_iot_thing_type" "plant" {
    name        = "plant"
    properties  = {
        description =
            "A plant (as in production plant) is a high-level unit in a production process in general. Usually, one plant takes over exactly one task of the superordinate value creation process (e.g. bottling). It typically consists of multiple (modularly) interliked stations, which, in turn, each complete an individual subtask. Normally, a production plant (as well as the subordinate stations) is controlled via one or multiple PLCs (Programmable Logic Controller)."
    }
}
output "plant_arn" {
    value = "${aws_iot_thing_type.plant.arn}"
}

resource "aws_iot_thing_type" "station" {
    name        = "station"
    properties  = {
        description =
            "A station is a (modular) part of a superordinate plant that is responsible for a single subtask resp. production step of the overall production process. It represents the smallest logic unit in which the process can be broken down. In an IoT context, a station can usually be interpreted as a logical pooling of multiple sensor and actor devices that are required to solve a specific task. Usually, a station is controlled via a PLC (Programmable Logic Controller)."
    }
}
output "station_arn" {
    value = "${aws_iot_thing_type.station.arn}"
}

resource "aws_iot_thing_type" "hmi" {
    name        = "hmi"
    properties  = {
        description =
            "The HMI (Human-Machine Interface) serves as a space where human-machine interactions can take place. Customized and individually prepared information for the specific use case is displayed to an operator who can then again use this knowledge to take appropriate situational measures. The other way round, the HMI serves the operator as a control interface for the respective device / machine / plant, e.g. to switch between work orders. HMIs can come either in physical or virtual form, ranging from simple buttons and status LEDs over SCADA plugins to fully digitized, web-based control centers."
    }
}
output "hmi_arn" {
    value = "${aws_iot_thing_type.hmi.arn}"
}

resource "aws_iot_thing_type" "sensor" {
    name        = "sensor"
    properties  = {
        description =
            "A sensor is a device, module, or subsystem whose purpose is to detect events or changes in its environment and send the information to other electronics. In an IoT-context, a sensor is usually connected to a computing unit like e.g. a microcontroller or a PLC (Programmable Logic Controller). If this CPU's only purpose is to read out the sensor and to move the thereby generated data to its designated destination (local or e.g. in the cloud), the whole unit as one can be referred to as \"Sensor Unit\"."
        searchable_attributes = [ "manufacturer", "model", "type" ]
    }
}
output "sensor_arn" {
    value = "${aws_iot_thing_type.sensor.arn}"
}

resource "aws_iot_thing_type" "actor" {
    name        = "actor"
    properties  = {
        description =
            "An actor is a device, module, or subsystem whose purpose is to interact with the real world, possibly controlled by other electronics. In an IoT-context, an actor is usually connected to a computing unit like e.g. a microcontroller or a PLC (Programmable Logic Controller). If this CPU's only purpose is to control the actor and (optionally) communicate the actor's state to its designated destination (local or e.g. in the cloud), the whole unit as one can be referred to as \"Actor Unit\"."
        searchable_attributes = [ "manufacturer", "model", "type" ]
    }
}
output "actor_arn" {
    value = "${aws_iot_thing_type.actor.arn}"
}
