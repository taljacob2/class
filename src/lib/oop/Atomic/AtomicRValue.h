#ifndef ATOMICRVALUE_H
#define ATOMICRVALUE_H

#include "AtomicLValue.h"

// `RValue` acts the same as the `&&` "move" operator in cpp.
typedef TYPEOF_ANONYMOUS_POINTER RValue;

DEFINE_CLASS_H(AtomicRValue)

AtomicRValue *AtomicRValueConstructor(RValue rValue);

#endif //ATOMICRVALUE_H
