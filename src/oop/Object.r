#ifndef OBJECT_H
#define OBJECT_H

#include "Constructable.r"
#include "Destructable.r"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct object Object;

struct object {
    const char *CLASS_NAME;

    const Constructable *constructable;

    const Destructable *destructable;
};

Object *ObjectBaseConstructor();

#endif //OBJECT_H
