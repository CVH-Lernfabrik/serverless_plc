/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "revpi_open62541_IO_methods.h"


/* O_2 - ns=1;s=O_2 */

static UA_StatusCode function_revpi_open62541_IO_methods_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_2_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_2_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_2_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_2");
attr.description = UA_LOCALIZEDTEXT("", "O_2");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_2"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_2"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_2_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_2")
);
}

/* I_5 - ns=1;s=I_5 */

static UA_StatusCode function_revpi_open62541_IO_methods_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_5_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_5_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_5_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_5");
attr.description = UA_LOCALIZEDTEXT("", "I_5");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_5"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_5"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_5_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_5")
);
}

/* O_14 - ns=1;s=O_14 */

static UA_StatusCode function_revpi_open62541_IO_methods_2_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_14_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_14_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_14_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_14");
attr.description = UA_LOCALIZEDTEXT("", "O_14");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_14"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_14"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_14_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_2_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_14")
);
}

/* I_1 - ns=1;s=I_1 */

static UA_StatusCode function_revpi_open62541_IO_methods_3_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_1_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_1_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_1_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_1");
attr.description = UA_LOCALIZEDTEXT("", "I_1");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_1"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_1"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_1_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_3_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_1")
);
}

/* ModularProductionSystemCoreModuleType - ns=1;i=1001 */

static UA_StatusCode function_revpi_open62541_IO_methods_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ModularProductionSystemCoreModuleType");
attr.description = UA_LOCALIZEDTEXT("", "ModularProductionSystemCoreModuleType");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[1], 1001),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[1], "ModularProductionSystemCoreModuleType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 1001)
);
}

/* I_7 - ns=1;s=I_7 */

static UA_StatusCode function_revpi_open62541_IO_methods_5_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_7_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_7_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_7_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_7");
attr.description = UA_LOCALIZEDTEXT("", "I_7");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_7"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_7"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_7_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_5_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_7")
);
}

/* I_10 - ns=1;s=I_10 */

static UA_StatusCode function_revpi_open62541_IO_methods_6_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_10_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_10_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_10_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_10");
attr.description = UA_LOCALIZEDTEXT("", "I_10");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_10"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_10"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_10_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_10")
);
}

/* I_14 - ns=1;s=I_14 */

static UA_StatusCode function_revpi_open62541_IO_methods_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_14_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_14_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_14_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_14");
attr.description = UA_LOCALIZEDTEXT("", "I_14");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_14"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_14"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_14_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_14")
);
}

/* I_6 - ns=1;s=I_6 */

static UA_StatusCode function_revpi_open62541_IO_methods_8_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_6_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_6_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_6_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_6");
attr.description = UA_LOCALIZEDTEXT("", "I_6");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_6"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_6"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_6_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_8_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_6")
);
}

/* IndicatorType - ns=1;i=2005 */

static UA_StatusCode function_revpi_open62541_IO_methods_9_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IndicatorType");
attr.description = UA_LOCALIZEDTEXT("", "IndicatorType");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[1], 2005),
UA_NODEID_NUMERIC(ns[1], 1001),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[1], "IndicatorType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_9_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2005)
);
}

/* O_5 - ns=1;s=O_5 */

static UA_StatusCode function_revpi_open62541_IO_methods_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_5_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_5_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_5_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_5");
attr.description = UA_LOCALIZEDTEXT("", "O_5");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_5"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_5"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_5_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_5")
);
}

/* I_2 - ns=1;s=I_2 */

static UA_StatusCode function_revpi_open62541_IO_methods_11_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_2_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_2_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_2_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_2");
attr.description = UA_LOCALIZEDTEXT("", "I_2");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_2"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_2"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_2_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_11_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_2")
);
}

/* O_10 - ns=1;s=O_10 */

static UA_StatusCode function_revpi_open62541_IO_methods_12_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_10_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_10_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_10_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_10");
attr.description = UA_LOCALIZEDTEXT("", "O_10");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_10"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_10"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_10_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_12_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_10")
);
}

/* OutputPin - ns=1;i=2006 */

