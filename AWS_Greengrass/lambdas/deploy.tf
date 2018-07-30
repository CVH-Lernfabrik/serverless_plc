# deploy.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-07-30

# Upload the Lambdas to S3 and deploy them to the Greengrass Core

# hello_world_template
module "hello_world_template" {
    source = "./hello_world_template"

    shared_credentials_file = "${var.shared_credentials_file}"
    profile                 = "${var.profile}"
    region                  = "${var.region}"

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

    gg_lambda_role_arn      = "${aws_iam_role.gg_lambda_default_role.arn}"
    gg_lambda_bucket_name   = "${aws_s3_bucket.gg_lambda_bucket.id}"

    depends_on = [
        "${aws_s3_bucket.gg_lambda_bucket.arn}"
    ]
}

# Deploy the Lambda to the GGC and set up the corresponding subscriptions
# Note: This resource is triggered whenever the ARN of the Lambda changes.
resource "null_resource" "ggc_lambda_deployment" {
    triggers {
        lambda_arn  = "${module.opcua_gw.lambda_qualified_arn}"
    }

    provisioner "local-exec" {
        command     = "./deploy.sh ${var.profile} ${var.region}"
        interpreter = [ "bash", "-c" ]
        environment {
            GGG_ROLE_ARN    = "${aws_iam_role.ggg_default_role.arn}"

            LAMBDA_ARN      = "${module.opcua_gw.lambda_qualified_arn}"
        }
    }
}
