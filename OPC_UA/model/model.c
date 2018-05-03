/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "model.h"


/* RPI - ns=0;i=42001 */

static UA_StatusCode function_model_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "RPI");
attr.description = UA_LOCALIZEDTEXT("", "The base type for all object nodes.");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 42001),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 35),
UA_QUALIFIEDNAME(ns[0], "RPI"),
UA_NODEID_NUMERIC(ns[0], 58),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_model_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42001)
);
}

/* MPS - ns=0;i=42002 */

static UA_StatusCode function_model_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MPS");
attr.description = UA_LOCALIZEDTEXT("", "The base type for all object nodes.");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 42002),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 35),
UA_QUALIFIEDNAME(ns[0], "MPS"),
UA_NODEID_NUMERIC(ns[0], 58),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_model_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42002)
);
}

/* StackMagazine - ns=0;i=42005 */

static UA_StatusCode function_model_2_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "StackMagazine");
attr.description = UA_LOCALIZEDTEXT("", "The base type for all object nodes.");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 42002),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "VerticalMagazine"),
UA_NODEID_NUMERIC(ns[0], 58),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_model_2_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42005)
);
}

/* getStatus - ns=0;i=42046 */

static UA_StatusCode function_model_3_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "getStatus");
attr.description = UA_LOCALIZEDTEXT("", "getStatus");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42046),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "getStatus"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_3_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42046)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=0;i=42047 */

static UA_StatusCode function_model_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42047_Argument_0_0_struct;
variablenode_ns_0_i_42047_Argument_0_0_struct.Name = UA_STRING("partsAvailable");
variablenode_ns_0_i_42047_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42047_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42047_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42047_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42047_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42047_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "");
UA_ExtensionObject *variablenode_ns_0_i_42047_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42047_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42047_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42047_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42047_Argument_0_0 = variablenode_ns_0_i_42047_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42047_Argument_0_0 = &variablenode_ns_0_i_42047_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42047_Argument_0_0, &endvariablenode_ns_0_i_42047_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42047_Argument_0_0, &endvariablenode_ns_0_i_42047_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42047_Argument_0_0, &endvariablenode_ns_0_i_42047_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42047_Argument_0_0, &endvariablenode_ns_0_i_42047_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42047_Argument_0_0, &endvariablenode_ns_0_i_42047_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42047_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42047_Argument_0_0-variablenode_ns_0_i_42047_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42047_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42047_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42047_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42047_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42047_Argument_0_0_newBody, variablenode_ns_0_i_42047_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42047_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42047_Argument_0_0_oldBody = variablenode_ns_0_i_42047_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42047_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42047_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42047_Argument_0_0_oldBody);


struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42047_Argument_1_0_struct;
variablenode_ns_0_i_42047_Argument_1_0_struct.Name = UA_STRING("partsSupplied");
variablenode_ns_0_i_42047_Argument_1_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42047_Argument_1_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42047_Argument_1_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42047_Argument_1_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42047_Argument_1_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42047_Argument_1_0_struct.Description = UA_LOCALIZEDTEXT("", "");
UA_ExtensionObject *variablenode_ns_0_i_42047_Argument_1_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42047_Argument_1_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42047_Argument_1_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42047_Argument_1_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42047_Argument_1_0 = variablenode_ns_0_i_42047_Argument_1_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42047_Argument_1_0 = &variablenode_ns_0_i_42047_Argument_1_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_1_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42047_Argument_1_0, &endvariablenode_ns_0_i_42047_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_1_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42047_Argument_1_0, &endvariablenode_ns_0_i_42047_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_1_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42047_Argument_1_0, &endvariablenode_ns_0_i_42047_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_1_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42047_Argument_1_0, &endvariablenode_ns_0_i_42047_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42047_Argument_1_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42047_Argument_1_0, &endvariablenode_ns_0_i_42047_Argument_1_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42047_Argument_1_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42047_Argument_1_0-variablenode_ns_0_i_42047_Argument_1_0->content.encoded.body.data);
variablenode_ns_0_i_42047_Argument_1_0->content.encoded.body.length = variablenode_ns_0_i_42047_Argument_1_0_encOffset;
UA_Byte *variablenode_ns_0_i_42047_Argument_1_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42047_Argument_1_0_encOffset);
memcpy(variablenode_ns_0_i_42047_Argument_1_0_newBody, variablenode_ns_0_i_42047_Argument_1_0->content.encoded.body.data, variablenode_ns_0_i_42047_Argument_1_0_encOffset);
UA_Byte *variablenode_ns_0_i_42047_Argument_1_0_oldBody = variablenode_ns_0_i_42047_Argument_1_0->content.encoded.body.data;
variablenode_ns_0_i_42047_Argument_1_0->content.encoded.body.data = variablenode_ns_0_i_42047_Argument_1_0_newBody;
UA_free(variablenode_ns_0_i_42047_Argument_1_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42047_variant_DataContents[2];
variablenode_ns_0_i_42047_variant_DataContents[0] = *variablenode_ns_0_i_42047_Argument_0_0;
variablenode_ns_0_i_42047_variant_DataContents[1] = *variablenode_ns_0_i_42047_Argument_1_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42047_variant_DataContents, (UA_Int32) 2, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42047),
UA_NODEID_NUMERIC(ns[0], 42046),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42047_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42047_Argument_0_0);

UA_free(variablenode_ns_0_i_42047_Argument_1_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42047_Argument_1_0);
return retVal;
}

static UA_StatusCode function_model_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42047)
);
}

/* valveRetractCylinder - ns=0;i=42038 */

static UA_StatusCode function_model_5_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42038_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42038_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42038_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "valveRetractCylinder");
attr.description = UA_LOCALIZEDTEXT("", "valveRetractCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42038),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "valveRetractCylinder"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42038_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_5_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42038)
);
}

/* valveRetractCylinder - ns=0;i=42039 */

static UA_StatusCode function_model_6_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42039_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42039_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42039_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "valveRetractCylinder");
attr.description = UA_LOCALIZEDTEXT("", "valveRetractCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42039),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "valveRetractCylinder"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42039_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42039)
);
}

/* valveExtendCylinder - ns=0;i=42040 */

static UA_StatusCode function_model_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42040_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42040_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42040_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "valveExtendCylinder");
attr.description = UA_LOCALIZEDTEXT("", "valveExtendCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42040),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "valveExtendCylinder"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42040_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42040)
);
}

/* supplyPart - ns=0;i=42044 */

static UA_StatusCode function_model_8_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "supplyPart");
attr.description = UA_LOCALIZEDTEXT("", "supplyPart");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42044),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "supplyPart"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_8_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42044)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* retractCylinder - ns=0;i=42043 */

