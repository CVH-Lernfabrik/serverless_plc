#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "piControlIf.h"
#include "piControl.h"

#include "revpi.h"

char *getReadError(int error)
{
    static char *ReadError[] = {
	"Cannot connect to control process",
	"Offset seek error",
	"Cannot read from control process",
	"Unknown error"
    };
    switch (error) {
    case -1:
	return ReadError[0];
	break;
    case -2:
	return ReadError[1];
	break;
    case -3:
	return ReadError[2];
	break;
    default:
	return ReadError[3];
	break;
    }
}

char *getWriteError(int error)
{
    static char *WriteError[] = {
	"Cannot connect to control process",
	"Offset seek error",
	"Cannot write to control process",
	"Unknown error"
    };
    switch (error) {
    case -1:
	return WriteError[0];
	break;
    case -2:
	return WriteError[1];
	break;
    case -3:
	return WriteError[2];
	break;
    default:
	return WriteError[3];
	break;
    }
}

extern bool PI_readSingleIO(char *pszVariableName, bool *bit, bool verbose)
{
	int rc;
	SPIVariable sPiVariable;		// Struct, declared in l157 of piControl.h - psten, 2018-05-15
	SPIValue sPIValue;					// Struct, declared in l164 of piControl.h - psten, 2018-05-15

	strncpy(sPiVariable.strVarName, pszVariableName, sizeof(sPiVariable.strVarName));
	rc = piControlGetVariableInfo(&sPiVariable);
	if (rc < 0) {
		printf("Cannot find variable '%s'\n", pszVariableName);
		return false;
	}

  sPIValue.i16uAddress = sPiVariable.i16uAddress;
  sPIValue.i8uBit = sPiVariable.i8uBit;

				rc = piControlGetBitValue(&sPIValue);	// declared in l271 of PiControlIf.c - psten, 2018-05-15
			if (rc < 0)
				printf("Get bit error\n");
      else if (bit != NULL) {
        *bit = sPIValue.i8uValue;
        if (verbose)
          printf("Read bit %d on byte at offset %d. Value %d\n", sPIValue.i8uBit, sPIValue.i16uAddress, sPIValue.i8uValue);
      }
      return sPIValue.i8uValue;
}


/***********************************************************************************/
/*!
 * @brief Write variable value
 *
 * Write a value to a variable.
 *
 * @param[in]   Variable name
 * @param[in]   Value to write
 * @param[in]   Enable additional logs
 *
 ************************************************************************************/
extern void PI_writeSingleIO(char *pszVariableName, bool *bit, bool verbose)
{
	int rc;
	SPIVariable sPiVariable;
	SPIValue sPIValue;

	strncpy(sPiVariable.strVarName, pszVariableName, sizeof(sPiVariable.strVarName));
	rc = piControlGetVariableInfo(&sPiVariable);
	if (rc < 0) {
		printf("Cannot find variable '%s'\n", pszVariableName);
		return;
	}

		sPIValue.i16uAddress = sPiVariable.i16uAddress;
		sPIValue.i8uBit = sPiVariable.i8uBit;
		sPIValue.i8uValue = *bit;
		rc = piControlSetBitValue(&sPIValue);
		if (rc < 0)
			printf("Set bit error %s\n", getWriteError(rc));
		else if (verbose)
			printf("Set bit %d on byte at offset %d. Value %d\n", sPIValue.i8uBit, sPIValue.i16uAddress,
			       sPIValue.i8uValue);
}
