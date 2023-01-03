#include "AnonymousPointer.r"

TYPEOF_ANONYMOUS_POINTER *getAnonymousPointerByIndex(void *self, size_t index) {
    return ((TYPEOF_ANONYMOUS_POINTER *) self) + index;
}

TYPEOF_ANONYMOUS_POINTER getAnonymousPointerValueByIndex(void * self,
                                                         size_t index) {
    return *(((TYPEOF_ANONYMOUS_POINTER *) self) + index);
}

void setAnonymousPointerValueByIndex(void *self, size_t index,
                                     void *valueToSet) {
    *(getAnonymousPointerByIndex(self, index)) =
            (TYPEOF_ANONYMOUS_POINTER) valueToSet;
}

void setAnonymousPointerValue(TYPEOF_ANONYMOUS_POINTER *anonymousPointer,
                              void *                    valueToSet) {
    *anonymousPointer = (TYPEOF_ANONYMOUS_POINTER) valueToSet;
}