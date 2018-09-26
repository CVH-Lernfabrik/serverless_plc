# lambda.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-06-20

# Upload the Lambda function to AWS

# Upload the .zip to the Lambda-on-Greengrass S3 bucket
resource "aws_s3_bucket_object" "lambda_zip" {
    bucket = "${var.gg_lambda_bucket_name}"
    key    = "${var.lambda_name}"
    source = "${var.lambda_zip_path}"
    etag   = "${md5(file("${var.lambda_zip_path}"))}"
}

# Create / Update the Lambda
resource "aws_lambda_function" "lambda" {
    function_name       = "${var.lambda_name}"
    role                = "${var.gg_lambda_role_arn}"
    handler             = "index.handler"
    runtime             = "nodejs6.10"

    description         = "OPC UA gateway functionality and state synchronization w/ AWS using the AWS Shadow Engine"

    s3_bucket           = "${var.gg_lambda_bucket_name}"
    s3_key              = "${aws_s3_bucket_object.lambda_zip.id}"

    publish             = true
    source_code_hash    = "${base64sha256(file("${var.lambda_zip_path}"))}"
}
output "lambda_qualified_arn" {
    value = "${aws_lambda_function.lambda.qualified_arn}"
}
