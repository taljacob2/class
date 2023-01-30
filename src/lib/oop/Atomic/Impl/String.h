#ifndef STRING_H
#define STRING_H

#include "../../Atomic/AtomicDoubleRValue.h"
#include "../../Object/Object.h"
#include "AtomicImplDefines.h"

DEFINE_CLASS_H_ALL_FIELDS_PRIVATE(String)
char *(*get)(String *self);
BOOLEAN (*set)(String *self, IntegerRValue integerRValueToSet);
}
;

String *StringConstructor();

#endif //STRING_H
