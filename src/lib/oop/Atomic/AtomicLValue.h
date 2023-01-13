#ifndef ATOMICLVALUE_H
#define ATOMICLVALUE_H

#include "../Object/Object.h"
#include "Random.r"

#define __ATOMIC_LVALUE_MEMBER_NAME__ "__ATOMIC_LVALUE_MEMBER_NAME__"

DEFINE_CLASS_H(AtomicLValue)

AtomicLValue *AtomicLValueConstructor(void *  data,
                                      BOOLEAN isDataDynamicallyAllocated);

#endif //ATOMICLVALUE_H
