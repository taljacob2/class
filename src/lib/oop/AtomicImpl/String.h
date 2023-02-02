#ifndef STRING_H
#define STRING_H

#include "../Atomic/AtomicDoubleRValue.h"
#include "../Object/Object.h"
#include "AtomicImplDefines.h"


// Forward declaration of incomplete type
typedef struct string String;

struct string {

    /// Implements `Object` anonymously.
    ANONYMOUS_POINTER_AS_FIELD;

    char *(*get)(String *self);
    BOOLEAN (*set)(String *self, IntegerRValue integerRValueToSet);
};

String *StringConstructor();

#endif //STRING_H
