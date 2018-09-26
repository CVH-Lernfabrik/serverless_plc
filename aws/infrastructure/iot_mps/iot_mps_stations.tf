# iot_mps_stations.tf
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-21

# Initialize the AWS representation of the individual stations of the
# Festo Didactic MPS (Modular Production System)

# Conveyor

# Create the device
resource "aws_iot_thing" "iot_mps_conveyor" {
    name = "mps_conveyor"
    thing_type_name = "station"
}

# (Re-)Create the certificate associated w/ the device

# Private key
resource "tls_private_key" "iot_mps_conveyor_cert_key" {
  algorithm     = "RSA"
  ecdsa_curve   = "4096"

  provisioner "local-exec" {
      command       = "echo '${tls_private_key.iot_mps_conveyor_cert_key.public_key_pem}' > ../AWS_Greengrass/certs/mps_conveyor/public.pem.key; echo '${tls_private_key.iot_mps_conveyor_cert_key.private_key_pem}' > ../AWS_Greengrass/certs/mps_conveyor/private.pem.key"
      interpreter   = [ "bash", "-c" ]
  }
}

# CSR
resource "tls_cert_request" "iot_mps_conveyor_cert_csr" {
  key_algorithm     = "RSA"
  private_key_pem   = "${tls_private_key.iot_mps_conveyor_cert_key.private_key_pem}"

  subject {
    common_name     = "Serverless PLC MPS Conveyor"
    organization    = "Bochum University of Applied Science (CVH)"
    street_address  = [ "Kettwiger Str. 20" ]
    locality        = "Heiligenhaus"
    postal_code     = "42579"
    province        = "North Rhine-Westphalia"
    country         = "Germany"
  }
}

# Certificate
resource "aws_iot_certificate" "iot_mps_conveyor_cert" {
    csr = "${tls_cert_request.iot_mps_conveyor_cert_csr.cert_request_pem}"
    active = true

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot describe-certificate --certificate-id $(echo ${aws_iot_certificate.iot_mps_conveyor_cert.arn} | sed -e 's#.*/##') | jq -r '.certificateDescription.certificatePem' > ../AWS_Greengrass/certs/mps_conveyor/certificate.pem.crt"
        interpreter = [ "bash", "-c" ]
    }
}

# Associate the certificate to the device
resource "null_resource" "iot_mps_conveyor_cert_associate_cert" {
    triggers {
        ggc_cert_arn    = "aws_iot_certificate.iot_mps_conveyor_cert.arn"
    }

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot attach-thing-principal --thing-name ${aws_iot_thing.iot_mps_conveyor.name} --principal ${aws_iot_certificate.iot_mps_conveyor_cert.arn}"
        interpreter = [ "bash", "-c" ]
    }
}

# Ejector

# Create the device
resource "aws_iot_thing" "iot_mps_ejector" {
    name = "mps_ejector"
    thing_type_name = "station"
}

# (Re-)Create the certificate associated w/ the device

# Private key
resource "tls_private_key" "iot_mps_ejector_cert_key" {
  algorithm     = "RSA"
  ecdsa_curve   = "4096"

  provisioner "local-exec" {
      command       = "echo '${tls_private_key.iot_mps_ejector_cert_key.public_key_pem}' > ../AWS_Greengrass/certs/mps_ejector/public.pem.key; echo '${tls_private_key.iot_mps_ejector_cert_key.private_key_pem}' > ../AWS_Greengrass/certs/mps_ejector/private.pem.key"
      interpreter   = [ "bash", "-c" ]
  }
}

# CSR
resource "tls_cert_request" "iot_mps_ejector_cert_csr" {
  key_algorithm     = "RSA"
  private_key_pem   = "${tls_private_key.iot_mps_ejector_cert_key.private_key_pem}"

  subject {
    common_name     = "Serverless PLC MPS Ejector"
    organization    = "Bochum University of Applied Science (CVH)"
    street_address  = [ "Kettwiger Str. 20" ]
    locality        = "Heiligenhaus"
    postal_code     = "42579"
    province        = "North Rhine-Westphalia"
    country         = "Germany"
  }
}

# Certificate
resource "aws_iot_certificate" "iot_mps_ejector_cert" {
    csr = "${tls_cert_request.iot_mps_ejector_cert_csr.cert_request_pem}"
    active = true

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot describe-certificate --certificate-id $(echo ${aws_iot_certificate.iot_mps_ejector_cert.arn} | sed -e 's#.*/##') | jq -r '.certificateDescription.certificatePem' > ../AWS_Greengrass/certs/mps_ejector/certificate.pem.crt"
        interpreter = [ "bash", "-c" ]
    }
}