static UA_StatusCode function_model_9_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "retractCylinder");
attr.description = UA_LOCALIZEDTEXT("", "retractCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42043),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "retractCylinder"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_9_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42043)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* UserPanel - ns=0;i=42003 */

static UA_StatusCode function_model_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "UserPanel");
attr.description = UA_LOCALIZEDTEXT("", "The base type for all object nodes.");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 42002),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "UserPanel"),
UA_NODEID_NUMERIC(ns[0], 58),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_model_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42003)
);
}

/* limitCylinderExtended - ns=0;i=42037 */

static UA_StatusCode function_model_11_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42037_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42037_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42037_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "limitCylinderExtended");
attr.description = UA_LOCALIZEDTEXT("", "limitCylinderExtended");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42037),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "limitCylinderExtended"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42037_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_11_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42037)
);
}

/* Ejector - ns=0;i=42006 */

static UA_StatusCode function_model_12_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Ejector");
attr.description = UA_LOCALIZEDTEXT("", "The base type for all object nodes.");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 42002),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "Ejector"),
UA_NODEID_NUMERIC(ns[0], 58),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_model_12_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42006)
);
}

/* extendCylinder - ns=0;i=42042 */

static UA_StatusCode function_model_13_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "extendCylinder");
attr.description = UA_LOCALIZEDTEXT("", "extendCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42042),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "extendCylinder"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_13_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42042)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* swAutoMan - ns=0;i=42052 */

static UA_StatusCode function_model_14_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42052_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42052_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42052_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "swAutoMan");
attr.description = UA_LOCALIZEDTEXT("", "swAutoMan");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42052),
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "swAutoMan"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42052_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_14_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42052)
);
}

/* valveRetractCylinder - ns=0;i=42020 */

static UA_StatusCode function_model_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42020_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42020_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42020_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "valveRetractCylinder");
attr.description = UA_LOCALIZEDTEXT("", "valveRetractCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42020),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "valveRetractCylinder"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42020_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42020)
);
}

/* getLightBarrierRejects - ns=0;i=42032 */

static UA_StatusCode function_model_16_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "getLightBarrierRejects");
attr.description = UA_LOCALIZEDTEXT("", "getLightBarrierRejects");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42032),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "getLightBarrierRejects"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_16_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42032)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* getStatus - ns=0;i=42034 */

static UA_StatusCode function_model_17_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "getStatus");
attr.description = UA_LOCALIZEDTEXT("", "getStatus");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42034),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "getStatus"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_17_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42034)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* ledQ2 - ns=0;i=42056 */

static UA_StatusCode function_model_18_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42056_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42056_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42056_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ledQ2");
attr.description = UA_LOCALIZEDTEXT("", "ledQ2");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42056),
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ledQ2"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42056_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_18_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42056)
);
}

/* getProximitySensor - ns=0;i=42030 */

static UA_StatusCode function_model_19_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "getProximitySensor");
attr.description = UA_LOCALIZEDTEXT("", "getProximitySensor");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42030),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "getProximitySensor"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_19_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42030)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* emergencyStop - ns=0;i=42048 */

static UA_StatusCode function_model_20_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42048_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42048_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42048_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "emergencyStop");
attr.description = UA_LOCALIZEDTEXT("", "emergencyStop");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42048),
UA_NODEID_NUMERIC(ns[0], 42002),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "emergencyStop"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42048_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_20_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42048)
);
}

/* ejectPart - ns=0;i=42026 */

static UA_StatusCode function_model_21_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "ejectPart");
attr.description = UA_LOCALIZEDTEXT("", "ejectPart");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42026),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ejectPart"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_21_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42026)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* limitCylinderRetracted - ns=0;i=42017 */

static UA_StatusCode function_model_22_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42017_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42017_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42017_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "limitCylinderRetracted");
attr.description = UA_LOCALIZEDTEXT("", "limitCylinderRetracted");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42017),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "limitCylinderRetracted"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42017_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_22_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42017)
);
}

/* OutputArguments - ns=0;i=42033 */

static UA_StatusCode function_model_23_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42033_Argument_0_0_struct;
variablenode_ns_0_i_42033_Argument_0_0_struct.Name = UA_STRING("lightBarrierRejects");
variablenode_ns_0_i_42033_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42033_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42033_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42033_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42033_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42033_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "");
UA_ExtensionObject *variablenode_ns_0_i_42033_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42033_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42033_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42033_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42033_Argument_0_0 = variablenode_ns_0_i_42033_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42033_Argument_0_0 = &variablenode_ns_0_i_42033_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42033_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42033_Argument_0_0, &endvariablenode_ns_0_i_42033_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42033_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42033_Argument_0_0, &endvariablenode_ns_0_i_42033_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42033_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42033_Argument_0_0, &endvariablenode_ns_0_i_42033_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42033_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42033_Argument_0_0, &endvariablenode_ns_0_i_42033_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42033_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42033_Argument_0_0, &endvariablenode_ns_0_i_42033_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42033_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42033_Argument_0_0-variablenode_ns_0_i_42033_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42033_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42033_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42033_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42033_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42033_Argument_0_0_newBody, variablenode_ns_0_i_42033_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42033_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42033_Argument_0_0_oldBody = variablenode_ns_0_i_42033_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42033_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42033_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42033_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42033_variant_DataContents[1];
variablenode_ns_0_i_42033_variant_DataContents[0] = *variablenode_ns_0_i_42033_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42033_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42033),
UA_NODEID_NUMERIC(ns[0], 42032),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42033_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42033_Argument_0_0);
return retVal;
}

static UA_StatusCode function_model_23_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42033)
);
}

/* OutputArguments - ns=0;i=42035 */

static UA_StatusCode function_model_24_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42035_Argument_0_0_struct;
variablenode_ns_0_i_42035_Argument_0_0_struct.Name = UA_STRING("proximitySensor");
variablenode_ns_0_i_42035_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42035_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42035_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42035_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42035_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42035_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "0: no part detected; 1: part detected");
UA_ExtensionObject *variablenode_ns_0_i_42035_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42035_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42035_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42035_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42035_Argument_0_0 = variablenode_ns_0_i_42035_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42035_Argument_0_0 = &variablenode_ns_0_i_42035_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42035_Argument_0_0, &endvariablenode_ns_0_i_42035_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42035_Argument_0_0, &endvariablenode_ns_0_i_42035_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42035_Argument_0_0, &endvariablenode_ns_0_i_42035_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42035_Argument_0_0, &endvariablenode_ns_0_i_42035_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42035_Argument_0_0, &endvariablenode_ns_0_i_42035_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42035_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42035_Argument_0_0-variablenode_ns_0_i_42035_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42035_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42035_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42035_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42035_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42035_Argument_0_0_newBody, variablenode_ns_0_i_42035_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42035_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42035_Argument_0_0_oldBody = variablenode_ns_0_i_42035_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42035_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42035_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42035_Argument_0_0_oldBody);


struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42035_Argument_1_0_struct;
variablenode_ns_0_i_42035_Argument_1_0_struct.Name = UA_STRING("lightBarrierRejects");
variablenode_ns_0_i_42035_Argument_1_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42035_Argument_1_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42035_Argument_1_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42035_Argument_1_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42035_Argument_1_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42035_Argument_1_0_struct.Description = UA_LOCALIZEDTEXT("", "0: light beam broken; 1: light beam unbroken");
UA_ExtensionObject *variablenode_ns_0_i_42035_Argument_1_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42035_Argument_1_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42035_Argument_1_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42035_Argument_1_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42035_Argument_1_0 = variablenode_ns_0_i_42035_Argument_1_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42035_Argument_1_0 = &variablenode_ns_0_i_42035_Argument_1_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_1_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42035_Argument_1_0, &endvariablenode_ns_0_i_42035_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_1_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42035_Argument_1_0, &endvariablenode_ns_0_i_42035_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_1_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42035_Argument_1_0, &endvariablenode_ns_0_i_42035_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_1_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42035_Argument_1_0, &endvariablenode_ns_0_i_42035_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_1_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42035_Argument_1_0, &endvariablenode_ns_0_i_42035_Argument_1_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42035_Argument_1_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42035_Argument_1_0-variablenode_ns_0_i_42035_Argument_1_0->content.encoded.body.data);
variablenode_ns_0_i_42035_Argument_1_0->content.encoded.body.length = variablenode_ns_0_i_42035_Argument_1_0_encOffset;
UA_Byte *variablenode_ns_0_i_42035_Argument_1_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42035_Argument_1_0_encOffset);
memcpy(variablenode_ns_0_i_42035_Argument_1_0_newBody, variablenode_ns_0_i_42035_Argument_1_0->content.encoded.body.data, variablenode_ns_0_i_42035_Argument_1_0_encOffset);
UA_Byte *variablenode_ns_0_i_42035_Argument_1_0_oldBody = variablenode_ns_0_i_42035_Argument_1_0->content.encoded.body.data;
variablenode_ns_0_i_42035_Argument_1_0->content.encoded.body.data = variablenode_ns_0_i_42035_Argument_1_0_newBody;
UA_free(variablenode_ns_0_i_42035_Argument_1_0_oldBody);


struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42035_Argument_2_0_struct;
variablenode_ns_0_i_42035_Argument_2_0_struct.Name = UA_STRING("partsEjected");
variablenode_ns_0_i_42035_Argument_2_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 5);
variablenode_ns_0_i_42035_Argument_2_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42035_Argument_2_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42035_Argument_2_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42035_Argument_2_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42035_Argument_2_0_struct.Description = UA_LOCALIZEDTEXT("", "total count of ecjected parts");
UA_ExtensionObject *variablenode_ns_0_i_42035_Argument_2_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42035_Argument_2_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42035_Argument_2_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42035_Argument_2_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42035_Argument_2_0 = variablenode_ns_0_i_42035_Argument_2_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42035_Argument_2_0 = &variablenode_ns_0_i_42035_Argument_2_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_2_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42035_Argument_2_0, &endvariablenode_ns_0_i_42035_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_2_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42035_Argument_2_0, &endvariablenode_ns_0_i_42035_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_2_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42035_Argument_2_0, &endvariablenode_ns_0_i_42035_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_2_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42035_Argument_2_0, &endvariablenode_ns_0_i_42035_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42035_Argument_2_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42035_Argument_2_0, &endvariablenode_ns_0_i_42035_Argument_2_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42035_Argument_2_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42035_Argument_2_0-variablenode_ns_0_i_42035_Argument_2_0->content.encoded.body.data);
variablenode_ns_0_i_42035_Argument_2_0->content.encoded.body.length = variablenode_ns_0_i_42035_Argument_2_0_encOffset;
UA_Byte *variablenode_ns_0_i_42035_Argument_2_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42035_Argument_2_0_encOffset);
memcpy(variablenode_ns_0_i_42035_Argument_2_0_newBody, variablenode_ns_0_i_42035_Argument_2_0->content.encoded.body.data, variablenode_ns_0_i_42035_Argument_2_0_encOffset);
UA_Byte *variablenode_ns_0_i_42035_Argument_2_0_oldBody = variablenode_ns_0_i_42035_Argument_2_0->content.encoded.body.data;
variablenode_ns_0_i_42035_Argument_2_0->content.encoded.body.data = variablenode_ns_0_i_42035_Argument_2_0_newBody;
UA_free(variablenode_ns_0_i_42035_Argument_2_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42035_variant_DataContents[3];
variablenode_ns_0_i_42035_variant_DataContents[0] = *variablenode_ns_0_i_42035_Argument_0_0;
variablenode_ns_0_i_42035_variant_DataContents[1] = *variablenode_ns_0_i_42035_Argument_1_0;
variablenode_ns_0_i_42035_variant_DataContents[2] = *variablenode_ns_0_i_42035_Argument_2_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42035_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42035),
UA_NODEID_NUMERIC(ns[0], 42034),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42035_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42035_Argument_0_0);

UA_free(variablenode_ns_0_i_42035_Argument_1_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42035_Argument_1_0);

UA_free(variablenode_ns_0_i_42035_Argument_2_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42035_Argument_2_0);
return retVal;
}

static UA_StatusCode function_model_24_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42035)
);
}

/* proximitySensor - ns=0;i=42028 */

static UA_StatusCode function_model_25_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42028_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42028_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42028_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "proximitySensor");
attr.description = UA_LOCALIZEDTEXT("", "proximitySensor");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42028),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "proximitySensor"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42028_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_25_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42028)
);
}

/* ledStart - ns=0;i=42053 */

static UA_StatusCode function_model_26_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42053_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42053_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42053_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ledStart");
attr.description = UA_LOCALIZEDTEXT("", "ledStart");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42053),
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ledStart"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42053_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_26_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42053)
);
}

/* OutputArguments - ns=0;i=42031 */

