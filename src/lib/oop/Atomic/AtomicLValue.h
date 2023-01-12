#ifndef ATOMICLVALUE_H
#define ATOMICLVALUE_H

#include "../Object/Object.h"
#include "Random.r"

#define __ATOMIC_MEMBER_NAME__ "__AtomicMemberName__"

DEFINE_CLASS_H(AtomicLValue)

AtomicLValue *AtomicLValueConstructor(void *  data,
                                      BOOLEAN isDataDynamicallyAllocated);

#endif //ATOMICLVALUE_H
