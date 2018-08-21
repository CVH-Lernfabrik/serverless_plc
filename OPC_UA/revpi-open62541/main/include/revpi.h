#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

char *getReadError(int error);
char *getWriteError(int error);
extern bool PI_readSingleIO(char *pszVariableName, bool *bit, bool verbose);
extern void PI_writeSingleIO(char *pszVariableName, bool *bit, bool verbose);

#ifdef __cplusplus
}
#endif
