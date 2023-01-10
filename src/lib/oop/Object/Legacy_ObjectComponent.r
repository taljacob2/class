#ifndef LEGACY_OBJECTCOMPONENT_H
#define LEGACY_OBJECTCOMPONENT_H

#include "Destructable.r"
#include "InvocationStatus.r"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_ObjectComponent Legacy_ObjectComponent;

struct legacy_ObjectComponent {
    const char *CLASS_NAME;

    const Destructable *destructable;

    enum InvocationStatus destructorInvocationStatus;
};

Legacy_ObjectComponent *
Legacy_ObjectComponentConstructorClassName(const char *className);

#endif //LEGACY_OBJECTCOMPONENT_H
