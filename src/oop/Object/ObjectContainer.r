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

void storeObjectConstructorAndDestructor(ObjectContainer *objectContainer) {

    // `objectConstructable` is stored.
    const Constructable **objectConstructable =
            malloc(sizeof(const Constructable *));
    *objectConstructable = objectContainer->object->object->constructable;
    objectContainer->object->addMemberWhichIsPrimitive(
            objectContainer->object, __OBJECT_CONSTRUCTABLE__ObjectContainer__,
            objectConstructable);

    // `objectDestructable` is stored.
    const Destructable **objectDestructable =
            malloc(sizeof(const Destructable *));
    *objectDestructable = objectContainer->object->object->destructable;
    objectContainer->object->addMemberWhichIsPrimitive(
            objectContainer->object, __OBJECT_DESTRUCTABLE__ObjectContainer__,
            objectDestructable);
}

void invokeObjectDestructor(ObjectContainer *objectContainer) {

    // Invoke destructor of atomicInteger->object, which destructs everything.
    (*((Destructable **) objectContainer->object->getMemberByName(
             objectContainer->object,
             __OBJECT_DESTRUCTABLE__ObjectContainer__)))
            ->destructor(objectContainer->object);
}

#endif //OBJECTCONTAINER_H