static UA_StatusCode function_model_27_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42031_Argument_0_0_struct;
variablenode_ns_0_i_42031_Argument_0_0_struct.Name = UA_STRING("proximitySensor");
variablenode_ns_0_i_42031_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42031_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42031_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42031_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42031_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42031_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "0: no part detected; 1: part detected");
UA_ExtensionObject *variablenode_ns_0_i_42031_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42031_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42031_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42031_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42031_Argument_0_0 = variablenode_ns_0_i_42031_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42031_Argument_0_0 = &variablenode_ns_0_i_42031_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42031_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42031_Argument_0_0, &endvariablenode_ns_0_i_42031_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42031_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42031_Argument_0_0, &endvariablenode_ns_0_i_42031_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42031_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42031_Argument_0_0, &endvariablenode_ns_0_i_42031_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42031_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42031_Argument_0_0, &endvariablenode_ns_0_i_42031_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42031_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42031_Argument_0_0, &endvariablenode_ns_0_i_42031_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42031_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42031_Argument_0_0-variablenode_ns_0_i_42031_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42031_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42031_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42031_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42031_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42031_Argument_0_0_newBody, variablenode_ns_0_i_42031_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42031_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42031_Argument_0_0_oldBody = variablenode_ns_0_i_42031_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42031_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42031_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42031_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42031_variant_DataContents[1];
variablenode_ns_0_i_42031_variant_DataContents[0] = *variablenode_ns_0_i_42031_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42031_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42031),
UA_NODEID_NUMERIC(ns[0], 42030),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42031_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42031_Argument_0_0);
return retVal;
}

static UA_StatusCode function_model_27_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42031)
);
}

/* Conveyor - ns=0;i=42004 */

static UA_StatusCode function_model_28_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Conveyor");
attr.description = UA_LOCALIZEDTEXT("", "The base type for all object nodes.");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 42002),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "Conveyor"),
UA_NODEID_NUMERIC(ns[0], 58),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_model_28_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42004)
);
}

/* btnStart - ns=0;i=42049 */

static UA_StatusCode function_model_29_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42049_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42049_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42049_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "btnStart");
attr.description = UA_LOCALIZEDTEXT("", "btnStart");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42049),
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "btnStart"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42049_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_29_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42049)
);
}

/* extendCylinder - ns=0;i=42022 */

static UA_StatusCode function_model_30_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "extendCylinder");
attr.description = UA_LOCALIZEDTEXT("", "extendCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42022),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "extendCylinder"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_30_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42022)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* move - ns=0;i=42014 */

static UA_StatusCode function_model_31_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "move");
attr.description = UA_LOCALIZEDTEXT("", "move");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42014),
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "move"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_31_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42014)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=0;i=42045 */

static UA_StatusCode function_model_32_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42045_Argument_0_0_struct;
variablenode_ns_0_i_42045_Argument_0_0_struct.Name = UA_STRING("success");
variablenode_ns_0_i_42045_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42045_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42045_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42045_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42045_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42045_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "1: part successfully supplied; 1: part could not be supplied");
UA_ExtensionObject *variablenode_ns_0_i_42045_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42045_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42045_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42045_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42045_Argument_0_0 = variablenode_ns_0_i_42045_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42045_Argument_0_0 = &variablenode_ns_0_i_42045_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42045_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42045_Argument_0_0, &endvariablenode_ns_0_i_42045_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42045_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42045_Argument_0_0, &endvariablenode_ns_0_i_42045_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42045_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42045_Argument_0_0, &endvariablenode_ns_0_i_42045_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42045_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42045_Argument_0_0, &endvariablenode_ns_0_i_42045_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42045_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42045_Argument_0_0, &endvariablenode_ns_0_i_42045_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42045_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42045_Argument_0_0-variablenode_ns_0_i_42045_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42045_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42045_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42045_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42045_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42045_Argument_0_0_newBody, variablenode_ns_0_i_42045_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42045_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42045_Argument_0_0_oldBody = variablenode_ns_0_i_42045_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42045_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42045_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42045_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42045_variant_DataContents[1];
variablenode_ns_0_i_42045_variant_DataContents[0] = *variablenode_ns_0_i_42045_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42045_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42045),
UA_NODEID_NUMERIC(ns[0], 42044),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42045_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42045_Argument_0_0);
return retVal;
}

static UA_StatusCode function_model_32_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42045)
);
}

/* limitCylinderRetracted - ns=0;i=42036 */

static UA_StatusCode function_model_33_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42036_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42036_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42036_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "limitCylinderRetracted");
attr.description = UA_LOCALIZEDTEXT("", "limitCylinderRetracted");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42036),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "limitCylinderRetracted"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42036_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_33_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42036)
);
}

/* valveExtendCylinder - ns=0;i=42021 */

static UA_StatusCode function_model_34_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42021_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42021_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42021_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "valveExtendCylinder");
attr.description = UA_LOCALIZEDTEXT("", "valveExtendCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42021),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "valveExtendCylinder"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42021_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_34_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42021)
);
}

/* limitCylinderExtended - ns=0;i=42018 */

static UA_StatusCode function_model_35_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42018_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42018_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42018_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "limitCylinderExtended");
attr.description = UA_LOCALIZEDTEXT("", "limitCylinderExtended");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42018),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "limitCylinderExtended"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42018_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_35_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42018)
);
}

/* lightBarrierRejects - ns=0;i=42029 */

static UA_StatusCode function_model_36_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42029_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42029_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42029_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "lightBarrierRejects");
attr.description = UA_LOCALIZEDTEXT("", "lightBarrierRejects");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42029),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "lightBarrierRejects"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42029_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_36_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42029)
);
}

/* partAvailable - ns=0;i=42019 */

static UA_StatusCode function_model_37_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42019_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42019_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42019_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "partAvailable");
attr.description = UA_LOCALIZEDTEXT("", "partAvailable");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42019),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "partAvailable"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42019_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_37_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42019)
);
}

/* ledReset - ns=0;i=42054 */

static UA_StatusCode function_model_38_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42054_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42054_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42054_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ledReset");
attr.description = UA_LOCALIZEDTEXT("", "ledReset");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42054),
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ledReset"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42054_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_38_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42054)
);
}

/* btnStop - ns=0;i=42050 */

static UA_StatusCode function_model_39_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42050_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42050_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42050_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "btnStop");
attr.description = UA_LOCALIZEDTEXT("", "btnStop");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42050),
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "btnStop"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42050_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_39_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42050)
);
}

/* retractCylinder - ns=0;i=42023 */

static UA_StatusCode function_model_40_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "retractCylinder");
attr.description = UA_LOCALIZEDTEXT("", "retractCylinder");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42023),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "retractCylinder"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_40_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42023)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* lightBarrierExit - ns=0;i=42011 */

static UA_StatusCode function_model_41_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42011_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42011_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42011_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "lightBarrierExit");
attr.description = UA_LOCALIZEDTEXT("", "lightBarrierExit");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42011),
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "lightBarrierExit"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42011_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_41_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42011)
);
}

/* lightBarrierPartAvailable - ns=0;i=42041 */

