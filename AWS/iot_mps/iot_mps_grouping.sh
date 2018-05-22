#!/bin/bash

# iot_mps_grouping.sh
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-22

# (Re-)Create the superordinate group that represents the MPS in AWS and add the
# individual modules

# Delete the group if it already exists
aws --profile ${1} --region ${2} iot delete-thing-group --thing-group-name Festo_MPS

# (Re-)Create the group
aws --profile ${1} --region ${2} iot create-thing-group --thing-group-name Festo_MPS --thing-group-properties thingGroupDescription="The MPS (Modular Production System) is a cyber-physical system (CPS) designed for educational purposes by Festo Didactic. By default\, the plant consists of a simple HMI and a conveyor. The model can be extended by different logically interlinkable stations\, that each serve one specific subtask\, thus allowing for it to be adjusted to the individual use case.",attributePayload={attributes={"manufacturer"="Festo_Didactic"}}

# Add the individual modules to the group
aws --profile ${1} --region ${2} iot add-thing-to-thing-group --thing-group-name Festo_MPS --thing-name mps_conveyor
aws --profile ${1} --region ${2} iot add-thing-to-thing-group --thing-group-name Festo_MPS --thing-name mps_ejector
aws --profile ${1} --region ${2} iot add-thing-to-thing-group --thing-group-name Festo_MPS --thing-name mps_magazine
aws --profile ${1} --region ${2} iot add-thing-to-thing-group --thing-group-name Festo_MPS --thing-name mps_hmi
aws --profile ${1} --region ${2} iot add-thing-to-thing-group --thing-group-name Festo_MPS --thing-name mps_plc
