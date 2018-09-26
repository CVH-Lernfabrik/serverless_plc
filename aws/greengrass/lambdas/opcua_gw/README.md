## OPC UA gateway

This Lambda function implements a fully functional, bidirectional OPC UA gateway
with integrated state synchronization w/ AWS using the AWS Shadow Engine, thus
enabling the creation of a digital twin in the form of a virtual, reactive
representation of the real plant. Futhermore, OPC Methods are supported as
part of the OPC UA Information Model (as defined in DIN EN 62541) to faciliate
decoupled, API-focussed development approaches as they are currently becoming
more and more widespread with the ongoing trend towards individual, flexible
production systems.

### Configuration

To connect the gateway to an OPC UA server, three configuration steps are
necessary:

1\. In [config.json](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/greengrass/lambdas/opcua_gw/config.json), modify the section

    ```
    "connectionParameters": {
        "url": "{URL OF THE OPC SERVER}",
        "securityMode": "{SECURITY MODE}",
        "securityPolicy": "{SECURITY POLICY}",
        "serverCertificate": "{PATH TO THE SERVER CERTIFICATE IN PEM FORMAT (optional)}",
        "serverCertificateSelfSigned": {TRUE / FALSE (optional)},
        "username": "{USERNAME (optional)}",
        "password": "{PASSWORD (optional)}"
    }
    ```

to match the settings of your OPC server. Please note, that the URL provided
has to match the one specified in the certificate in case an encrypted
connection shall be established. In case the `securityPolicy` is set to `NONE`,
the options `serverCertificate` and `serverCertificateSelfSigned` are ignored
(can be left blank).

2\. In the current state of implementation, it is necessary to manually configure
the node set of the server for the gateway to be able to resolve the connection
between node ID and the AWS representation of the physical entity. In a later
version, this could possibly be substituted by a further abstraction level such
as [AutomationML](https://www.automationml.org/o.red.c/home.html).

The gateway expects the nodeset defined in
[nodeset.json](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/greengrass/lambdas/opcua_gw/config.json) to have the following format:

    ```
    [
        {
            "thingName": "{AWS THING NAME}",
            "topic": "{TOPIC ON WHICH STATE CHANGES ARE PUBLISHED}",
            "UANodes": {
                "{NODE NAME}": {
                    "nodeId": "{NODE ID}",
                    "UANodeClass": "{NODE CLASS}",
                    "UADataType": "{NODE TYPE (optional)}",
                    "components": {
                        {SUBNODES (optional)}
                    }
                },
                ...
            }
        },
        ...
    ]
    ```

3\. Lastly, it is necessary to define the nodes whose status the gateway is to
monitor. This is done in
[nodeset.json](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/greengrass/lambdas/opcua_gw/subscriptions.json). The format is as follows:

    ```
    [
        {
            "thingName": "{AWS THING NAME}",
            "subscriptions": [
                "{ABSOLUTE PATH WITHIN THE NODESET (e.g. lightBarrier_infeed.components.state)}",
                ...
            ]
        },
        ...
    ]
    ```

### Deployment

As described
[here](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/greengrass/lambdas),
execute

    make package

from the current directory to build the source package for the Lambda function.
Then, afterwards, switch to
[the parent directory](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/aws/greengrass/lambdas)
and initiate the deployment to the Greengrass Core device via

    terraform apply
