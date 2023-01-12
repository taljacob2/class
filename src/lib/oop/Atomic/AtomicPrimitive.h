#ifndef ATOMICPRIMITIVE_H
#define ATOMICPRIMITIVE_H

#include "AtomicData.h"

typedef void *TypeOfPrimitive;

DEFINE_CLASS_H(AtomicPrimitive)

AtomicPrimitive *AtomicPrimitiveConstructor(void *primitiveData);

#endif //ATOMICPRIMITIVE_H
