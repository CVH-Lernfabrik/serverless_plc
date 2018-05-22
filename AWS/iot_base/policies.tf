# policies.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-15

# Set up a default policy for GGC devices that enables full access to all
# Greengrass services as well as to basic IoT Pub/Sub resp. Shadow functionalites
resource "aws_iot_policy" "ggc_default_policy" {
    name = "ggc_default_policy"
    policy = <<EOF
{
    "Version": "2012-10-17",
    "Statement": [
        {
            "Effect": "Allow",
            "Action": [
                "iot:Publish",
                "iot:Subscribe",
                "iot:Connect",
                "iot:Receive"
            ],
            "Resource": [
                "*"
            ]
        },
        {
            "Effect": "Allow",
            "Action": [
                "iot:GetThingShadow",
                "iot:UpdateThingShadow",
                "iot:DeleteThingShadow"
            ],
            "Resource": [
                "*"
            ]
        },
        {
            "Effect": "Allow",
            "Action": [
                "greengrass:*"
            ],
            "Resource": [
                "*"
            ]
        }
    ]
}
EOF
}
output "ggc_default_policy_arn" {
    value = "${aws_iot_policy.ggc_default_policy.arn}"
}
