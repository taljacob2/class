#ifndef CONCAT_H
#define CONCAT_H

#include "Quote.h"
#include <stdlib.h>
#include <string.h>

/*
 * See More About Preventing A Macro-Expanding With This Trick:
 * https://stackoverflow.com/a/11694231/14427765
 */

#define __CONCAT_NOT_EXPANDED__(A, B) A##B
#define CONCAT(A, B)                  __CONCAT_NOT_EXPANDED__(A, B)
#define CONCAT_SURROUND(middle, whatToSurround) \
    CONCAT(whatToSurround, CONCAT(middle, whatToSurround))

#define CREATE_LOCAL_CONST_STRING_VAR_FROM_CONCAT_MACRO_TEXT( \
        _stringVarName_, FIRST_MACRO_TEXT, SECOND_MACRO_TEXT) \
    CREATE_LOCAL_CONST_STRING_VAR_FROM_MACRO_TEXT(            \
            _stringVarName_, CONCAT(FIRST_MACRO_TEXT, SECOND_MACRO_TEXT))


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
const char *concat(const char *firstString, const char *secondString);

void concatToPreAllocatedString(char *destination, const char *firstString,
                                const char *secondString);

#endif /* CONCAT_H */
