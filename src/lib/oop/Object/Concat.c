#define _CRT_SECURE_NO_WARNINGS

#include "Concat.h"

const char *concat(const char *firstString, const char *secondString) {
    const size_t sizeOfFirstString = strlen(firstString) + (sizeof(char) * 1);
    char *returnValue = malloc(strlen(firstString) + strlen(secondString) +
                               (sizeof(char) * 1));
    memcpy(returnValue, firstString, sizeOfFirstString);
    strcat(returnValue, secondString);

    return returnValue;
}

void concatToPreAllocatedString(char *destination, const char *firstString,
                                const char *secondString) {
    const char *result = concat(firstString, secondString);
    strcpy(destination, result);
    free((void *) result);
}