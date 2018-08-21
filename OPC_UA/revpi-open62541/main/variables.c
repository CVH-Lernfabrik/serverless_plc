#include <stdbool.h>
#include "open62541.h"
#include "variables.h"

extern void
updateVariable(UA_Server *server, char *pszVariableName, bool verbose) {
    UA_Boolean bit;
    UA_Variant value;

    PI_readSingleIO(pszVariableName, &bit, verbose);
    UA_Variant_setScalar(&value, &bit, &UA_TYPES[UA_TYPES_BOOLEAN]);
    UA_NodeId currentNodeId = UA_NODEID_STRING(1, pszVariableName);
    UA_Server_writeValue(server, currentNodeId, value);
}

extern void
addVariable(UA_Server *server, char *pszVariableName, bool readonly, bool verbose) {
    UA_Boolean bit = UA_FALSE;
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    attr.displayName = UA_LOCALIZEDTEXT("en-US", pszVariableName);
    attr.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
    attr.accessLevel = UA_ACCESSLEVELMASK_READ;
    if (!readonly)
      attr.accessLevel |= UA_ACCESSLEVELMASK_WRITE;
    UA_Variant_setScalar(&attr.value, &bit, &UA_TYPES[UA_TYPES_BOOLEAN]);

    UA_NodeId currentNodeId = UA_NODEID_STRING(1, pszVariableName);
    UA_QualifiedName currentName = UA_QUALIFIEDNAME(1, pszVariableName);
    UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER);
    UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES);
    UA_NodeId variableTypeNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE);
    UA_Server_addVariableNode(server, currentNodeId, parentNodeId,
                              parentReferenceNodeId, currentName,
                              variableTypeNodeId, attr, NULL, NULL);

    updateVariable(server, pszVariableName, verbose);
}

/**
 * Variable Value Callback
 * ^^^^^^^^^^^^^^^^^^^^^^^
 *
 * When a value changes continuously, such as the system time, updating the
 * value in a tight loop would take up a lot of resources. Value callbacks allow
 * to synchronize a variable value with an external representation. They attach
 * callbacks to the variable that are executed before every read and after every
 * write operation. */

 extern void
 beforeReadVariable(UA_Server *server,
                const UA_NodeId *sessionId, void *sessionContext,
                const UA_NodeId *nodeId, void *nodeContext,
                const UA_NumericRange *range, const UA_DataValue *data) {

                  UA_Boolean bit;
                  UA_Variant value;

                  UA_String uaString;
                  UA_String_copy(&nodeId->identifier.string, &uaString);

                  char* convert = (char*)UA_malloc(sizeof(char)*uaString.length+1);
                  memcpy(convert, uaString.data, uaString.length);
                  convert[uaString.length] = '\0';

                  PI_readSingleIO(convert, &bit, false);
                  UA_Variant_setScalar(&value, &bit, &UA_TYPES[UA_TYPES_BOOLEAN]);

                  // Der folgende Teil muss auch anders realisierbar sein, sonst wird bei jedem Lesezugriff auf eine Variable selbige nochmal geschrieben!
                  // Zunächst überprüfen, ob dies auch für Datasources der Fall ist.
                  UA_NodeId currentNodeId = UA_NODEID_STRING(1, convert);
                  UA_Server_writeValue(server, currentNodeId, value);

                  //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                  //            "beforeReadVariable %s: value  %i", convert, bit);
 }

 extern void
 afterWriteVariable(UA_Server *server,
                const UA_NodeId *sessionId, void *sessionContext,
                const UA_NodeId *nodeId, void *nodeContext,
                const UA_NumericRange *range, const UA_DataValue *data) {

                  UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "afterWriteVariable vor copy");

                  UA_String uaString;
                  UA_String_copy(&nodeId->identifier.string, &uaString);

                  char* convert = (char*)UA_malloc(sizeof(char)*uaString.length+1);
                  memcpy(convert, uaString.data, uaString.length);
                  convert[uaString.length] = '\0';

                  UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "afterWriteVariable nach copy: %s", convert);

                  UA_Boolean bit;
                  UA_Boolean_copy(*(&data->value.data), &bit);

                  UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "bit value: %i", bit);


                  //Hier gehört unbedingt noch eine Typabfrage bzw. ein try-catch rein, falls Daten in einem unerwarteten Typ übergeben werden!
                  PI_writeSingleIO(convert, &bit, false);

                  UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "afterWriteVariable %s: value  %i",convert,bit);
 }

 extern void
 afterWriteReadonlyVariable(UA_Server *server,
                const UA_NodeId *sessionId, void *sessionContext,
                const UA_NodeId *nodeId, void *nodeContext,
                const UA_NumericRange *range, const UA_DataValue *data) {

                  UA_String uaString;
                  UA_String_copy(&nodeId->identifier.string, &uaString);

                  char* convert = (char*)UA_malloc(sizeof(char)*uaString.length+1);
                  memcpy(convert, uaString.data, uaString.length);
                  convert[uaString.length] = '\0';

                  UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "Variable %s is readonly",convert);
 }

 extern void
 addValueCallbackToVariable(UA_Server *server, char *pszVariableName, bool readonly, bool verbose) {
     UA_NodeId currentNodeId = UA_NODEID_STRING(1, pszVariableName);
     UA_ValueCallback callback ;
     callback.onRead = beforeReadVariable;
     if (readonly)
        callback.onWrite = afterWriteReadonlyVariable;
     else
        callback.onWrite = afterWriteVariable;
     UA_Server_setVariableNode_valueCallback(server, currentNodeId, callback);
 }

