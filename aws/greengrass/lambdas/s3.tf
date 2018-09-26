# s3.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-06-12

# Create a S3 bucket to store and version Lambdas hosted on AWS Greengrass
resource "aws_s3_bucket" "gg_lambda_bucket" {
    bucket = "gg-lambda-bucket"
    acl    = "private"

    tags {
        Name        = "Greengrass Lambda Bucket"
        Description = "Bucket to store and version Lambdas hosted on AWS Greengrass"
    }

    versioning {
        enabled = true
    }

    lifecycle_rule {
        enabled = true

        noncurrent_version_expiration {
            days = 90
        }
    }
}
