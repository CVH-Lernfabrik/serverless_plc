#include <stdbool.h>
#include "open62541.h"
#include "methods.h"

extern UA_StatusCode
getIndicatorStateCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {

UA_BrowseDescription browseForProperty;
//browseForProperty.


//UA_Server_read

    char *outputPin = "O_1";

    UA_Server_readValue(server, UA_NODEID_STRING(2, outputPin), output);

    return UA_STATUSCODE_GOOD;
}

extern UA_StatusCode
setIndicatorStateCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {

    char *outputPin = "O_1";

    UA_Server_writeValue(server, UA_NODEID_STRING(2, outputPin), *input);

    return UA_STATUSCODE_GOOD;
}

extern UA_StatusCode
stackMagazineMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {
    char *sensorExtended = "I_12", *sensorRetracted = "I_10", *sensorStatus = "I_14",
            *valveExtend = "O_10",    *valveRetract = "O_12";

    bool verbose = true, tr = true, fa = false;

    UA_Boolean currentPosition, targetPosition; //true = extended
    UA_Variant value;
    UA_NodeId currentNodeId;

    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "DataType %i - should be %i or %i", input->type, UA_TYPES[UA_TYPES_BOOLEAN].typeId, UA_TYPES_BOOLEAN);
    //if (*((int *)input->type) == UA_TYPES_BOOLEAN){
      targetPosition = (UA_Boolean)*((int *)input->data);
    //}else{
    //  return UA_STATUSCODE_BADTYPEMISMATCH;
    //}

    if(PI_readSingleIO(sensorExtended, NULL, verbose) && !PI_readSingleIO(sensorRetracted, NULL, verbose)){
      currentPosition = true;
    }else if(!PI_readSingleIO(sensorExtended, NULL, verbose) && PI_readSingleIO(sensorRetracted, NULL, verbose)){
      currentPosition = false;
    }else{
      return UA_STATUSCODE_BADDEVICEFAILURE;
    }
    if ((currentPosition != targetPosition) && PI_readSingleIO(sensorStatus, NULL, verbose)){
      if(targetPosition == true){
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Extend Cylinder");

        UA_Variant_setScalar(&value, &fa, &UA_TYPES[UA_TYPES_BOOLEAN]);
        currentNodeId = UA_NODEID_STRING(1, valveRetract);
        UA_Server_writeValue(server, currentNodeId, value);

        UA_Variant_setScalar(&value, &tr, &UA_TYPES[UA_TYPES_BOOLEAN]);
        currentNodeId = UA_NODEID_STRING(1, valveExtend);
        UA_Server_writeValue(server, currentNodeId, value);

        currentPosition = true;
      }else{
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Retract Cylinder");
        currentPosition = false;

        UA_Variant_setScalar(&value, &fa, &UA_TYPES[UA_TYPES_BOOLEAN]);
        currentNodeId = UA_NODEID_STRING(1, valveExtend);
        UA_Server_writeValue(server, currentNodeId, value);

        UA_Variant_setScalar(&value, &tr, &UA_TYPES[UA_TYPES_BOOLEAN]);
        currentNodeId = UA_NODEID_STRING(1, valveRetract);
        UA_Server_writeValue(server, currentNodeId, value);
      }
    }

    UA_Variant_setScalarCopy(output, &currentPosition, &UA_TYPES[UA_TYPES_BOOLEAN]);
    return UA_STATUSCODE_GOOD;
}

