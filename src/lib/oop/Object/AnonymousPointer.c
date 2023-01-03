#include "AnonymousPointer.r"

TYPEOF_ANONYMOUS_POINTER *getAnonymousPointerByIndex(void *self, size_t index) {
    return ((TYPEOF_ANONYMOUS_POINTER *) self) + index;
}

void setAnonymousPointerByIndex(void *self, size_t index, void *valueToSet) {
    *(getAnonymousPointerByIndex(self, index)) =
            (TYPEOF_ANONYMOUS_POINTER) valueToSet;
}