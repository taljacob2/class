#ifndef CLASS_OBJECTBASE_H
#define CLASS_OBJECTBASE_H

#include "Constructable.h"
#include "Destructable.h"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct objectBase ObjectBase;

struct objectBase {

    /// Sensitive data. DO NOT TOUCH!
    void *ALLOCATION_ADDRESS;

    /// Sensitive data. DO NOT TOUCH!
    char *CLASS_NAME;

    Constructable const *constructable;

    Destructable const *destructable;
};

ObjectBase *ObjectBaseConstructor();

#endif //CLASS_OBJECTBASE_H
