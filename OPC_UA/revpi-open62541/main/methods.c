#include <stdbool.h>
#include <string.h>
#include "open62541.h"
#include "util.h"
#include "methods.h"



extern UA_StatusCode
universalSetGetCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {

    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    UA_QualifiedName *methodQN = UA_malloc(sizeof(UA_QualifiedName));
    UA_QualifiedName valueQN;
    retval |= UA_Server_readBrowseName(server, *methodId, methodQN);
    if (retval != UA_STATUSCODE_GOOD)
      return retval;


    char *methodName = String_fromUA_String(&methodQN->name);
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "readBrowseName returned: %s, methodName: %s", UA_StatusCode_name(retval), methodName);

    bool writeValue = false;

    if (strlen(methodName) > 5 && methodName[0] == 'w' && methodName[1] == 'r'
                               && methodName[2] == 'i' && methodName[3] == 't' && methodName[4] == 'e') {
      valueQN = UA_QUALIFIEDNAME(1, &methodName[5]);
      writeValue = true;
    }
    else if (strlen(methodName) > 4 && methodName[0] == 'r' && methodName[1] == 'e'
                                    && methodName[2] == 'a' && methodName[3] == 'd') {
      valueQN = UA_QUALIFIEDNAME(1, &methodName[4]);
      writeValue = false;
    }
    else if (strlen(methodName) > 3 && methodName[0] == 's' && methodName[1] == 'e'
                                    && methodName[2] == 't') {
      valueQN = UA_QUALIFIEDNAME(1, &methodName[3]);
      writeValue = true;
    }

    else if (strlen(methodName) > 3 && methodName[0] == 'g' && methodName[1] == 'e'
                                    && methodName[2] == 't') {
      valueQN = UA_QUALIFIEDNAME(1, &methodName[3]);
      writeValue = false;
    }

    UA_NodeId *valueNodeId = UA_malloc(sizeof(UA_NodeId)); //Ohne Malloc rennt findChildByBrowsename in den SegFault!
    retval |= findChildByBrowsename(server, objectId, &valueQN, valueNodeId);

    if (retval != UA_STATUSCODE_GOOD)
      return retval;

    if (writeValue)
      retval |= UA_Server_writeValue(server, *valueNodeId, *input);
    else
      retval |= UA_Server_readValue(server, *valueNodeId, output);

    free(methodQN);
    free(valueNodeId);
    return retval;
}

extern UA_StatusCode
readValueCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {

    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    UA_NodeId *valueNodeId = UA_malloc(sizeof(UA_NodeId)); //Ohne Malloc rennt findChildByBrowsename in den SegFault!
    UA_QualifiedName valueQN = UA_QUALIFIEDNAME(1, "Value");

    retval |= findChildByBrowsename(server, objectId, &valueQN, valueNodeId);
    retval |= UA_Server_readValue(server, *valueNodeId, output);

    free(valueNodeId);
    return retval;
}

extern UA_StatusCode
writeValueCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {

    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    UA_NodeId *valueNodeId = UA_malloc(sizeof(UA_NodeId)); //Ohne Malloc rennt findChildByBrowsename in den SegFault!
    UA_QualifiedName valueQN = UA_QUALIFIEDNAME(1, "Value");

    retval |= findChildByBrowsename(server, objectId, &valueQN, valueNodeId);
    retval |= UA_Server_writeValue(server, *valueNodeId, *input);

    free(valueNodeId);
    return retval;
}

extern UA_StatusCode
setStateCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {

    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    UA_NodeId *valueNodeId = UA_malloc(sizeof(UA_NodeId)); //Ohne Malloc rennt findChildByBrowsename in den SegFault!
    UA_QualifiedName valueQN = UA_QUALIFIEDNAME(1, "State");

    retval |= findChildByBrowsename(server, objectId, &valueQN, valueNodeId);
    retval |= UA_Server_writeValue(server, *valueNodeId, *input);

    free(valueNodeId);
    return retval;
}

extern UA_StatusCode
getStateCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {

    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    UA_NodeId *valueNodeId = UA_malloc(sizeof(UA_NodeId)); //Ohne Malloc rennt findChildByBrowsename in den SegFault!
    UA_QualifiedName valueQN = UA_QUALIFIEDNAME(1, "State");

    retval |= findChildByBrowsename(server, objectId, &valueQN, valueNodeId);
    retval |= UA_Server_readValue(server, *valueNodeId, output);

    free(valueNodeId);
    return retval;
}
