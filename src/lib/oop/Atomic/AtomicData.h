#ifndef ATOMICDATA_H
#define ATOMICDATA_H

#include "../Object/Object.h"

#define __ATOMIC_MEMBER_NAME__ "__ATOMIC_MEMBER_NAME__"

DEFINE_CLASS_H(AtomicData)

AtomicData *AtomicDataConstructor(void *dynamicallyAllocatedData);

#endif //ATOMICDATA_H