static UA_StatusCode function_revpi_open62541_IO_methods_13_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_STACKARRAY(UA_String, variablenode_ns_1_i_2006_variant_DataContents, 1);
UA_init(variablenode_ns_1_i_2006_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2006_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputPin");
attr.description = UA_LOCALIZEDTEXT("", "OutputPin");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2006),
UA_NODEID_NUMERIC(ns[1], 2005),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "OutputPin"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2006), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_13_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2006)
);
}

/* O_3 - ns=1;s=O_3 */

static UA_StatusCode function_revpi_open62541_IO_methods_14_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_3_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_3_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_3_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_3");
attr.description = UA_LOCALIZEDTEXT("", "O_3");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_3"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_3"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_3_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_14_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_3")
);
}

/* O_15 - ns=1;s=O_15 */

static UA_StatusCode function_revpi_open62541_IO_methods_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_15_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_15_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_15_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_15");
attr.description = UA_LOCALIZEDTEXT("", "O_15");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_15"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_15"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_15_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_15")
);
}

/* O_9 - ns=1;s=O_9 */

static UA_StatusCode function_revpi_open62541_IO_methods_16_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_9_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_9_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_9_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_9");
attr.description = UA_LOCALIZEDTEXT("", "O_9");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_9"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_9"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_9_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_16_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_9")
);
}

/* O_11 - ns=1;s=O_11 */

static UA_StatusCode function_revpi_open62541_IO_methods_17_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_11_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_11_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_11_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_11");
attr.description = UA_LOCALIZEDTEXT("", "O_11");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_11"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_11"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_11_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_17_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_11")
);
}

/* I_12 - ns=1;s=I_12 */

static UA_StatusCode function_revpi_open62541_IO_methods_18_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_12_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_12_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_12_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_12");
attr.description = UA_LOCALIZEDTEXT("", "I_12");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_12"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_12"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_12_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_18_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_12")
);
}

/* O_6 - ns=1;s=O_6 */

static UA_StatusCode function_revpi_open62541_IO_methods_19_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_6_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_6_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_6_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_6");
attr.description = UA_LOCALIZEDTEXT("", "O_6");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_6"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_6"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_6_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_19_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_6")
);
}

/* O_8 - ns=1;s=O_8 */

static UA_StatusCode function_revpi_open62541_IO_methods_20_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_8_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_8_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_8_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_8");
attr.description = UA_LOCALIZEDTEXT("", "O_8");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_8"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_8"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_8_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_20_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_8")
);
}

/* I_15 - ns=1;s=I_15 */

static UA_StatusCode function_revpi_open62541_IO_methods_21_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_15_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_15_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_15_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_15");
attr.description = UA_LOCALIZEDTEXT("", "I_15");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_15"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_15"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_15_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_21_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_15")
);
}

/* O_7 - ns=1;s=O_7 */

static UA_StatusCode function_revpi_open62541_IO_methods_22_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_7_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_7_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_7_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_7");
attr.description = UA_LOCALIZEDTEXT("", "O_7");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_7"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_7"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_7_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_22_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_7")
);
}

/* I_11 - ns=1;s=I_11 */

static UA_StatusCode function_revpi_open62541_IO_methods_23_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_11_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_11_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_11_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_11");
attr.description = UA_LOCALIZEDTEXT("", "I_11");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_11"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_11"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_11_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_23_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_11")
);
}

/* O_1 - ns=1;s=O_1 */

static UA_StatusCode function_revpi_open62541_IO_methods_24_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_1_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_1_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_1_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_1");
attr.description = UA_LOCALIZEDTEXT("", "O_1");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_1"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_1"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_1_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_24_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_1")
);
}

/* I_16 - ns=1;s=I_16 */

static UA_StatusCode function_revpi_open62541_IO_methods_25_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_16_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_16_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_16_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_16");
attr.description = UA_LOCALIZEDTEXT("", "I_16");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_16"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_16"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_16_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_25_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_16")
);
}

/* O_12 - ns=1;s=O_12 */

