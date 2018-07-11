# main.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-06-12

# Initialize the AWS provider
provider "aws" {
    version = "~> 1.18"

    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"
}

# Upload the Lambdas to S3 and deploy them to the Greengrass Core

# hello_world_template
module "hello_world_template" {
    source = "./hello_world_template"

    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"

    ggg_role_arn            = "${aws_iam_role.ggg_default_role.arn}"

    gg_lambda_role_arn      = "${aws_iam_role.gg_lambda_default_role.arn}"
    gg_lambda_bucket_name   = "${aws_s3_bucket.gg_lambda_bucket.id}"

    depends_on = [
        "${aws_s3_bucket.gg_lambda_bucket.arn}"
    ]
}

# opcua_gw
module "opcua_gw" {
    source = "./opcua_gw"

    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"

    ggg_role_arn            = "${aws_iam_role.ggg_default_role.arn}"

    gg_lambda_role_arn      = "${aws_iam_role.gg_lambda_default_role.arn}"
    gg_lambda_bucket_name   = "${aws_s3_bucket.gg_lambda_bucket.id}"

    depends_on = [
        "${aws_s3_bucket.gg_lambda_bucket.arn}"
    ]
}
