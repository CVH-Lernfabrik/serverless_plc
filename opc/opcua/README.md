## OPC UA server

This directory contains all resources related to implementation and setup of
the OPC UA server, which served as the interface between Edge and Fog layer
(cf. [architecture diagram](https://github.com/CVH-Lernfabrik/serverless_plc/blob/master/doc/img/architecture.png)).

The [model](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/opc/opcua/model)
subdirectory contains several nodeset versions used in the scope of this
project (in this case generated via the [FreeOpcUA modeller](https://github.com/FreeOpcUa/opcua-modeler)).
Furthermore, two sample OPC UA server implementations based on
[open62541](https://open62541.org/) are provided in the form of
[open62541_base](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/opc/opcua/open62541_base)
and
[open62541_methods](https://github.com/CVH-Lernfabrik/serverless_plc/tree/master/opc/opcua/open62541_methods),
the former demonstrating the basic setup of an encrypted server with a custom
configuration and nodeset, while the latter extends this model by using OPC UA
Methods to enable a decentralized, API-first development approach.
