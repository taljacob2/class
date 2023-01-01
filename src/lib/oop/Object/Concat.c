#include "Concat.h"

const char *concat(const char *firstString, const char *secondString) {
    const size_t sizeOfFirstString = strlen(firstString) + (sizeof(char) * 1);
    char *returnValue = malloc(strlen(firstString) + strlen(secondString) +
                               (sizeof(char) * 1));
    memcpy(returnValue, firstString, sizeOfFirstString);
    strcat(returnValue, secondString);

    return returnValue;
}