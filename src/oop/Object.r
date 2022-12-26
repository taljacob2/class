#ifndef OBJECT_H
#define OBJECT_H

#include "Constructable.r"
#include "Destructable.r"
#include "InvocationStatus.r"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct object Object;

struct object {
    const char *CLASS_NAME;

    const Constructable *constructable;

    const Destructable *destructable;

    enum InvocationStatus destructorInvocationStatus;

    enum InvocationStatus deleteFromAllocationTableInvocationStatus;
};

Object *ObjectConstructorClassName(const char *className);

#endif //OBJECT_H
