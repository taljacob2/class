#ifndef CLASS_OBJECTBASE_R
#define CLASS_OBJECTBASE_R

#include "Constructable.r"
#include "Destructable.r"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct objectBase ObjectBase;

struct objectBase {
    const char *CLASS_NAME;

    const Constructable *constructable;

    const Destructable *destructable;
};

ObjectBase *ObjectBaseConstructor();

#endif //CLASS_OBJECTBASE_R
