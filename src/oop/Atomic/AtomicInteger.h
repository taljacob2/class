#ifndef ATOMICINTEGER_H
#define ATOMICINTEGER_H

#include "../Object/Object.h"
#include "Atomic.h"

// Forward declaration of incomplete type
typedef struct atomicInteger AtomicInteger;

struct atomicInteger {

    /// `AtomicInteger` implements `MemberList`.
    MemberList *object;

};

AtomicInteger *AtomicIntegerConstructor();


#endif //ATOMICINTEGER_H