static UA_StatusCode function_revpi_open62541_IO_methods_26_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_12_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_12_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_12_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_12");
attr.description = UA_LOCALIZEDTEXT("", "O_12");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_12"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_12"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_12_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_26_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_12")
);
}

/* O_13 - ns=1;s=O_13 */

static UA_StatusCode function_revpi_open62541_IO_methods_27_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_13_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_13_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_13_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_13");
attr.description = UA_LOCALIZEDTEXT("", "O_13");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_13"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_13"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_13_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_27_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_13")
);
}

/* I_8 - ns=1;s=I_8 */

static UA_StatusCode function_revpi_open62541_IO_methods_28_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_8_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_8_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_8_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_8");
attr.description = UA_LOCALIZEDTEXT("", "I_8");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_8"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_8"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_8_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_28_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_8")
);
}

/* O_16 - ns=1;s=O_16 */

static UA_StatusCode function_revpi_open62541_IO_methods_29_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_16_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_16_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_16_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_16");
attr.description = UA_LOCALIZEDTEXT("", "O_16");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_16"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_16"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_16_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_29_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_16")
);
}

/* I_4 - ns=1;s=I_4 */

static UA_StatusCode function_revpi_open62541_IO_methods_30_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_4_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_4_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_4_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_4");
attr.description = UA_LOCALIZEDTEXT("", "I_4");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_4"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_4"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_4_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_30_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_4")
);
}

/* O_4 - ns=1;s=O_4 */

static UA_StatusCode function_revpi_open62541_IO_methods_31_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_o_4_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_o_4_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_o_4_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "O_4");
attr.description = UA_LOCALIZEDTEXT("", "O_4");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "O_4"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "O_4"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_o_4_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_31_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "O_4")
);
}

/* I_3 - ns=1;s=I_3 */

static UA_StatusCode function_revpi_open62541_IO_methods_32_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_3_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_3_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_3_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_3");
attr.description = UA_LOCALIZEDTEXT("", "I_3");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_3"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_3"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_3_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_32_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_3")
);
}

/* getIndicatorState - ns=1;i=2010 */

static UA_StatusCode function_revpi_open62541_IO_methods_33_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "getIndicatorState");
attr.description = UA_LOCALIZEDTEXT("", "getIndicatorState");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2010),
UA_NODEID_NUMERIC(ns[1], 2005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "getIndicatorState"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2010), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_revpi_open62541_IO_methods_33_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2010)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* I_13 - ns=1;s=I_13 */

static UA_StatusCode function_revpi_open62541_IO_methods_34_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_13_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_13_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_13_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_13");
attr.description = UA_LOCALIZEDTEXT("", "I_13");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_13"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_13"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_13_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_34_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_13")
);
}

/* I_9 - ns=1;s=I_9 */

static UA_StatusCode function_revpi_open62541_IO_methods_35_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_s_i_9_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_s_i_9_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_s_i_9_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "I_9");
attr.description = UA_LOCALIZEDTEXT("", "I_9");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "I_9"),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "I_9"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_s_i_9_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_35_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "I_9")
);
}

/* setIndicatorState - ns=1;i=2008 */

static UA_StatusCode function_revpi_open62541_IO_methods_36_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "setIndicatorState");
attr.description = UA_LOCALIZEDTEXT("", "setIndicatorState");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2008),
UA_NODEID_NUMERIC(ns[1], 2005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "setIndicatorState"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2008), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_revpi_open62541_IO_methods_36_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2008)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* State - ns=1;i=2007 */

static UA_StatusCode function_revpi_open62541_IO_methods_37_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_i_2007_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_i_2007_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2007_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "State");
attr.description = UA_LOCALIZEDTEXT("", "State");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2007),
UA_NODEID_NUMERIC(ns[1], 2005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "State"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_i_2007_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2007), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_37_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2007)
);
}

/* OutputArguments - ns=1;i=2011 */

