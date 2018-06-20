# Serverless system integration on an industrial level
This case study aims to demonstrate the advantages of a serverless system architecture in the field of IoT and Industrie 4.0. 
It is designed to serve as an example for how a traditional SCADA system can be substituted by a Linux-based PLC with connection to a cloud service via an edge gateway.

To evaluate the technological challenges the design of this architecture imposes, the model of an industrial plant has been interfaced to a cloud-based process automation system via OPC UA. The process logic - originally implemented solely onto a single PLC - is decentralized and split up between the cloud and the edge (PLC / OPC UA) level.

The core technologies utilized include Amazon Web Services (AWS) IoT as a cloud service and AWS Greengrass on the fog layer for redundancy. 
The main objective of this case study is the evaluation of the benefits and downsides of such a decentralized architecture in conjunction with new, holistic programming paradigms in the context of Industrie 4.0.

Part of the secondary objectives is the integration of a digital twin in the style of AutomationML. Additional attention is given to the aspects of redundancy and availability as well as deployment of software changes. 
The following illustration visualizes the architectural concept:

![](doc/img/architecture.png)

The project can be divided in three parts:

1. Setting up an OPC UA-server as an interface to the machinery
2. Setting up an AWS Greengrass instance on fog-level
3. Implementing the process logic
