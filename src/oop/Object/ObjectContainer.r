#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "Object.r"

#define __OBJECT_CONSTRUCTABLE__ObjectContainer__ "objectConstructable"
#define __OBJECT_DESTRUCTABLE__ObjectContainer__  "objectDestructable"


// Forward declaration of incomplete type
typedef struct objectContainer ObjectContainer;

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
struct objectContainer {
    Object *object;
};

void storeObjectConstructorAndDestructor(ObjectContainer *objectContainer);

void invokeObjectDestructor(ObjectContainer *objectContainer);

#endif //OBJECTCONTAINER_H