static UA_StatusCode function_revpi_open62541_IO_methods_38_begin(UA_Server *server, UA_UInt16* ns) {
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
} variablenode_ns_1_i_2011_Argument_0_0_struct;
variablenode_ns_1_i_2011_Argument_0_0_struct.Name = UA_STRING("state");
variablenode_ns_1_i_2011_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_1_i_2011_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_1_i_2011_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_1_i_2011_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_1_i_2011_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_1_i_2011_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "0: Indicator ist off; 1: Indicator is active");
UA_ExtensionObject *variablenode_ns_1_i_2011_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_1_i_2011_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_1_i_2011_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_1_i_2011_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_1_i_2011_Argument_0_0 = variablenode_ns_1_i_2011_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_1_i_2011_Argument_0_0 = &variablenode_ns_1_i_2011_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2011_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_1_i_2011_Argument_0_0, &endvariablenode_ns_1_i_2011_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2011_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_1_i_2011_Argument_0_0, &endvariablenode_ns_1_i_2011_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2011_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_1_i_2011_Argument_0_0, &endvariablenode_ns_1_i_2011_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2011_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_1_i_2011_Argument_0_0, &endvariablenode_ns_1_i_2011_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2011_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_1_i_2011_Argument_0_0, &endvariablenode_ns_1_i_2011_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_1_i_2011_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_1_i_2011_Argument_0_0-variablenode_ns_1_i_2011_Argument_0_0->content.encoded.body.data);
variablenode_ns_1_i_2011_Argument_0_0->content.encoded.body.length = variablenode_ns_1_i_2011_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_1_i_2011_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_1_i_2011_Argument_0_0_encOffset);
memcpy(variablenode_ns_1_i_2011_Argument_0_0_newBody, variablenode_ns_1_i_2011_Argument_0_0->content.encoded.body.data, variablenode_ns_1_i_2011_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_1_i_2011_Argument_0_0_oldBody = variablenode_ns_1_i_2011_Argument_0_0->content.encoded.body.data;
variablenode_ns_1_i_2011_Argument_0_0->content.encoded.body.data = variablenode_ns_1_i_2011_Argument_0_0_newBody;
UA_free(variablenode_ns_1_i_2011_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_1_i_2011_variant_DataContents[1];
variablenode_ns_1_i_2011_variant_DataContents[0] = *variablenode_ns_1_i_2011_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2011_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2011),
UA_NODEID_NUMERIC(ns[1], 2010),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_1_i_2011_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_1_i_2011_Argument_0_0);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2011), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_38_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2011)
);
}

/* StartLed - ns=1;i=5003 */

static UA_StatusCode function_revpi_open62541_IO_methods_39_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "StartLed");
attr.description = UA_LOCALIZEDTEXT("", "IndicatorType");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 5003),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 35),
UA_QUALIFIEDNAME(ns[1], "StartLed"),
UA_NODEID_NUMERIC(ns[1], 2005),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_39_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 5003)
);
}

/* InputArguments - ns=1;i=2009 */

static UA_StatusCode function_revpi_open62541_IO_methods_40_begin(UA_Server *server, UA_UInt16* ns) {
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
} variablenode_ns_1_i_2009_Argument_0_0_struct;
variablenode_ns_1_i_2009_Argument_0_0_struct.Name = UA_STRING("state");
variablenode_ns_1_i_2009_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_1_i_2009_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_1_i_2009_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_1_i_2009_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_1_i_2009_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_1_i_2009_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "0: Indicator is off; 1: Indicator is active");
UA_ExtensionObject *variablenode_ns_1_i_2009_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_1_i_2009_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_1_i_2009_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_1_i_2009_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_1_i_2009_Argument_0_0 = variablenode_ns_1_i_2009_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_1_i_2009_Argument_0_0 = &variablenode_ns_1_i_2009_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2009_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_1_i_2009_Argument_0_0, &endvariablenode_ns_1_i_2009_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2009_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_1_i_2009_Argument_0_0, &endvariablenode_ns_1_i_2009_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2009_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_1_i_2009_Argument_0_0, &endvariablenode_ns_1_i_2009_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2009_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_1_i_2009_Argument_0_0, &endvariablenode_ns_1_i_2009_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2009_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_1_i_2009_Argument_0_0, &endvariablenode_ns_1_i_2009_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_1_i_2009_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_1_i_2009_Argument_0_0-variablenode_ns_1_i_2009_Argument_0_0->content.encoded.body.data);
variablenode_ns_1_i_2009_Argument_0_0->content.encoded.body.length = variablenode_ns_1_i_2009_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_1_i_2009_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_1_i_2009_Argument_0_0_encOffset);
memcpy(variablenode_ns_1_i_2009_Argument_0_0_newBody, variablenode_ns_1_i_2009_Argument_0_0->content.encoded.body.data, variablenode_ns_1_i_2009_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_1_i_2009_Argument_0_0_oldBody = variablenode_ns_1_i_2009_Argument_0_0->content.encoded.body.data;
variablenode_ns_1_i_2009_Argument_0_0->content.encoded.body.data = variablenode_ns_1_i_2009_Argument_0_0_newBody;
UA_free(variablenode_ns_1_i_2009_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_1_i_2009_variant_DataContents[1];
variablenode_ns_1_i_2009_variant_DataContents[0] = *variablenode_ns_1_i_2009_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2009_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
attr.description = UA_LOCALIZEDTEXT("", "InputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2009),
UA_NODEID_NUMERIC(ns[1], 2008),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_1_i_2009_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_1_i_2009_Argument_0_0);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2009), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_40_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2009)
);
}