static UA_StatusCode function_model_42_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42041_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42041_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42041_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "lightBarrierPartAvailable");
attr.description = UA_LOCALIZEDTEXT("", "lightBarrierPartAvailable");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42041),
UA_NODEID_NUMERIC(ns[0], 42005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "lightBarrierPartAvailable"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42041_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_42_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42041)
);
}

/* getPartAvailability - ns=0;i=42024 */

static UA_StatusCode function_model_43_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "getPartAvailability");
attr.description = UA_LOCALIZEDTEXT("", "getPartAvailability");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42024),
UA_NODEID_NUMERIC(ns[0], 42006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "getPartAvailability"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_43_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42024)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* ledQ1 - ns=0;i=42055 */

static UA_StatusCode function_model_44_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42055_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42055_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42055_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ledQ1");
attr.description = UA_LOCALIZEDTEXT("", "ledQ1");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42055),
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ledQ1"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42055_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_44_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42055)
);
}

/* btnReset - ns=0;i=42051 */

static UA_StatusCode function_model_45_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42051_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42051_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42051_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "btnReset");
attr.description = UA_LOCALIZEDTEXT("", "btnReset");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42051),
UA_NODEID_NUMERIC(ns[0], 42003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "btnReset"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42051_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_45_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42051)
);
}

/* getStatus - ns=0;i=42012 */

static UA_StatusCode function_model_46_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "getStatus");
attr.description = UA_LOCALIZEDTEXT("", "getStatus");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42012),
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "getStatus"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_46_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42012)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=0;i=42027 */

static UA_StatusCode function_model_47_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42027_Argument_0_0_struct;
variablenode_ns_0_i_42027_Argument_0_0_struct.Name = UA_STRING("success");
variablenode_ns_0_i_42027_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42027_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42027_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42027_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42027_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42027_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "1: Part Ejection was successful; 0: Part could not be ejected");
UA_ExtensionObject *variablenode_ns_0_i_42027_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42027_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42027_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42027_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42027_Argument_0_0 = variablenode_ns_0_i_42027_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42027_Argument_0_0 = &variablenode_ns_0_i_42027_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42027_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42027_Argument_0_0, &endvariablenode_ns_0_i_42027_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42027_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42027_Argument_0_0, &endvariablenode_ns_0_i_42027_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42027_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42027_Argument_0_0, &endvariablenode_ns_0_i_42027_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42027_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42027_Argument_0_0, &endvariablenode_ns_0_i_42027_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42027_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42027_Argument_0_0, &endvariablenode_ns_0_i_42027_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42027_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42027_Argument_0_0-variablenode_ns_0_i_42027_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42027_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42027_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42027_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42027_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42027_Argument_0_0_newBody, variablenode_ns_0_i_42027_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42027_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42027_Argument_0_0_oldBody = variablenode_ns_0_i_42027_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42027_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42027_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42027_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42027_variant_DataContents[1];
variablenode_ns_0_i_42027_variant_DataContents[0] = *variablenode_ns_0_i_42027_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42027_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42027),
UA_NODEID_NUMERIC(ns[0], 42026),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42027_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42027_Argument_0_0);
return retVal;
}

static UA_StatusCode function_model_47_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42027)
);
}

/* active - ns=0;i=42007 */

static UA_StatusCode function_model_48_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42007_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42007_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42007_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "active");
attr.description = UA_LOCALIZEDTEXT("", "active");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42007),
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "active"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42007_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_48_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42007)
);
}

/* direction - ns=0;i=42008 */

static UA_StatusCode function_model_49_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42008_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42008_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42008_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "direction");
attr.description = UA_LOCALIZEDTEXT("", "direction");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42008),
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "direction"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42008_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_49_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42008)
);
}

/* stop - ns=0;i=42016 */

static UA_StatusCode function_model_50_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "stop");
attr.description = UA_LOCALIZEDTEXT("", "stop");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 42016),
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "stop"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_model_50_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42016)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=0;i=42013 */

static UA_StatusCode function_model_51_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42013_Argument_0_0_struct;
variablenode_ns_0_i_42013_Argument_0_0_struct.Name = UA_STRING("isMoving");
variablenode_ns_0_i_42013_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42013_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42013_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42013_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42013_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42013_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "0: stillstand; 1: moving");
UA_ExtensionObject *variablenode_ns_0_i_42013_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42013_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42013_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42013_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42013_Argument_0_0 = variablenode_ns_0_i_42013_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42013_Argument_0_0 = &variablenode_ns_0_i_42013_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42013_Argument_0_0, &endvariablenode_ns_0_i_42013_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42013_Argument_0_0, &endvariablenode_ns_0_i_42013_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42013_Argument_0_0, &endvariablenode_ns_0_i_42013_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42013_Argument_0_0, &endvariablenode_ns_0_i_42013_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42013_Argument_0_0, &endvariablenode_ns_0_i_42013_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42013_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42013_Argument_0_0-variablenode_ns_0_i_42013_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42013_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42013_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42013_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42013_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42013_Argument_0_0_newBody, variablenode_ns_0_i_42013_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42013_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42013_Argument_0_0_oldBody = variablenode_ns_0_i_42013_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42013_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42013_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42013_Argument_0_0_oldBody);


struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42013_Argument_1_0_struct;
variablenode_ns_0_i_42013_Argument_1_0_struct.Name = UA_STRING("direction");
variablenode_ns_0_i_42013_Argument_1_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42013_Argument_1_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42013_Argument_1_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42013_Argument_1_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42013_Argument_1_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42013_Argument_1_0_struct.Description = UA_LOCALIZEDTEXT("", "0: forward; 1: reverse");
UA_ExtensionObject *variablenode_ns_0_i_42013_Argument_1_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42013_Argument_1_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42013_Argument_1_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42013_Argument_1_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42013_Argument_1_0 = variablenode_ns_0_i_42013_Argument_1_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42013_Argument_1_0 = &variablenode_ns_0_i_42013_Argument_1_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_1_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42013_Argument_1_0, &endvariablenode_ns_0_i_42013_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_1_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42013_Argument_1_0, &endvariablenode_ns_0_i_42013_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_1_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42013_Argument_1_0, &endvariablenode_ns_0_i_42013_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_1_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42013_Argument_1_0, &endvariablenode_ns_0_i_42013_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_1_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42013_Argument_1_0, &endvariablenode_ns_0_i_42013_Argument_1_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42013_Argument_1_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42013_Argument_1_0-variablenode_ns_0_i_42013_Argument_1_0->content.encoded.body.data);
variablenode_ns_0_i_42013_Argument_1_0->content.encoded.body.length = variablenode_ns_0_i_42013_Argument_1_0_encOffset;
UA_Byte *variablenode_ns_0_i_42013_Argument_1_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42013_Argument_1_0_encOffset);
memcpy(variablenode_ns_0_i_42013_Argument_1_0_newBody, variablenode_ns_0_i_42013_Argument_1_0->content.encoded.body.data, variablenode_ns_0_i_42013_Argument_1_0_encOffset);
UA_Byte *variablenode_ns_0_i_42013_Argument_1_0_oldBody = variablenode_ns_0_i_42013_Argument_1_0->content.encoded.body.data;
variablenode_ns_0_i_42013_Argument_1_0->content.encoded.body.data = variablenode_ns_0_i_42013_Argument_1_0_newBody;
UA_free(variablenode_ns_0_i_42013_Argument_1_0_oldBody);


struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42013_Argument_2_0_struct;
variablenode_ns_0_i_42013_Argument_2_0_struct.Name = UA_STRING("speed");
variablenode_ns_0_i_42013_Argument_2_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42013_Argument_2_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42013_Argument_2_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42013_Argument_2_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42013_Argument_2_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42013_Argument_2_0_struct.Description = UA_LOCALIZEDTEXT("", "< 64: slow; >= 64: fast");
UA_ExtensionObject *variablenode_ns_0_i_42013_Argument_2_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42013_Argument_2_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42013_Argument_2_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42013_Argument_2_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42013_Argument_2_0 = variablenode_ns_0_i_42013_Argument_2_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42013_Argument_2_0 = &variablenode_ns_0_i_42013_Argument_2_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_2_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42013_Argument_2_0, &endvariablenode_ns_0_i_42013_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_2_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42013_Argument_2_0, &endvariablenode_ns_0_i_42013_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_2_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42013_Argument_2_0, &endvariablenode_ns_0_i_42013_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_2_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42013_Argument_2_0, &endvariablenode_ns_0_i_42013_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42013_Argument_2_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42013_Argument_2_0, &endvariablenode_ns_0_i_42013_Argument_2_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42013_Argument_2_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42013_Argument_2_0-variablenode_ns_0_i_42013_Argument_2_0->content.encoded.body.data);
variablenode_ns_0_i_42013_Argument_2_0->content.encoded.body.length = variablenode_ns_0_i_42013_Argument_2_0_encOffset;
UA_Byte *variablenode_ns_0_i_42013_Argument_2_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42013_Argument_2_0_encOffset);
memcpy(variablenode_ns_0_i_42013_Argument_2_0_newBody, variablenode_ns_0_i_42013_Argument_2_0->content.encoded.body.data, variablenode_ns_0_i_42013_Argument_2_0_encOffset);
UA_Byte *variablenode_ns_0_i_42013_Argument_2_0_oldBody = variablenode_ns_0_i_42013_Argument_2_0->content.encoded.body.data;
variablenode_ns_0_i_42013_Argument_2_0->content.encoded.body.data = variablenode_ns_0_i_42013_Argument_2_0_newBody;
UA_free(variablenode_ns_0_i_42013_Argument_2_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42013_variant_DataContents[3];
variablenode_ns_0_i_42013_variant_DataContents[0] = *variablenode_ns_0_i_42013_Argument_0_0;
variablenode_ns_0_i_42013_variant_DataContents[1] = *variablenode_ns_0_i_42013_Argument_1_0;
variablenode_ns_0_i_42013_variant_DataContents[2] = *variablenode_ns_0_i_42013_Argument_2_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42013_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42013),
UA_NODEID_NUMERIC(ns[0], 42012),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42013_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42013_Argument_0_0);

UA_free(variablenode_ns_0_i_42013_Argument_1_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42013_Argument_1_0);

UA_free(variablenode_ns_0_i_42013_Argument_2_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42013_Argument_2_0);
return retVal;
}

static UA_StatusCode function_model_51_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42013)
);
}

/* speed - ns=0;i=42009 */

static UA_StatusCode function_model_52_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3);
UA_Byte *variablenode_ns_0_i_42009_variant_DataContents =  UA_Byte_new();
*variablenode_ns_0_i_42009_variant_DataContents = (UA_Byte) 127;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42009_variant_DataContents, &UA_TYPES[UA_TYPES_BYTE]);
attr.displayName = UA_LOCALIZEDTEXT("", "speed");
attr.description = UA_LOCALIZEDTEXT("", "speed");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42009),
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "speed"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Byte_delete(variablenode_ns_0_i_42009_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_52_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42009)
);
}

/* lightBarrierEntry - ns=0;i=42010 */

static UA_StatusCode function_model_53_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_0_i_42010_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_0_i_42010_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_42010_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "lightBarrierEntry");
attr.description = UA_LOCALIZEDTEXT("", "lightBarrierEntry");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42010),
UA_NODEID_NUMERIC(ns[0], 42004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "lightBarrierEntry"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_0_i_42010_variant_DataContents);
return retVal;
}

static UA_StatusCode function_model_53_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42010)
);
}

/* InputArguments - ns=0;i=42015 */

static UA_StatusCode function_model_54_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42015_Argument_0_0_struct;
variablenode_ns_0_i_42015_Argument_0_0_struct.Name = UA_STRING("direction");
variablenode_ns_0_i_42015_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42015_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42015_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42015_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42015_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42015_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "0: forward; 1: reverse");
UA_ExtensionObject *variablenode_ns_0_i_42015_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42015_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42015_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42015_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42015_Argument_0_0 = variablenode_ns_0_i_42015_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42015_Argument_0_0 = &variablenode_ns_0_i_42015_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42015_Argument_0_0, &endvariablenode_ns_0_i_42015_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42015_Argument_0_0, &endvariablenode_ns_0_i_42015_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42015_Argument_0_0, &endvariablenode_ns_0_i_42015_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42015_Argument_0_0, &endvariablenode_ns_0_i_42015_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42015_Argument_0_0, &endvariablenode_ns_0_i_42015_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42015_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42015_Argument_0_0-variablenode_ns_0_i_42015_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42015_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42015_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42015_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42015_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42015_Argument_0_0_newBody, variablenode_ns_0_i_42015_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42015_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42015_Argument_0_0_oldBody = variablenode_ns_0_i_42015_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42015_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42015_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42015_Argument_0_0_oldBody);


struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42015_Argument_1_0_struct;
variablenode_ns_0_i_42015_Argument_1_0_struct.Name = UA_STRING("speed");
variablenode_ns_0_i_42015_Argument_1_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 3);
variablenode_ns_0_i_42015_Argument_1_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42015_Argument_1_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42015_Argument_1_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42015_Argument_1_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42015_Argument_1_0_struct.Description = UA_LOCALIZEDTEXT("", "< 64: slow; >= 64: fast");
UA_ExtensionObject *variablenode_ns_0_i_42015_Argument_1_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42015_Argument_1_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42015_Argument_1_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42015_Argument_1_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42015_Argument_1_0 = variablenode_ns_0_i_42015_Argument_1_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42015_Argument_1_0 = &variablenode_ns_0_i_42015_Argument_1_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_1_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42015_Argument_1_0, &endvariablenode_ns_0_i_42015_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_1_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42015_Argument_1_0, &endvariablenode_ns_0_i_42015_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_1_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42015_Argument_1_0, &endvariablenode_ns_0_i_42015_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_1_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42015_Argument_1_0, &endvariablenode_ns_0_i_42015_Argument_1_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_1_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42015_Argument_1_0, &endvariablenode_ns_0_i_42015_Argument_1_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42015_Argument_1_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42015_Argument_1_0-variablenode_ns_0_i_42015_Argument_1_0->content.encoded.body.data);
variablenode_ns_0_i_42015_Argument_1_0->content.encoded.body.length = variablenode_ns_0_i_42015_Argument_1_0_encOffset;
UA_Byte *variablenode_ns_0_i_42015_Argument_1_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42015_Argument_1_0_encOffset);
memcpy(variablenode_ns_0_i_42015_Argument_1_0_newBody, variablenode_ns_0_i_42015_Argument_1_0->content.encoded.body.data, variablenode_ns_0_i_42015_Argument_1_0_encOffset);
UA_Byte *variablenode_ns_0_i_42015_Argument_1_0_oldBody = variablenode_ns_0_i_42015_Argument_1_0->content.encoded.body.data;
variablenode_ns_0_i_42015_Argument_1_0->content.encoded.body.data = variablenode_ns_0_i_42015_Argument_1_0_newBody;
UA_free(variablenode_ns_0_i_42015_Argument_1_0_oldBody);


struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42015_Argument_2_0_struct;
variablenode_ns_0_i_42015_Argument_2_0_struct.Name = UA_STRING("duration");
variablenode_ns_0_i_42015_Argument_2_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 10);
variablenode_ns_0_i_42015_Argument_2_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42015_Argument_2_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42015_Argument_2_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42015_Argument_2_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42015_Argument_2_0_struct.Description = UA_LOCALIZEDTEXT("", "runtime in sec");
UA_ExtensionObject *variablenode_ns_0_i_42015_Argument_2_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42015_Argument_2_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42015_Argument_2_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42015_Argument_2_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42015_Argument_2_0 = variablenode_ns_0_i_42015_Argument_2_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42015_Argument_2_0 = &variablenode_ns_0_i_42015_Argument_2_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_2_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42015_Argument_2_0, &endvariablenode_ns_0_i_42015_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_2_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42015_Argument_2_0, &endvariablenode_ns_0_i_42015_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_2_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42015_Argument_2_0, &endvariablenode_ns_0_i_42015_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_2_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42015_Argument_2_0, &endvariablenode_ns_0_i_42015_Argument_2_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42015_Argument_2_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42015_Argument_2_0, &endvariablenode_ns_0_i_42015_Argument_2_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42015_Argument_2_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42015_Argument_2_0-variablenode_ns_0_i_42015_Argument_2_0->content.encoded.body.data);
variablenode_ns_0_i_42015_Argument_2_0->content.encoded.body.length = variablenode_ns_0_i_42015_Argument_2_0_encOffset;
UA_Byte *variablenode_ns_0_i_42015_Argument_2_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42015_Argument_2_0_encOffset);
memcpy(variablenode_ns_0_i_42015_Argument_2_0_newBody, variablenode_ns_0_i_42015_Argument_2_0->content.encoded.body.data, variablenode_ns_0_i_42015_Argument_2_0_encOffset);
UA_Byte *variablenode_ns_0_i_42015_Argument_2_0_oldBody = variablenode_ns_0_i_42015_Argument_2_0->content.encoded.body.data;
variablenode_ns_0_i_42015_Argument_2_0->content.encoded.body.data = variablenode_ns_0_i_42015_Argument_2_0_newBody;
UA_free(variablenode_ns_0_i_42015_Argument_2_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42015_variant_DataContents[3];
variablenode_ns_0_i_42015_variant_DataContents[0] = *variablenode_ns_0_i_42015_Argument_0_0;
variablenode_ns_0_i_42015_variant_DataContents[1] = *variablenode_ns_0_i_42015_Argument_1_0;
variablenode_ns_0_i_42015_variant_DataContents[2] = *variablenode_ns_0_i_42015_Argument_2_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42015_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
attr.description = UA_LOCALIZEDTEXT("", "InputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42015),
UA_NODEID_NUMERIC(ns[0], 42014),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42015_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42015_Argument_0_0);

UA_free(variablenode_ns_0_i_42015_Argument_1_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42015_Argument_1_0);

UA_free(variablenode_ns_0_i_42015_Argument_2_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42015_Argument_2_0);
return retVal;
}

static UA_StatusCode function_model_54_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42015)
);
}

/* OutputArguments - ns=0;i=42025 */

static UA_StatusCode function_model_55_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);

struct {
  UA_String Name;
  UA_NodeId DataType;
  UA_Int32 ValueRank;
  UA_Int32 ArrayDimensionsSize;
  UA_UInt32 *ArrayDimensions;
  UA_LocalizedText Description;
} variablenode_ns_0_i_42025_Argument_0_0_struct;
variablenode_ns_0_i_42025_Argument_0_0_struct.Name = UA_STRING("partAvailable");
variablenode_ns_0_i_42025_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_0_i_42025_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_0_i_42025_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_0_i_42025_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_0_i_42025_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_0_i_42025_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "");
UA_ExtensionObject *variablenode_ns_0_i_42025_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_0_i_42025_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_0_i_42025_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_0_i_42025_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_0_i_42025_Argument_0_0 = variablenode_ns_0_i_42025_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_0_i_42025_Argument_0_0 = &variablenode_ns_0_i_42025_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42025_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_0_i_42025_Argument_0_0, &endvariablenode_ns_0_i_42025_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42025_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_0_i_42025_Argument_0_0, &endvariablenode_ns_0_i_42025_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42025_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_0_i_42025_Argument_0_0, &endvariablenode_ns_0_i_42025_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42025_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_0_i_42025_Argument_0_0, &endvariablenode_ns_0_i_42025_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_0_i_42025_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_0_i_42025_Argument_0_0, &endvariablenode_ns_0_i_42025_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_0_i_42025_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_0_i_42025_Argument_0_0-variablenode_ns_0_i_42025_Argument_0_0->content.encoded.body.data);
variablenode_ns_0_i_42025_Argument_0_0->content.encoded.body.length = variablenode_ns_0_i_42025_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_0_i_42025_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_0_i_42025_Argument_0_0_encOffset);
memcpy(variablenode_ns_0_i_42025_Argument_0_0_newBody, variablenode_ns_0_i_42025_Argument_0_0->content.encoded.body.data, variablenode_ns_0_i_42025_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_0_i_42025_Argument_0_0_oldBody = variablenode_ns_0_i_42025_Argument_0_0->content.encoded.body.data;
variablenode_ns_0_i_42025_Argument_0_0->content.encoded.body.data = variablenode_ns_0_i_42025_Argument_0_0_newBody;
UA_free(variablenode_ns_0_i_42025_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_0_i_42025_variant_DataContents[1];
variablenode_ns_0_i_42025_variant_DataContents[0] = *variablenode_ns_0_i_42025_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_42025_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 42025),
UA_NODEID_NUMERIC(ns[0], 42024),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_0_i_42025_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_0_i_42025_Argument_0_0);
return retVal;
}

