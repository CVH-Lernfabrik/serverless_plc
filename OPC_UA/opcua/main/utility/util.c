// utility.c
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-05-03
//
// Description: Additional utility functions

#include "util.h"

//-------------------------------
// Additional utility functions:
//-------------------------------

/**
 * Parses a given file and returns its contents as UA_ByteString
 *
 * @param   path    path to the file to parse
 * @return          file content
 */
UA_ByteString UA_loadFile(const char *const path)
{
    if (!path || sizeof(path) == 0) {
        UA_LOG_FATAL(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "UA_loadFile: No file specified! Aborting!");
    }

    UA_ByteString fileContents = UA_STRING_NULL;

    // Open the specified file
    FILE *f = fopen(path, "rb");

    if (f) {
        // Get the file length
        fseek(f, 0, SEEK_END);
        fileContents.length = (size_t)ftell(f);

        // Read the content of the file
        fileContents.data = (UA_Byte *) UA_malloc(fileContents.length * sizeof(UA_Byte));
        if(fileContents.data) {
            fseek(f, 0, SEEK_SET);
            size_t read = fread(fileContents.data, sizeof(UA_Byte), fileContents.length, f);
            if(read != fileContents.length)
                UA_ByteString_deleteMembers(&fileContents);
        }
        else {
            fileContents.length = 0;
        }
        fclose(f);
    }

    return fileContents;
}