/* setIndicatorState - ns=1;i=2014 */

static UA_StatusCode function_revpi_open62541_IO_methods_41_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "setIndicatorState");
attr.description = UA_LOCALIZEDTEXT("", "setIndicatorState");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2014),
UA_NODEID_NUMERIC(ns[1], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "setIndicatorState"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_revpi_open62541_IO_methods_41_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2014)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=1;i=2015 */

static UA_StatusCode function_revpi_open62541_IO_methods_42_begin(UA_Server *server, UA_UInt16* ns) {
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
} variablenode_ns_1_i_2015_Argument_0_0_struct;
variablenode_ns_1_i_2015_Argument_0_0_struct.Name = UA_STRING("state");
variablenode_ns_1_i_2015_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_1_i_2015_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_1_i_2015_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_1_i_2015_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_1_i_2015_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_1_i_2015_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "0: Indicator is off; 1: Indicator is active");
UA_ExtensionObject *variablenode_ns_1_i_2015_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_1_i_2015_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_1_i_2015_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_1_i_2015_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_1_i_2015_Argument_0_0 = variablenode_ns_1_i_2015_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_1_i_2015_Argument_0_0 = &variablenode_ns_1_i_2015_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2015_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_1_i_2015_Argument_0_0, &endvariablenode_ns_1_i_2015_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2015_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_1_i_2015_Argument_0_0, &endvariablenode_ns_1_i_2015_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2015_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_1_i_2015_Argument_0_0, &endvariablenode_ns_1_i_2015_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2015_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_1_i_2015_Argument_0_0, &endvariablenode_ns_1_i_2015_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2015_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_1_i_2015_Argument_0_0, &endvariablenode_ns_1_i_2015_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_1_i_2015_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_1_i_2015_Argument_0_0-variablenode_ns_1_i_2015_Argument_0_0->content.encoded.body.data);
variablenode_ns_1_i_2015_Argument_0_0->content.encoded.body.length = variablenode_ns_1_i_2015_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_1_i_2015_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_1_i_2015_Argument_0_0_encOffset);
memcpy(variablenode_ns_1_i_2015_Argument_0_0_newBody, variablenode_ns_1_i_2015_Argument_0_0->content.encoded.body.data, variablenode_ns_1_i_2015_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_1_i_2015_Argument_0_0_oldBody = variablenode_ns_1_i_2015_Argument_0_0->content.encoded.body.data;
variablenode_ns_1_i_2015_Argument_0_0->content.encoded.body.data = variablenode_ns_1_i_2015_Argument_0_0_newBody;
UA_free(variablenode_ns_1_i_2015_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_1_i_2015_variant_DataContents[1];
variablenode_ns_1_i_2015_variant_DataContents[0] = *variablenode_ns_1_i_2015_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2015_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
attr.description = UA_LOCALIZEDTEXT("", "InputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2015),
UA_NODEID_NUMERIC(ns[1], 2014),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_1_i_2015_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_1_i_2015_Argument_0_0);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_42_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2015)
);
}

