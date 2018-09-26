# policies.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-15

# Set up a default service role for AWS Greengrass which allows access to
# related services including AWS Lambda and AWS IoT thing shadows
resource "aws_iam_role" "gg_default_service_role" {
    name = "gg_default_service_role"
    assume_role_policy = <<EOF
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Action": "sts:AssumeRole",
      "Principal": {
        "Service": "greengrass.amazonaws.com"
      },
      "Effect": "Allow",
      "Sid": ""
    }
  ]
}
EOF
}
output "gg_default_service_role_arn" {
    value = "${aws_iam_role.gg_default_service_role.arn}"
}

# Attach the necessary (managed) policy to the Greengrass service role
resource "aws_iam_role_policy_attachment" "gg_default_service_role_attach_policy" {
    role       = "${aws_iam_role.gg_default_service_role.name}"
    policy_arn = "arn:aws:iam::aws:policy/service-role/AWSGreengrassResourceAccessRolePolicy"
}

# Set up a default policy for GGC devices that enables full access to all
# Greengrass services as well as to basic IoT Pub/Sub resp. Shadow and CloudWatch
# logging functionalites
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
output "ggc_default_policy_name" {
    value = "${aws_iot_policy.ggc_default_policy.name}"
}
