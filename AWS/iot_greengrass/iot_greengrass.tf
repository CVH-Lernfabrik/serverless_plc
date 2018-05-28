# iot_greengrass.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-22

# Initialize and configure the Greengrass Core device as well as the associated
# resources (Greengrass Group, Lambdas, etc.)

# (Re-)Create the GGC device
resource "aws_iot_thing" "iot_ggc_thing" {
    name = "ggc_thing"
    thing_type_name = "edge_device"
}

# (Re-)Create the certificate associated w/ the GGC device

# Private key
resource "tls_private_key" "iot_ggc_cert_key" {
  algorithm   = "RSA"
  ecdsa_curve = "4096"

  provisioner "local-exec" {
      command       = "echo '${tls_private_key.iot_ggc_cert_key.public_key_pem}' > ../AWS_Greengrass/certs/public.pem.key; echo '${tls_private_key.iot_ggc_cert_key.private_key_pem}' > ../AWS_Greengrass/certs/private.pem.key"
      interpreter   = [ "bash", "-c" ]
  }
}

# CSR
resource "tls_cert_request" "iot_ggc_cert_csr" {
  key_algorithm   = "RSA"
  private_key_pem = "${tls_private_key.iot_ggc_cert_key.private_key_pem}"

  subject {
    common_name     = "Serverless PLC GGC"
    organization    = "Bochum University of Applied Science (CVH)"
    street_address  = [ "Kettwiger Str. 20" ]
    locality        = "Heiligenhaus"
    postal_code     = "42579"
    province        = "North Rhine-Westphalia"
    country         = "Germany"
  }
}

# Certificate
resource "aws_iot_certificate" "iot_ggc_cert" {
    csr = "${tls_cert_request.iot_ggc_cert_csr.cert_request_pem}"
    active = true

    provisioner "local-exec" {
        command       = "aws --profile ${var.profile} --region ${var.region} iot describe-certificate --certificate-id $(echo ${aws_iot_certificate.iot_ggc_cert.arn} | sed -e 's#.*/##') | jq -r '.certificateDescription.certificatePem' > ../AWS_Greengrass/certs/certificate.pem.crt"
        interpreter   = [ "bash", "-c" ]
    }
}

# Associate the certificate to the GGC
resource "null_resource" "iot_ggc_cert_associate_cert" {
    triggers {
        ggc_cert_arn    = "aws_iot_certificate.iot_ggc_cert.arn"
    }

    provisioner "local-exec" {
        command       = "aws --profile ${var.profile} --region ${var.region} iot attach-thing-principal --thing-name ${aws_iot_thing.iot_ggc_thing.name} --principal ${aws_iot_certificate.iot_ggc_cert.arn}"
        interpreter   = [ "bash", "-c" ]
    }
}

# Associate the GGC policy to the core's certificate
resource "null_resource" "iot_ggc_cert_associate_policy" {
    triggers {
        ggc_cert_arn    = "aws_iot_certificate.iot_ggc_cert.arn"
        ggc_policy_name = "var.ggc_policy_name"
    }

    provisioner "local-exec" {
        command       = "aws --profile ${var.profile} --region ${var.region} iot attach-policy --target ${aws_iot_certificate.iot_ggc_cert.arn} --policy-name ${var.ggc_policy_name}"
        interpreter   = [ "bash", "-c" ]
    }
}

# Associate the service role w/ the necessary policies to AWS Greengrass
resource "null_resource" "iot_gg_attach_service_role" {
    triggers {
        gg_service_role_arn = "var.gg_service_role_arn"
    }

    provisioner "local-exec" {
        command       = "aws --profile ${var.profile} --region ${var.region} greengrass associate-service-role-to-account --role-arn ${var.gg_service_role_arn}"
        interpreter   = [ "bash", "-c" ]
    }
}

# Initialize and configure the Greengrass Group
# Note: This resource is triggered whenever the ARN of the GGC device changes.
resource "null_resource" "iot_greengrass_group" {
    triggers {
        mps_conveyor_arn    = "aws_iot_thing.iot_ggc.arn"
    }

    provisioner "local-exec" {
        command       = "iot_greengrass/iot_greengrass.sh ${var.profile} ${var.region}"
        interpreter   = [ "bash", "-c" ]
        environment {
            GGC_THING_ARN = "${aws_iot_thing.iot_ggc_thing.arn}"
            GGC_CERT_ARN  = "${aws_iot_certificate.iot_ggc_cert.arn}"
        }
    }
}
