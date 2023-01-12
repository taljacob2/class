#ifndef ATOMICLVALUE_H
#define ATOMICLVALUE_H

#include "../Object/Object.h"
#include "Random.r"

DEFINE_CLASS_H(AtomicLValue)

AtomicLValue *AtomicLValueConstructor(void *  data,
                                      BOOLEAN isDataDynamicallyAllocated);

#endif //ATOMICLVALUE_H
