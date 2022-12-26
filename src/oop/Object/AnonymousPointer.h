#ifndef ANONYMOUSPOINTER_H
#define ANONYMOUSPOINTER_H

#include <limits.h>

/*
 * Read more here:
 *
 * https://stackoverflow.com/a/62749804/14427765
 * https://www.geeksforgeeks.org/bit-fields-c/
 */
#define ANONYMOUS_POINTER size_t : (sizeof(size_t) * CHAR_BIT)

#endif //ANONYMOUSPOINTER_H
