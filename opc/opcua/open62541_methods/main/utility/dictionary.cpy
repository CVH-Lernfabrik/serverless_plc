#include "dictionary.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "open62541.h"

Dictionary* dict_new() {
    Dictionary *dictionary = (Dictionary*)malloc(sizeof(Dictionary));
    assert(dictionary != NULL);
    dictionary->head = NULL;
    dictionary->tail = NULL;
    return dictionary;
}

void dict_add(Dictionary *dictionary, const UA_NodeId keyUA, const UA_NodeId valueUA) {
    char *key = String_fromUA_String(keyUA);
    char *value = String_fromUA_String(valueUA);
    if(dict_has(dictionary, key))
            dict_remove(dictionary, key);
    if (dictionary->head != NULL) {
        while(dictionary->tail != NULL) {
            dictionary = dictionary->tail;
        }
        Dictionary *next = dict_new();
        dictionary->tail = next;
        dictionary = dictionary->tail;
    }
    int key_length = strlen(key) + 1;
    int value_length = strlen(value) + 1;
    dictionary->head = (KVPair*)malloc(sizeof(KVPair));
    assert(dictionary->head != NULL);
    dictionary->head->key = (char *)malloc(key_length * sizeof(char));
    dictionary->head->value = (char *)malloc(value_length * sizeof(char));
    assert(dictionary->head->key != NULL);
    strcpy(dictionary->head->key, key);
    strcpy(dictionary->head->value, value);
}

int dict_has(Dictionary *dictionary, const UA_NodeId keyUA) {
    char *key = String_fromUA_String(keyUA);
    if (dictionary->head == NULL)
        return 0;
    while(dictionary != NULL) {
        if(strcmp(dictionary->head->key, key) == 0)
            return 1;
        dictionary = dictionary->tail;
    }
    return 0;
}

UA_NodeId dict_get(Dictionary *dictionary, const UA_NodeId keyUA) {
    char *key = String_fromUA_String(keyUA);
    if (dictionary->head == NULL)
        return UA_NODEID_NULL;
    while(dictionary != NULL) {
        if(strcmp(dictionary->head->key, key) == 0)
            return UA_NodeId_fromString(dictionary->head->value);
        dictionary = dictionary->tail;
    }
    return UA_NODEID_NULL;
}

void dict_remove(Dictionary *dictionary, const UA_NodeId keyUA) {
    char *key = String_fromUA_String(keyUA);
    if (dictionary->head == NULL)
        return;
    Dictionary *previous = NULL;
    while(dictionary != NULL) {
        if(strcmp(dictionary->head->key, key) == 0) {
            if(previous == NULL) {
                free(dictionary->head->key);
                free(dictionary->head->value);
                dictionary->head->key = NULL;
                if (dictionary->tail != NULL) {
                    Dictionary *toremove = dictionary->tail;
                    dictionary->head->key = toremove->head->key;
                    dictionary->tail = toremove->tail;
                    free(toremove->head);
                    free(toremove);
                    return;
                }
            }
            else {
                previous->tail = dictionary->tail;
            }
            free(dictionary->head->key);
            free(dictionary->head->value);
            free(dictionary->head);
            free(dictionary);
            return;
        }
        previous = dictionary;
        dictionary = dictionary->tail;
    }
}

void dict_free(Dictionary *dictionary) {
    if(dictionary == NULL)
        return;
    free(dictionary->head->key);
    free(dictionary->head);
    Dictionary *tail = dictionary->tail;
    free(dictionary);
    dict_free(tail);
}
