#ifndef CLASS_OBJECTBASE_H
#define CLASS_OBJECTBASE_H

#include "Constructable.h"
#include "Destructable.h"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct objectBase ObjectBase;

struct objectBase {
    const char *CLASS_NAME;

    const Constructable *constructable;

    const Destructable *destructable;
};

ObjectBase *ObjectBaseConstructor();

#endif //CLASS_OBJECTBASE_H