static UA_StatusCode function_model_55_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 42025)
);
}

UA_StatusCode model(UA_Server *server) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
/* Use namespace ids generated by the server */
UA_UInt16 ns[1];
ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
retVal |= function_model_0_begin(server, ns);
retVal |= function_model_1_begin(server, ns);
retVal |= function_model_2_begin(server, ns);
retVal |= function_model_3_begin(server, ns);
retVal |= function_model_4_begin(server, ns);
retVal |= function_model_5_begin(server, ns);
retVal |= function_model_6_begin(server, ns);
retVal |= function_model_7_begin(server, ns);
retVal |= function_model_8_begin(server, ns);
retVal |= function_model_9_begin(server, ns);
retVal |= function_model_10_begin(server, ns);
retVal |= function_model_11_begin(server, ns);
retVal |= function_model_12_begin(server, ns);
retVal |= function_model_13_begin(server, ns);
retVal |= function_model_14_begin(server, ns);
retVal |= function_model_15_begin(server, ns);
retVal |= function_model_16_begin(server, ns);
retVal |= function_model_17_begin(server, ns);
retVal |= function_model_18_begin(server, ns);
retVal |= function_model_19_begin(server, ns);
retVal |= function_model_20_begin(server, ns);
retVal |= function_model_21_begin(server, ns);
retVal |= function_model_22_begin(server, ns);
retVal |= function_model_23_begin(server, ns);
retVal |= function_model_24_begin(server, ns);
retVal |= function_model_25_begin(server, ns);
retVal |= function_model_26_begin(server, ns);
retVal |= function_model_27_begin(server, ns);
retVal |= function_model_28_begin(server, ns);
retVal |= function_model_29_begin(server, ns);
retVal |= function_model_30_begin(server, ns);
retVal |= function_model_31_begin(server, ns);
retVal |= function_model_32_begin(server, ns);
retVal |= function_model_33_begin(server, ns);
retVal |= function_model_34_begin(server, ns);
retVal |= function_model_35_begin(server, ns);
retVal |= function_model_36_begin(server, ns);
retVal |= function_model_37_begin(server, ns);
retVal |= function_model_38_begin(server, ns);
retVal |= function_model_39_begin(server, ns);
retVal |= function_model_40_begin(server, ns);
retVal |= function_model_41_begin(server, ns);
retVal |= function_model_42_begin(server, ns);
retVal |= function_model_43_begin(server, ns);
retVal |= function_model_44_begin(server, ns);
retVal |= function_model_45_begin(server, ns);
retVal |= function_model_46_begin(server, ns);
retVal |= function_model_47_begin(server, ns);
retVal |= function_model_48_begin(server, ns);
retVal |= function_model_49_begin(server, ns);
retVal |= function_model_50_begin(server, ns);
retVal |= function_model_51_begin(server, ns);
retVal |= function_model_52_begin(server, ns);
retVal |= function_model_53_begin(server, ns);
retVal |= function_model_54_begin(server, ns);
retVal |= function_model_55_begin(server, ns);
retVal |= function_model_55_finish(server, ns);
retVal |= function_model_54_finish(server, ns);
retVal |= function_model_53_finish(server, ns);
retVal |= function_model_52_finish(server, ns);
retVal |= function_model_51_finish(server, ns);
retVal |= function_model_50_finish(server, ns);
retVal |= function_model_49_finish(server, ns);
retVal |= function_model_48_finish(server, ns);
retVal |= function_model_47_finish(server, ns);
retVal |= function_model_46_finish(server, ns);
retVal |= function_model_45_finish(server, ns);
retVal |= function_model_44_finish(server, ns);
retVal |= function_model_43_finish(server, ns);
retVal |= function_model_42_finish(server, ns);
retVal |= function_model_41_finish(server, ns);
retVal |= function_model_40_finish(server, ns);
retVal |= function_model_39_finish(server, ns);
retVal |= function_model_38_finish(server, ns);
retVal |= function_model_37_finish(server, ns);
retVal |= function_model_36_finish(server, ns);
retVal |= function_model_35_finish(server, ns);
retVal |= function_model_34_finish(server, ns);
retVal |= function_model_33_finish(server, ns);
retVal |= function_model_32_finish(server, ns);
retVal |= function_model_31_finish(server, ns);
retVal |= function_model_30_finish(server, ns);
retVal |= function_model_29_finish(server, ns);
retVal |= function_model_28_finish(server, ns);
retVal |= function_model_27_finish(server, ns);
retVal |= function_model_26_finish(server, ns);
retVal |= function_model_25_finish(server, ns);
retVal |= function_model_24_finish(server, ns);
retVal |= function_model_23_finish(server, ns);
retVal |= function_model_22_finish(server, ns);
retVal |= function_model_21_finish(server, ns);
retVal |= function_model_20_finish(server, ns);
retVal |= function_model_19_finish(server, ns);
retVal |= function_model_18_finish(server, ns);
retVal |= function_model_17_finish(server, ns);
retVal |= function_model_16_finish(server, ns);
retVal |= function_model_15_finish(server, ns);
retVal |= function_model_14_finish(server, ns);
retVal |= function_model_13_finish(server, ns);
retVal |= function_model_12_finish(server, ns);
retVal |= function_model_11_finish(server, ns);
retVal |= function_model_10_finish(server, ns);
retVal |= function_model_9_finish(server, ns);
retVal |= function_model_8_finish(server, ns);
retVal |= function_model_7_finish(server, ns);
retVal |= function_model_6_finish(server, ns);
retVal |= function_model_5_finish(server, ns);
retVal |= function_model_4_finish(server, ns);
retVal |= function_model_3_finish(server, ns);
retVal |= function_model_2_finish(server, ns);
retVal |= function_model_1_finish(server, ns);
retVal |= function_model_0_finish(server, ns);
return retVal;
}
