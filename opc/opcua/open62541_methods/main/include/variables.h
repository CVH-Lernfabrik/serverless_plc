#include <stdbool.h>
#include "open62541.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void updateVariable(UA_Server *server, char *pszVariableName, bool verbose);

extern void addVariable(UA_Server *server, char *pszVariableName, bool readonly, bool verbose);

extern void beforeReadVariable(UA_Server *server,
                   const UA_NodeId *sessionId, void *sessionContext,
                   const UA_NodeId *nodeId, void *nodeContext,
                   const UA_NumericRange *range, const UA_DataValue *data);

extern void afterWriteVariable(UA_Server *server,
                   const UA_NodeId *sessionId, void *sessionContext,
                   const UA_NodeId *nodeId, void *nodeContext,
                   const UA_NumericRange *range, const UA_DataValue *data);

extern void afterWriteReadonlyVariable(UA_Server *server,
                   const UA_NodeId *sessionId, void *sessionContext,
                   const UA_NodeId *nodeId, void *nodeContext,
                   const UA_NumericRange *range, const UA_DataValue *data);

extern void addValueCallbackToVariable(UA_Server *server,
                   char *pszVariableName, bool readonly, bool verbose);

extern UA_StatusCode readDataSourceVariable(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               UA_Boolean sourceTimeStamp, const UA_NumericRange *range,
               UA_DataValue *dataValue);

extern UA_StatusCode writeDataSourceVariable(UA_Server *server,
                const UA_NodeId *sessionId, void *sessionContext,
                const UA_NodeId *nodeId, void *nodeContext,
                const UA_NumericRange *range, const UA_DataValue *dataValue);

extern UA_StatusCode writeReadonlyDataSourceVariable(UA_Server *server,
                  const UA_NodeId *sessionId, void *sessionContext,
                  const UA_NodeId *nodeId, void *nodeContext,
                  const UA_NumericRange *range, const UA_DataValue *dataValue);

extern void addDataSourceVariable(UA_Server *server, char *pszVariableName, bool readonly, bool verbose);

extern UA_StatusCode linkStateWithIO(UA_Server *server, UA_NodeId nodeId);

#ifdef __cplusplus
}
#endif