extern UA_StatusCode
ejectorMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {
    char *sensorInduction = "I_4", *sensorPresence = "I_8",
         *sensorRetracted = "I_2",   *sensorStatus = "I_6",
             *valveExtend = "O_2",   *valveRetract = "O_4";

    bool verbose = true, tr = true, fa = false;

    UA_Boolean currentPosition, targetPosition; //true = extended
    UA_Variant value;
    UA_NodeId currentNodeId;

    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "DataType %i - should be %i or %i", input->type, UA_TYPES[UA_TYPES_BOOLEAN].typeId, UA_TYPES_BOOLEAN);
    //if (*((int *)input->type) == UA_TYPES_BOOLEAN){
      targetPosition = (UA_Boolean)*((int *)input->data);
    //}else{
    //  return UA_STATUSCODE_BADTYPEMISMATCH;
    //}

    currentPosition = PI_readSingleIO(sensorRetracted, NULL, verbose);

    if ((currentPosition != targetPosition)){
      if(targetPosition == true){
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Extend Cylinder");

        UA_Variant_setScalar(&value, &fa, &UA_TYPES[UA_TYPES_BOOLEAN]);
        currentNodeId = UA_NODEID_STRING(1, valveRetract);
        UA_Server_writeValue(server, currentNodeId, value);

        UA_Variant_setScalar(&value, &tr, &UA_TYPES[UA_TYPES_BOOLEAN]);
        currentNodeId = UA_NODEID_STRING(1, valveExtend);
        UA_Server_writeValue(server, currentNodeId, value);

        currentPosition = true;
      }else{
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Retract Cylinder");
        currentPosition = false;

        UA_Variant_setScalar(&value, &fa, &UA_TYPES[UA_TYPES_BOOLEAN]);
        currentNodeId = UA_NODEID_STRING(1, valveExtend);
        UA_Server_writeValue(server, currentNodeId, value);

        UA_Variant_setScalar(&value, &tr, &UA_TYPES[UA_TYPES_BOOLEAN]);
        currentNodeId = UA_NODEID_STRING(1, valveRetract);
        UA_Server_writeValue(server, currentNodeId, value);
      }
    }

    UA_Variant_setScalarCopy(output, &currentPosition, &UA_TYPES[UA_TYPES_BOOLEAN]);
    return UA_STATUSCODE_GOOD;
}

static void
addStackMagazineMethod(UA_Server *server) {
    UA_Argument inputArgument;
    UA_Argument_init(&inputArgument);
    inputArgument.description = UA_LOCALIZEDTEXT("en-US", "Target position: 1/TRUE (extended), 0/FALSE (retracted)");
    inputArgument.name = UA_STRING("position");
    inputArgument.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
    inputArgument.valueRank = -1; /* scalar */

    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "Actual position: 1/TRUE (extended), 0/FALSE (retracted)");
    outputArgument.name = UA_STRING("position");
    outputArgument.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
    outputArgument.valueRank = -1; /* scalar */

    UA_MethodAttributes helloAttr = UA_MethodAttributes_default;
    helloAttr.description = UA_LOCALIZEDTEXT("en-US","Supplies a part from the Magazine");
    helloAttr.displayName = UA_LOCALIZEDTEXT("en-US","Stack Magazine");
    helloAttr.executable = true;
    helloAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_STRING(1,"stackMagazine"),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASORDEREDCOMPONENT),
                            UA_QUALIFIEDNAME(1, "stack magazine"),
                            helloAttr, &stackMagazineMethodCallback,
                            1, &inputArgument, 1, &outputArgument, NULL, NULL);
}

static void
addEjectorMethod(UA_Server *server) {
    UA_Argument inputArgument;
    UA_Argument_init(&inputArgument);
    inputArgument.description = UA_LOCALIZEDTEXT("en-US", "Target position: 1/TRUE (extended), 0/FALSE (retracted)");
    inputArgument.name = UA_STRING("position");
    inputArgument.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
    inputArgument.valueRank = -1; /* scalar */

    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "Actual position: 1/TRUE (extended), 0/FALSE (retracted)");
    outputArgument.name = UA_STRING("position");
    outputArgument.dataType = UA_TYPES[UA_TYPES_BOOLEAN].typeId;
    outputArgument.valueRank = -1; /* scalar */

    UA_MethodAttributes helloAttr = UA_MethodAttributes_default;
    helloAttr.description = UA_LOCALIZEDTEXT("en-US","Ejects a Part");
    helloAttr.displayName = UA_LOCALIZEDTEXT("en-US","Ejector");
    helloAttr.executable = true;
    helloAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_STRING(1,"ejector"),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASORDEREDCOMPONENT),
                            UA_QUALIFIEDNAME(1, "ejector"),
                            helloAttr, &ejectorMethodCallback,
                            1, &inputArgument, 1, &outputArgument, NULL, NULL);
}
