#ifndef ATOMICDATA_H
#define ATOMICDATA_H

#include "../Object/Object.h"
#include "Random.r"

DEFINE_CLASS_H(AtomicData)

AtomicData *AtomicDataConstructor(void *  data,
                                  BOOLEAN isDataDynamicallyAllocated);

#endif //ATOMICDATA_H
