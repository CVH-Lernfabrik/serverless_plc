# policies.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-06-12

# Set up a default role for the Greengrass Group which allows access to related
# services including AWS Cloudwatch
resource "aws_iam_role" "ggg_default_role" {
    name = "ggg_default_role"
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

# Attach the necessary (managed) policies to the Greengrass Group role

# CloudWatchFullAccess
resource "aws_iam_role_policy_attachment" "ggg_default_role_attach_policy_CloudWatchFullAccess" {
    role       = "${aws_iam_role.ggg_default_role.name}"
    policy_arn = "arn:aws:iam::aws:policy/CloudWatchFullAccess"
}

# Set up a default role for Lambdas hosted on AWS Greengrass which allows access
# to related services including AWS IoT and AWS Cloudwatch
resource "aws_iam_role" "gg_lambda_default_role" {
    name = "gg_lambda_default_role"
    assume_role_policy = <<EOF
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Action": "sts:AssumeRole",
      "Principal": {
        "Service": "lambda.amazonaws.com"
      },
      "Effect": "Allow",
      "Sid": ""
    }
  ]
}
EOF
}

# Attach the necessary (managed) policies to the Lambda-on-Greengrass role

# LambdaBasicExecutionRole
resource "aws_iam_role_policy_attachment" "gg_lambda_default_role_attach_policy_LambdaBasicExecutionRole" {
    role       = "${aws_iam_role.gg_lambda_default_role.name}"
    policy_arn = "arn:aws:iam::aws:policy/service-role/AWSLambdaBasicExecutionRole"
}

# GreengrassFullAccess
resource "aws_iam_role_policy_attachment" "gg_lambda_default_role_attach_policy_GreengrassFullAccess" {
    role       = "${aws_iam_role.gg_lambda_default_role.name}"
    policy_arn = "arn:aws:iam::aws:policy/AWSGreengrassFullAccess"
}

# IoTDataAccess
resource "aws_iam_role_policy_attachment" "gg_lambda_default_role_attach_policy_IoTDataAccess" {
    role       = "${aws_iam_role.gg_lambda_default_role.name}"
    policy_arn = "arn:aws:iam::aws:policy/AWSIoTDataAccess"
}
