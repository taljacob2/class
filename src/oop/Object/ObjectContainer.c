#include "ObjectContainer.r"

void storeLegacyObjectConstructorAndDestructor(
        ObjectContainer *objectContainer) {

    // `__LEGACY_OBJECT_CONSTRUCTABLE__ObjectContainer__` is stored.
    const Constructable **legacyObjectConstructable =
            malloc(sizeof(const Constructable *));
    *legacyObjectConstructable = objectContainer->legacyObject->constructable;
    objectContainer->object->addMemberWhichIsPrimitive(
            objectContainer->object,
            __LEGACY_OBJECT_CONSTRUCTABLE__ObjectContainer__,
            legacyObjectConstructable);

    // `__LEGACY_OBJECT_DESTRUCTABLE__ObjectContainer__` is stored.
    const Destructable **legacyObjectDestructable =
            malloc(sizeof(const Destructable *));
    *legacyObjectDestructable = objectContainer->object->object->destructable;
    objectContainer->object->addMemberWhichIsPrimitive(
            objectContainer->object,
            __LEGACY_OBJECT_DESTRUCTABLE__ObjectContainer__,
            legacyObjectDestructable);
}

void *invokeStoredLegacyObjectDestructor(ObjectContainer *objectContainer) {

    // Invoke destructor of `legacyObjectDestructable`.
    return (*((Destructable **) objectContainer->object->getMemberByName(
                    objectContainer->object,
                    __LEGACY_OBJECT_DESTRUCTABLE__ObjectContainer__)))
            ->destructor(objectContainer->legacyObject);
}

/// @deprecated No need to use this. But it should work.
Legacy_Object *
invokeStoredLegacyObjectConstructor(ObjectContainer *objectContainer) {

    // Invoke constructor of `legacyObjectConstructable`.
    return (*((Constructable **) objectContainer->object->getMemberByName(
                    objectContainer->object,
                    __LEGACY_OBJECT_CONSTRUCTABLE__ObjectContainer__)))
            ->constructor(objectContainer->legacyObject);
}

