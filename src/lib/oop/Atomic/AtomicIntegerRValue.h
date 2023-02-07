#ifndef ATOMICINTEGERRVALUE_H
#define ATOMICINTEGERRVALUE_H

#include "AtomicLValue.h"


/* TODO: rename `AtomicRValue` to `AtomicIntegerRValue`. Rename also in `Object.c` */
/* TODO: rename `RValue` to `IntegerRValue`. */
DEFINE_CLASS_H(AtomicIntegerRValue)

AtomicIntegerRValue *
AtomicIntegerRValueConstructor(IntegerRValue integerRValue);

#endif //ATOMICINTEGERRVALUE_H
