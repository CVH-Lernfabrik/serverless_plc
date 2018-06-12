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

# Upload the .zip to the Lambda-on-Greengrass S3 bucket
resource "aws_s3_bucket_object" "lambda_zip" {
    bucket = "${var.gg_lambda_bucket_name}"
    key    = "${var.lambda_name}"
    source = "${var.lambda_zip_path}"
    etag   = "${md5(file(${var.lambda_zip_path}))}"
}

# Create / Update the Lambda
resource "aws_lambda_function" "lambda" {
    function_name   = "${var.lambda_name}"
    role            = "${var.gg_lambda_role_arn}"
    handler         = "index.handler"
    runtime         = "nodejs6.10"

    description     = "Periodically publishs a hello-world-message from the GGC to AWS IoT"

    s3_bucket       = "${var.gg_lambda_bucket_name}"
    s3_key          = "${aws_s3_bucket_object.lambda_zip.id}"

    publish         = true
    source_code_hash = "${base64sha256(file(${var.lambda_zip_path}))}"
}

# Create an alias for the Lambda (for later referencing purposes when deploying
# the function to the Greengrass Core)
resource "aws_lambda_alias" "ggc_alias" {
    name             = "GGC"
    description      = "GGC version"
    function_name    = "${aws_lambda_function.lambda.arn}"
    function_version = "$LATEST"
}
