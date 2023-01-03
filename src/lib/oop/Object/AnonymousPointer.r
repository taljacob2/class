#ifndef ANONYMOUSPOINTER_H
#define ANONYMOUSPOINTER_H

#include <stddef.h>

/*
 * Read more here:
 *
 * https://stackoverflow.com/a/62749804/14427765
 * https://www.geeksforgeeks.org/bit-fields-c/
 */

#define TYPEOF_ANONYMOUS_POINTER size_t

#define ANONYMOUS_POINTER_AS_FIELD \
    TYPEOF_ANONYMOUS_POINTER:      \
    (sizeof(TYPEOF_ANONYMOUS_POINTER) * CHAR_BIT)


TYPEOF_ANONYMOUS_POINTER *getAnonymousPointerByIndex(void *self, size_t index);

TYPEOF_ANONYMOUS_POINTER getAnonymousPointerValueByIndex(void * self,
                                                         size_t index);

void setAnonymousPointerValueByIndex(void *self, size_t index,
                                     void *valueToSet);

void setAnonymousPointerValue(TYPEOF_ANONYMOUS_POINTER *anonymousPointer,
                              void *                    valueToSet);

#endif //ANONYMOUSPOINTER_H
