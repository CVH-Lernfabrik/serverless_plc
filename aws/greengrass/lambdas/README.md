## Deployment of Lambda functions to the Greengrass Core

AWS Greengrass comes with a built-in deployment mechanism for configuration
changes and Lambda functions by default. Not only does this allow for a dynamic
adaption of the hosted process logic; it furthermore faciliates the concept of
"Continuous Delivery" at shop floor level.

To achieve automated re-deployment of the hosted Lambda functions on change,
[Terraform](https://www.terraform.io/) was used in combination with the
[official AWS CLI](https://aws.amazon.com/cli/). The process is triggered by
uploading a new function version to AWS. To do this, navigate to the root
directory of the Lambda function you want to deploy and execute

    make package

This will automatically built a package in the .zip format containing the
source code, the AWS Greengrass Core SDK and all further specified dependencies.

Annotation: The building process requires [Docker](https://www.docker.com/) to
be installed on your local machine.

Afterwards, upload the newly built package by executing

    terraform apply

from [the parent directory](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/greengrass/lambdas).
This will create the necessary AWS resources (S3 bucket to store the source
code, IAM policies), upload the function and automatically deploy it to the
Greengrass Core device.

Annotation: The deployment configuration can be found
[here](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/greengrass/lambdas/deploy.sh)
and has to be adjusted to the custom Lambda function's requirements (e.g.
regarding subscriptions or devices associated to the Greengrass Group).