/* getIndicatorState - ns=1;i=2016 */

static UA_StatusCode function_revpi_open62541_IO_methods_43_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "getIndicatorState");
attr.description = UA_LOCALIZEDTEXT("", "getIndicatorState");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2016),
UA_NODEID_NUMERIC(ns[1], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "getIndicatorState"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_revpi_open62541_IO_methods_43_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2016)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputPin - ns=1;i=2012 */

static UA_StatusCode function_revpi_open62541_IO_methods_44_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_1_i_2012_variant_DataContents =  UA_String_new();
*variablenode_ns_1_i_2012_variant_DataContents = UA_STRING_ALLOC("O_1");
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2012_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputPin");
attr.description = UA_LOCALIZEDTEXT("", "OutputPin");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2012),
UA_NODEID_NUMERIC(ns[1], 5003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "OutputPin"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_1_i_2012_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_44_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2012)
);
}

/* OutputArguments - ns=1;i=2017 */

static UA_StatusCode function_revpi_open62541_IO_methods_45_begin(UA_Server *server, UA_UInt16* ns) {
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
} variablenode_ns_1_i_2017_Argument_0_0_struct;
variablenode_ns_1_i_2017_Argument_0_0_struct.Name = UA_STRING("state");
variablenode_ns_1_i_2017_Argument_0_0_struct.DataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_1_i_2017_Argument_0_0_struct.ValueRank = (UA_Int32) -1;
variablenode_ns_1_i_2017_Argument_0_0_struct.ArrayDimensionsSize = 1;
variablenode_ns_1_i_2017_Argument_0_0_struct.ArrayDimensions = (UA_UInt32*) UA_malloc(sizeof(UA_UInt32));
variablenode_ns_1_i_2017_Argument_0_0_struct.ArrayDimensions[0]  = (UA_UInt32) 0;
variablenode_ns_1_i_2017_Argument_0_0_struct.Description = UA_LOCALIZEDTEXT("", "0: Indicator ist off; 1: Indicator is active");
UA_ExtensionObject *variablenode_ns_1_i_2017_Argument_0_0 =  UA_ExtensionObject_new();
variablenode_ns_1_i_2017_Argument_0_0->encoding = UA_EXTENSIONOBJECT_ENCODED_BYTESTRING;
variablenode_ns_1_i_2017_Argument_0_0->content.encoded.typeId = UA_NODEID_NUMERIC(0, 298);
UA_ByteString_allocBuffer(&variablenode_ns_1_i_2017_Argument_0_0->content.encoded.body, 65000);
UA_Byte *posvariablenode_ns_1_i_2017_Argument_0_0 = variablenode_ns_1_i_2017_Argument_0_0->content.encoded.body.data;
const UA_Byte *endvariablenode_ns_1_i_2017_Argument_0_0 = &variablenode_ns_1_i_2017_Argument_0_0->content.encoded.body.data[65000];
{
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2017_Argument_0_0_struct.Name, &UA_TYPES[UA_TYPES_STRING], &posvariablenode_ns_1_i_2017_Argument_0_0, &endvariablenode_ns_1_i_2017_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2017_Argument_0_0_struct.DataType, &UA_TYPES[UA_TYPES_NODEID], &posvariablenode_ns_1_i_2017_Argument_0_0, &endvariablenode_ns_1_i_2017_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2017_Argument_0_0_struct.ValueRank, &UA_TYPES[UA_TYPES_INT32], &posvariablenode_ns_1_i_2017_Argument_0_0, &endvariablenode_ns_1_i_2017_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2017_Argument_0_0_struct.ArrayDimensions[0], &UA_TYPES[UA_TYPES_UINT32], &posvariablenode_ns_1_i_2017_Argument_0_0, &endvariablenode_ns_1_i_2017_Argument_0_0, NULL, NULL);
retVal |= UA_encodeBinary(&variablenode_ns_1_i_2017_Argument_0_0_struct.Description, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], &posvariablenode_ns_1_i_2017_Argument_0_0, &endvariablenode_ns_1_i_2017_Argument_0_0, NULL, NULL);
}
size_t variablenode_ns_1_i_2017_Argument_0_0_encOffset = (uintptr_t)(posvariablenode_ns_1_i_2017_Argument_0_0-variablenode_ns_1_i_2017_Argument_0_0->content.encoded.body.data);
variablenode_ns_1_i_2017_Argument_0_0->content.encoded.body.length = variablenode_ns_1_i_2017_Argument_0_0_encOffset;
UA_Byte *variablenode_ns_1_i_2017_Argument_0_0_newBody = (UA_Byte *) UA_malloc(variablenode_ns_1_i_2017_Argument_0_0_encOffset);
memcpy(variablenode_ns_1_i_2017_Argument_0_0_newBody, variablenode_ns_1_i_2017_Argument_0_0->content.encoded.body.data, variablenode_ns_1_i_2017_Argument_0_0_encOffset);
UA_Byte *variablenode_ns_1_i_2017_Argument_0_0_oldBody = variablenode_ns_1_i_2017_Argument_0_0->content.encoded.body.data;
variablenode_ns_1_i_2017_Argument_0_0->content.encoded.body.data = variablenode_ns_1_i_2017_Argument_0_0_newBody;
UA_free(variablenode_ns_1_i_2017_Argument_0_0_oldBody);

