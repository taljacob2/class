#ifndef LEGACY_OBJECT_H
#define LEGACY_OBJECT_H

#include "Constructable.r"
#include "Destructable.r"
#include "InvocationStatus.r"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_Object Legacy_Object;

struct legacy_Object {
    const char *CLASS_NAME;

    const Constructable *constructable;

    const Destructable *destructable;

    enum InvocationStatus destructorInvocationStatus;

    enum InvocationStatus deleteFromAllocationTableInvocationStatus;
};

Legacy_Object *Legacy_ObjectConstructorClassName(const char *className);

#endif //LEGACY_OBJECT_H