# Associate the certificate to the device
resource "null_resource" "iot_mps_ejector_cert_associate_cert" {
    triggers {
        ggc_cert_arn    = "aws_iot_certificate.iot_mps_ejector_cert.arn"
    }

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot attach-thing-principal --thing-name ${aws_iot_thing.iot_mps_ejector.name} --principal ${aws_iot_certificate.iot_mps_ejector_cert.arn}"
        interpreter = [ "bash", "-c" ]
    }
}

# Magazine

# Create the device
resource "aws_iot_thing" "iot_mps_magazine" {
    name = "mps_magazine"
    thing_type_name = "station"
}

# (Re-)Create the certificate associated w/ the device

# Private key
resource "tls_private_key" "iot_mps_magazine_cert_key" {
  algorithm     = "RSA"
  ecdsa_curve   = "4096"

  provisioner "local-exec" {
      command       = "echo '${tls_private_key.iot_mps_magazine_cert_key.public_key_pem}' > ../AWS_Greengrass/certs/mps_magazine/public.pem.key; echo '${tls_private_key.iot_mps_magazine_cert_key.private_key_pem}' > ../AWS_Greengrass/certs/mps_magazine/private.pem.key"
      interpreter   = [ "bash", "-c" ]
  }
}

# CSR
resource "tls_cert_request" "iot_mps_magazine_cert_csr" {
  key_algorithm     = "RSA"
  private_key_pem   = "${tls_private_key.iot_mps_magazine_cert_key.private_key_pem}"

  subject {
    common_name     = "Serverless PLC MPS Magazine"
    organization    = "Bochum University of Applied Science (CVH)"
    street_address  = [ "Kettwiger Str. 20" ]
    locality        = "Heiligenhaus"
    postal_code     = "42579"
    province        = "North Rhine-Westphalia"
    country         = "Germany"
  }
}

# Certificate
resource "aws_iot_certificate" "iot_mps_magazine_cert" {
    csr = "${tls_cert_request.iot_mps_magazine_cert_csr.cert_request_pem}"
    active = true

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot describe-certificate --certificate-id $(echo ${aws_iot_certificate.iot_mps_magazine_cert.arn} | sed -e 's#.*/##') | jq -r '.certificateDescription.certificatePem' > ../AWS_Greengrass/certs/mps_magazine/certificate.pem.crt"
        interpreter = [ "bash", "-c" ]
    }
}

# Associate the certificate to the device
resource "null_resource" "iot_mps_magazine_cert_associate_cert" {
    triggers {
        ggc_cert_arn    = "aws_iot_certificate.iot_mps_magazine_cert.arn"
    }

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot attach-thing-principal --thing-name ${aws_iot_thing.iot_mps_magazine.name} --principal ${aws_iot_certificate.iot_mps_magazine_cert.arn}"
        interpreter = [ "bash", "-c" ]
    }
}

# HMI (Human-Machine Interface)

# Create the device
resource "aws_iot_thing" "iot_mps_hmi" {
    name = "mps_hmi"
    thing_type_name = "hmi"
}

# (Re-)Create the certificate associated w/ the device

# Private key
resource "tls_private_key" "iot_mps_hmi_cert_key" {
  algorithm     = "RSA"
  ecdsa_curve   = "4096"

  provisioner "local-exec" {
      command       = "echo '${tls_private_key.iot_mps_hmi_cert_key.public_key_pem}' > ../AWS_Greengrass/certs/mps_hmi/public.pem.key; echo '${tls_private_key.iot_mps_hmi_cert_key.private_key_pem}' > ../AWS_Greengrass/certs/mps_hmi/private.pem.key"
      interpreter   = [ "bash", "-c" ]
  }
}

# CSR
resource "tls_cert_request" "iot_mps_hmi_cert_csr" {
  key_algorithm     = "RSA"
  private_key_pem   = "${tls_private_key.iot_mps_hmi_cert_key.private_key_pem}"

  subject {
    common_name     = "Serverless PLC MPS HMI"
    organization    = "Bochum University of Applied Science (CVH)"
    street_address  = [ "Kettwiger Str. 20" ]
    locality        = "Heiligenhaus"
    postal_code     = "42579"
    province        = "North Rhine-Westphalia"
    country         = "Germany"
  }
}

