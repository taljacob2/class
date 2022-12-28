#ifndef CONCAT_H
#define CONCAT_H

#include <stdlib.h>
#include <string.h>

#define __CONCAT_NOT_EXPANDED__(A, B) A##B
#define CONCAT(A, B)                  __CONCAT_NOT_EXPANDED__(A, B)
#define CONCAT_SURROUND(middle, whatToSurround) \
    CONCAT(whatToSurround, CONCAT(middle, whatToSurround))


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

#endif //CONCAT_H
