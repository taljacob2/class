#ifndef ATOMICPRIMITIVE_H
#define ATOMICPRIMITIVE_H

#include "AtomicData.h"

typedef TYPEOF_ANONYMOUS_POINTER TypeOfPrimitive;

DEFINE_CLASS_H(AtomicPrimitive)

AtomicPrimitive *AtomicPrimitiveConstructor(TypeOfPrimitive primitiveData);

#endif //ATOMICPRIMITIVE_H
