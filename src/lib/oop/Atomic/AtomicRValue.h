#ifndef ATOMICRVALUE_H
#define ATOMICRVALUE_H

#include "AtomicLValue.h"


// TODO: rename `AtomicRValue` to `AtomicIntegerRValue`. Rename also in `Object.c`
// TODO: rename `RValue` to `IntegerRValue`.
DEFINE_CLASS_H(AtomicRValue)

AtomicRValue *AtomicRValueConstructor(RValue rValue);

#endif //ATOMICRVALUE_H
