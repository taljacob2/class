#include "AnonymousPointer.h"

TYPEOF_ANONYMOUS_POINTER *getAnonymousPointerByIndex(void *self, size_t index) {
    return ((TYPEOF_ANONYMOUS_POINTER *) self) + index;
}