# Certificate
resource "aws_iot_certificate" "iot_mps_hmi_cert" {
    csr = "${tls_cert_request.iot_mps_hmi_cert_csr.cert_request_pem}"
    active = true

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot describe-certificate --certificate-id $(echo ${aws_iot_certificate.iot_mps_hmi_cert.arn} | sed -e 's#.*/##') | jq -r '.certificateDescription.certificatePem' > ../AWS_Greengrass/certs/mps_hmi/certificate.pem.crt"
        interpreter = [ "bash", "-c" ]
    }
}

# Associate the certificate to the device
resource "null_resource" "iot_mps_hmi_cert_associate_cert" {
    triggers {
        ggc_cert_arn    = "aws_iot_certificate.iot_mps_hmi_cert.arn"
    }

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot attach-thing-principal --thing-name ${aws_iot_thing.iot_mps_hmi.name} --principal ${aws_iot_certificate.iot_mps_hmi_cert.arn}"
        interpreter = [ "bash", "-c" ]
    }
}

# PLC (Programmable Logic Controller)

# Create the device
resource "aws_iot_thing" "iot_mps_plc" {
    name = "mps_plc"
    thing_type_name = "plc"
    attributes {
        manufacturer = "Kunbus",
        model = "RevPi_Core_3"
    }
}

# (Re-)Create the certificate associated w/ the device

# Private key
resource "tls_private_key" "iot_mps_plc_cert_key" {
  algorithm     = "RSA"
  ecdsa_curve   = "4096"

  provisioner "local-exec" {
      command       = "echo '${tls_private_key.iot_mps_plc_cert_key.public_key_pem}' > ../AWS_Greengrass/certs/mps_plc/public.pem.key; echo '${tls_private_key.iot_mps_plc_cert_key.private_key_pem}' > ../AWS_Greengrass/certs/mps_plc/private.pem.key"
      interpreter   = [ "bash", "-c" ]
  }
}

# CSR
resource "tls_cert_request" "iot_mps_plc_cert_csr" {
  key_algorithm     = "RSA"
  private_key_pem   = "${tls_private_key.iot_mps_plc_cert_key.private_key_pem}"

  subject {
    common_name     = "Serverless PLC MPS PLC"
    organization    = "Bochum University of Applied Science (CVH)"
    street_address  = [ "Kettwiger Str. 20" ]
    locality        = "Heiligenhaus"
    postal_code     = "42579"
    province        = "North Rhine-Westphalia"
    country         = "Germany"
  }
}

# Certificate
resource "aws_iot_certificate" "iot_mps_plc_cert" {
    csr = "${tls_cert_request.iot_mps_plc_cert_csr.cert_request_pem}"
    active = true

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot describe-certificate --certificate-id $(echo ${aws_iot_certificate.iot_mps_plc_cert.arn} | sed -e 's#.*/##') | jq -r '.certificateDescription.certificatePem' > ../AWS_Greengrass/certs/mps_plc/certificate.pem.crt"
        interpreter = [ "bash", "-c" ]
    }
}

# Associate the certificate to the device
resource "null_resource" "iot_mps_plc_cert_associate_cert" {
    triggers {
        ggc_cert_arn    = "aws_iot_certificate.iot_mps_plc_cert.arn"
    }

    provisioner "local-exec" {
        command     = "aws --profile ${var.profile} --region ${var.region} iot attach-thing-principal --thing-name ${aws_iot_thing.iot_mps_plc.name} --principal ${aws_iot_certificate.iot_mps_plc_cert.arn}"
        interpreter = [ "bash", "-c" ]
    }
}

# (Re-)Create the superordinate group that represents the MPS in AWS and add the
# individual modules
# Note: This resource is triggered whenever the ARN of one of the modules changes.
resource "null_resource" "iot_mps_grouping" {
    triggers {
        mps_conveyor_arn    = "aws_iot_thing.iot_mps_conveyor.arn",
        mps_ejector_arn     = "aws_iot_thing.iot_mps_ejector.arn",
        mps_magazine_arn    = "aws_iot_thing.iot_mps_magazine.arn",
        mps_hmi_arn         = "aws_iot_thing.iot_mps_hmi.arn",
        mps_plc_arn         = "aws_iot_thing.iot_mps_plc.arn",
    }

    provisioner "local-exec" {
        command       = "iot_mps/iot_mps_grouping.sh ${var.profile} ${var.region}"
        interpreter   = [ "bash", "-c" ]
    }
}