UA_ExtensionObject variablenode_ns_1_i_2017_variant_DataContents[1];
variablenode_ns_1_i_2017_variant_DataContents[0] = *variablenode_ns_1_i_2017_Argument_0_0;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2017_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2017),
UA_NODEID_NUMERIC(ns[1], 2016),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

UA_free(variablenode_ns_1_i_2017_Argument_0_0_struct.ArrayDimensions);
UA_ExtensionObject_delete(variablenode_ns_1_i_2017_Argument_0_0);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_45_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2017)
);
}

/* State - ns=1;i=2013 */

static UA_StatusCode function_revpi_open62541_IO_methods_46_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_1_i_2013_variant_DataContents =  UA_Boolean_new();
*variablenode_ns_1_i_2013_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2013_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "State");
attr.description = UA_LOCALIZEDTEXT("", "State");
attr.writeMask = 0;
attr.userWriteMask = 0;
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2013),
UA_NODEID_NUMERIC(ns[1], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[1], "State"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_i_2013_variant_DataContents);
return retVal;
}

static UA_StatusCode function_revpi_open62541_IO_methods_46_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2013)
);
}

UA_StatusCode revpi_open62541_IO_methods(UA_Server *server) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
/* Use namespace ids generated by the server */
UA_UInt16 ns[2];
ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
ns[1] = UA_Server_addNamespace(server, "https://cvh-lernfabrik.github.io/UA/");
retVal |= function_revpi_open62541_IO_methods_0_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_1_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_2_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_3_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_4_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_5_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_6_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_7_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_8_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_9_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_10_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_11_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_12_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_13_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_14_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_15_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_16_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_17_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_18_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_19_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_20_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_21_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_22_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_23_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_24_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_25_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_26_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_27_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_28_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_29_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_30_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_31_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_32_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_33_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_34_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_35_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_36_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_37_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_38_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_39_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_40_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_41_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_42_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_43_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_44_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_45_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_46_begin(server, ns);
retVal |= function_revpi_open62541_IO_methods_46_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_45_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_44_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_43_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_42_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_41_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_40_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_39_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_38_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_37_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_36_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_35_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_34_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_33_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_32_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_31_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_30_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_29_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_28_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_27_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_26_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_25_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_24_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_23_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_22_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_21_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_20_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_19_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_18_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_17_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_16_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_15_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_14_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_13_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_12_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_11_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_10_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_9_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_8_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_7_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_6_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_5_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_4_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_3_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_2_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_1_finish(server, ns);
retVal |= function_revpi_open62541_IO_methods_0_finish(server, ns);
return retVal;
}
