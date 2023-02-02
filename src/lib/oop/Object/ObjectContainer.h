#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "Object.r"

// Forward declaration of incomplete type
typedef struct objectContainer ObjectContainer;

struct objectContainer {

    /// Implements `Object` privately.
    Object *object;
};

Object *getObject_ObjectContainer(void *self);

void setObject_ObjectContainer(void *self, Object *object);

#define DESTRUCT_OBJECT_CONTAINER(objectContainer) \
    (DESTRUCT_OBJECT(getObject_ObjectContainer(objectContainer)))

#endif //OBJECTCONTAINER_H
