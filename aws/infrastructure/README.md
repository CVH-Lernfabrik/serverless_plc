## AWS infrastructure setup

In this project, [Terraform](https://www.terraform.io/) was used for the AWS
infrastructure setup. The configuration was divided by logical entities. This
allows for a flexible specification of the deployment scope, either in form of
a combined deployment to address all resources at once or standalone, if only
individual entities are to be changed.

Module description:
- [iot_base](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/infrastructure/iot_base): Basic setup of IAM policies and device types
- [iot_greengrass](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/infrastructure/iot_greengrass): Creation of the Greengrass Core device, assignment of the corresponding policies and deployment of the initial configuration to the device
- [iot_mps](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/infrastructure/iot_mps): Creation and grouping of the virtual representation of the different MPS submodules

Annotation: As several relatively new services and functions not yet included in
Terraform such as AWS Greengrass were used in this project, the
[official AWS CLI](https://aws.amazon.com/cli/) in the form of custom bash
scripts was used in various places in the setup process.
