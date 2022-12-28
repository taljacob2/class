#include "Concat.h"

/**
 * @attention Remember to `free` the return value.
 *
 * For example:
 *
 * @code
 * int main(void) {
 *   const char *concattedString = concat("Hi", "There");
 *   puts(concattedString);
 *   free((void *)concattedString);
 *   return 0;
 * }
 * @endcode
 */
const char *concat(const char *firstString, const char *secondString) {
    const size_t sizeOfFirstString = strlen(firstString) + (sizeof(char) * 1);
    char *returnValue = malloc(strlen(firstString) + strlen(secondString) +
                               (sizeof(char) * 1));
    memcpy(returnValue, firstString, sizeOfFirstString);
    strcat(returnValue, secondString);

    return returnValue;
}