/**
 * Variable Data Sources
 * ^^^^^^^^^^^^^^^^^^^^^
 *
 * With value callbacks, the value is still stored in the variable node.
 * So-called data sources go one step further. The server redirects every read
 * and write request to a callback function. Upon reading, the callback provides
 * copy of the current value. Internally, the data source needs to implement its
 * own memory management. */

 extern UA_StatusCode
 readDataSourceVariable(UA_Server *server,
                 const UA_NodeId *sessionId, void *sessionContext,
                 const UA_NodeId *nodeId, void *nodeContext,
                 UA_Boolean sourceTimeStamp, const UA_NumericRange *range,
                 UA_DataValue *dataValue) {

                   UA_String uaString;
                   UA_String_copy(&nodeId->identifier.string, &uaString);

                   char* convert = (char*)UA_malloc(sizeof(char)*uaString.length+1);
                   memcpy(convert, uaString.data, uaString.length);
                   convert[uaString.length] = '\0';

                   UA_Boolean bit;
                   UA_Variant value;

                   PI_readSingleIO(convert, &bit, false);

     UA_Variant_setScalarCopy(&dataValue->value, &bit,
                              &UA_TYPES[UA_TYPES_BOOLEAN]);
     dataValue->hasValue = true;

     //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
     //             "readDataSourceVariable %s: value  %i", convert, bit);
     return UA_STATUSCODE_GOOD;
 }

 extern UA_StatusCode
 writeDataSourceVariable(UA_Server *server,
                  const UA_NodeId *sessionId, void *sessionContext,
                  const UA_NodeId *nodeId, void *nodeContext,
                  const UA_NumericRange *range, const UA_DataValue *dataValue) {

                  UA_String uaString;
                  UA_String_copy(&nodeId->identifier.string, &uaString);

                  char* convert = (char*)UA_malloc(sizeof(char)*uaString.length+1);
                  memcpy(convert, uaString.data, uaString.length);
                  convert[uaString.length] = '\0';

                  UA_Boolean bit;

                  // funktioniert überhaupt nicht wie erwartet, Typabfrage scheint fast unmöglich zu sein
                  /*UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "type is 0x%08x / 0x%08x, should be  0x%08x / 0x%08x, typematch result: %01x size of value.data %d, size should be %d value is 0x%08x",
                               *dataValue->value.type, dataValue->value.type, UA_TYPES[UA_TYPES_BOOLEAN], &UA_TYPES[UA_TYPES_BOOLEAN],
                               UA_Variant_hasScalarType(&dataValue->value, &UA_TYPES[UA_TYPES_BOOLEAN]),
                               sizeof(*dataValue->value.data), sizeof(UA_Boolean), dataValue->value.data);
                               */
                  //if (sizeof(*dataValue->value.data) == sizeof(UA_Boolean))
                    UA_Boolean_copy(dataValue->value.data, &bit);



                  PI_writeSingleIO(convert, &bit, false);

    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "writeDataSourceVariable %s: value  %i",convert ,bit);

    return UA_STATUSCODE_GOOD;
 }

 extern UA_StatusCode
 writeReadonlyDataSourceVariable(UA_Server *server,
                  const UA_NodeId *sessionId, void *sessionContext,
                  const UA_NodeId *nodeId, void *nodeContext,
                  const UA_NumericRange *range, const UA_DataValue *dataValue) {

                  UA_String uaString;
                  UA_String_copy(&nodeId->identifier.string, &uaString);

                  char* convert = (char*)UA_malloc(sizeof(char)*uaString.length+1);
                  memcpy(convert, uaString.data, uaString.length);
                  convert[uaString.length] = '\0';

                  //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                  //            "writeReadonlyDataSourceVariable %s - type is %u / %u, should be  %u \n value is %u",
                  //            convert, dataValue->value.type, *(dataValue->value.type), UA_TYPES_BOOLEAN, dataValue->value.data);


                  UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                    "writeReadonlyDataSourceVariable %s - variable is readonly!",convert);

    return UA_STATUSCODE_GOOD;
 }


 extern void
 addDataSourceVariable(UA_Server *server, char *pszVariableName, bool readonly, bool verbose) {
     UA_VariableAttributes attr = UA_VariableAttributes_default;
     attr.displayName = UA_LOCALIZEDTEXT("en-US", pszVariableName);
     attr.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
     attr.accessLevel = UA_ACCESSLEVELMASK_READ;
     if (!readonly)
       attr.accessLevel |= UA_ACCESSLEVELMASK_WRITE;

     UA_NodeId currentNodeId = UA_NODEID_STRING(1, pszVariableName);
     UA_QualifiedName currentName = UA_QUALIFIEDNAME(1, pszVariableName);
     UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER);
     UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES);
     UA_NodeId variableTypeNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE);

     UA_DataSource dataSourceVariable;
     dataSourceVariable.read = readDataSourceVariable;
     if (!readonly)
        dataSourceVariable.write = writeDataSourceVariable;
     else
        dataSourceVariable.write = writeReadonlyDataSourceVariable;

     UA_Server_addDataSourceVariableNode(server, currentNodeId, parentNodeId,
                                         parentReferenceNodeId, currentName,
                                         variableTypeNodeId, attr,
                                         dataSourceVariable, NULL, NULL);
}

extern void
linkDataSourceVariable(UA_Server *server, int namespace, char *pszVariableName, bool verbose) {
    UA_NodeId currentNodeId = UA_NODEID_STRING(namespace, pszVariableName);
    bool readonly = false;

    UA_DataSource dataSourceVariable;
    UA_StatusCode rc;

    //getUserAccessLevel(server, const UA_Session *session, const UA_VariableNode *node)

    dataSourceVariable.read = readDataSourceVariable;
    if (!readonly)
       dataSourceVariable.write = writeDataSourceVariable;
    else
       dataSourceVariable.write = writeReadonlyDataSourceVariable;

    rc = UA_Server_setVariableNode_dataSource(server, currentNodeId, dataSourceVariable);
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
               "setVariableNode_dataSource returned %s", UA_StatusCode_name(rc));

    /*
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    attr.displayName = UA_LOCALIZEDTEXT("en-US", pszVariableName);
    attr.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
    attr.accessLevel = UA_ACCESSLEVELMASK_READ;
    if (!readonly)
      attr.accessLevel |= UA_ACCESSLEVELMASK_WRITE;
    */
}
