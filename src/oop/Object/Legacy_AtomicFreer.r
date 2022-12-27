#ifndef ATOMICFREER_H
#define ATOMICFREER_H

#include "Legacy_Object.r"

// Forward declaration of incomplete type
typedef struct legacy_atomicFreer Legacy_AtomicFreer;

struct legacy_atomicFreer {

    /// `Legacy_AtomicFreer` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *legacyObjectComponent;

    void *data;
};

Legacy_AtomicFreer *Legacy_AtomicFreerConstructor();

Legacy_AtomicFreer *Legacy_AtomicFreerConstructorWithData(void *data);

#endif //ATOMICFREER_H
