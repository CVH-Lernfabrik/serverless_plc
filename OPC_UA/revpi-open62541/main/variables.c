#include <stdbool.h>
#include "open62541.h"
#include "variables.h"
#include "methods.h"
#include "util.h"
//#include "dictionary.h"

//Dictionary *stateToValue = dict_new();

extern void
updateVariable(UA_Server *server, char *pszVariableName, bool verbose) {
    UA_Boolean bit;
    UA_Variant value;

    PI_readSingleIO(pszVariableName, &bit, verbose);
    UA_Variant_setScalar(&value, &bit, &UA_TYPES[UA_TYPES_BOOLEAN]);
    UA_NodeId currentNodeId = UA_NODEID_STRING(1, pszVariableName);
    UA_Server_writeValue(server, currentNodeId, value);
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

                  PI_readSingleIO(convert, &bit, true);
                  UA_Variant_setScalar(&value, &bit, &UA_TYPES[UA_TYPES_BOOLEAN]);

                  // Der folgende Teil muss auch anders realisierbar sein, sonst wird bei jedem Lesezugriff auf eine Variable selbige nochmal geschrieben!
                  // Zunächst überprüfen, ob dies auch für Datasources der Fall ist.
                  UA_NodeId currentNodeId = UA_NODEID_STRING(1, convert);
                  UA_Server_writeValue(server, currentNodeId, value);

                  UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "beforeReadVariable %s: value  %i", convert, bit);
 }

 extern void
 afterWriteVariable(UA_Server *server,
                const UA_NodeId *sessionId, void *sessionContext,
                const UA_NodeId *nodeId, void *nodeContext,
                const UA_NumericRange *range, const UA_DataValue *data) {

                  UA_LOG_DEBUG(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "afterWriteVariable vor copy");

                  UA_String uaString;
                  UA_String_copy(&nodeId->identifier.string, &uaString);

                  char* convert = (char*)UA_malloc(sizeof(char)*uaString.length+1);
                  memcpy(convert, uaString.data, uaString.length);
                  convert[uaString.length] = '\0';

                  UA_LOG_DEBUG(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
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

                  UA_LOG_DEBUG(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
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

                   UA_StatusCode retval = UA_STATUSCODE_GOOD;
                   UA_NodeId *nameNodeId = UA_malloc(sizeof(UA_NodeId)); //Ohne Malloc rennt findChildByBrowsename in den SegFault!
                   UA_QualifiedName nameQN = UA_QUALIFIEDNAME(1, "Name");


                   retval = findSiblingByBrowsename(server, nodeId, &nameQN, nameNodeId);

                   UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                    "readDataSourceVariable: findSiblingByBrowsename returned StatusCode %s - node id: %i", UA_StatusCode_name(retval), nameNodeId->identifier.numeric);


                   UA_Variant nameVar;
                   retval = UA_Server_readValue(server, *nameNodeId, &nameVar);
                   UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "readDataSourceVariable: Name of IO is %s", String_fromUA_String(nameVar.data));

                   UA_Variant value;
                   UA_Boolean bit;

                   PI_readSingleIO(String_fromUA_String(nameVar.data), &bit, true);

     UA_Variant_setScalarCopy(&dataValue->value, &bit,
                              &UA_TYPES[UA_TYPES_BOOLEAN]);
     dataValue->hasValue = true;

     UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                  "readDataSourceVariable %s: value  %i", convert, bit);
     return retval;
 }

 extern UA_StatusCode
 writeDataSourceVariable(UA_Server *server,
                  const UA_NodeId *sessionId, void *sessionContext,
                  const UA_NodeId *nodeId, void *nodeContext,
                  const UA_NumericRange *range, const UA_DataValue *dataValue) {


                   UA_StatusCode retval = UA_STATUSCODE_GOOD;
                   UA_NodeId *nameNodeId = UA_malloc(sizeof(UA_NodeId)); //Ohne Malloc rennt findChildByBrowsename in den SegFault!
                   UA_QualifiedName nameQN = UA_QUALIFIEDNAME(1, "Name");


                   retval = findSiblingByBrowsename(server, nodeId, &nameQN, nameNodeId);

                  UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                      "writeDataSourceVariable: findSiblingByBrowsename returned StatusCode %s - node id: %i", UA_StatusCode_name(retval), nameNodeId->identifier.numeric);


                   UA_Variant nameVar;
                   retval = UA_Server_readValue(server, *nameNodeId, &nameVar);
                   UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "writeDataSource variable: Name of IO is %s", String_fromUA_String(nameVar.data));




                  UA_Boolean bit;

                  // funktioniert überhaupt nicht wie erwartet, Typabfrage scheint fast unmöglich zu sein
                  /*UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                              "type is 0x%08x / 0x%08x, should be  0x%08x / 0x%08x, typematch result: %01x size of value.data %d, size should be %d value is 0x%08x",
                               *dataValue->value.type, dataValue->value.type, UA_TYPES[UA_TYPES_BOOLEAN], &UA_TYPES[UA_TYPES_BOOLEAN],
                               UA_Variant_hasScalarType(&dataValue->value, &UA_TYPES[UA_TYPES_BOOLEAN]),
                               sizeof(*dataValue->value.data), sizeof(UA_Boolean), dataValue->value.data);
                               */
                  //if (sizeof(*dataValue->value.data) == sizeof(UA_Boolean))
                    retval = UA_Boolean_copy(dataValue->value.data, &bit);



                  PI_writeSingleIO(String_fromUA_String(nameVar.data), &bit, false);

                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                            "writeDataSourceVariable %s: value  %i", String_fromUA_String(nameVar.data) ,bit);
                free(nameNodeId);

    return retval;
 }

 extern UA_StatusCode
 writeReadonlyDataSourceVariable(UA_Server *server,
                  const UA_NodeId *sessionId, void *sessionContext,
                  const UA_NodeId *nodeId, void *nodeContext,
                  const UA_NumericRange *range, const UA_DataValue *dataValue) {

    #if UA_LOGLEVEL <= 200
        UA_String uaString;
        UA_String_copy(&nodeId->identifier.string, &uaString);

        char* convert = (char*)UA_malloc(sizeof(char)*uaString.length+1);
        memcpy(convert, uaString.data, uaString.length);
        convert[uaString.length] = '\0';

        UA_LOG_DEBUG(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
          "writeReadonlyDataSourceVariable %s - variable is readonly!",convert);
    #endif
    return UA_STATUSCODE_BADNOTWRITABLE;
 }

 extern UA_StatusCode
 linkDataSourceVariable(UA_Server *server, UA_NodeId nodeId) {
     bool readonly = false;
     UA_DataSource dataSourceVariable;
     UA_StatusCode rc;

     /*
     UA_VariableAttributes attr = UA_VariableAttributes_default;
     attr.displayName = UA_LOCALIZEDTEXT("en-US", pszVariableName);
     attr.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
     attr.accessLevel = UA_ACCESSLEVELMASK_READ;
     if (!readonly)
       attr.accessLevel |= UA_ACCESSLEVELMASK_WRITE;
     */

     //getUserAccessLevel(server, const UA_Session *session, const UA_VariableNode *node)

     dataSourceVariable.read = readDataSourceVariable;
     if (!readonly)
        dataSourceVariable.write = writeDataSourceVariable;
     else
        dataSourceVariable.write = writeReadonlyDataSourceVariable;

     return UA_Server_setVariableNode_dataSource(server, nodeId, dataSourceVariable);
 }

 extern UA_StatusCode
 ioReadCallback(UA_Server *server,
                 const UA_NodeId *sessionId, void *sessionContext,
                 const UA_NodeId *nodeId, void *nodeContext,
                 UA_Boolean sourceTimeStamp, const UA_NumericRange *range,
                 UA_DataValue *dataValue) {

                   UA_StatusCode retval = UA_STATUSCODE_GOOD;
                   UA_NodeId nameNodeId = UA_NODEID_NUMERIC(1, 2199);

                   retval = UA_Server_readValue(server, nameNodeId, &dataValue->value);

    return retval;
 }

 extern UA_StatusCode
 ioWriteCallback(UA_Server *server,
                  const UA_NodeId *sessionId, void *sessionContext,
                  const UA_NodeId *nodeId, void *nodeContext,
                  const UA_NumericRange *range, const UA_DataValue *dataValue) {

                  //return UA_Server_writeValue(server, dict_get(stateToValue, *nodeId), dataValue->value);
 }

extern UA_StatusCode
linkStateWithIO(UA_Server *server, UA_NodeId nodeId) {
    bool readonly = false;
    UA_DataSource dataSourceVariable;
    UA_StatusCode rc;

    /*
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    attr.displayName = UA_LOCALIZEDTEXT("en-US", pszVariableName);
    attr.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
    attr.accessLevel = UA_ACCESSLEVELMASK_READ;
    if (!readonly)
      attr.accessLevel |= UA_ACCESSLEVELMASK_WRITE;
    */

    //getUserAccessLevel(server, const UA_Session *session, const UA_VariableNode *node)

    dataSourceVariable.read = ioReadCallback;
    if (!readonly)
       dataSourceVariable.write = ioWriteCallback;
    else
       dataSourceVariable.write = writeReadonlyDataSourceVariable;

    return UA_Server_setVariableNode_dataSource(server, nodeId, dataSourceVariable);
}
