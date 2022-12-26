#include "ObjectContainer.r"

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
