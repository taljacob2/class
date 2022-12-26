#include "Object.r"

Legacy_ObjectContainer *addMemberWhichIsLegacy_ObjectContainer(
        Object *self, char *memberName,
        Legacy_ObjectContainer *legacyObjectContainer) {
    return self->memberList->addMember(self->memberList, memberName,
                                       legacyObjectContainer);
}

Legacy_ObjectContainer *
addMemberWhichIsPrimitive(Object *self, char *memberName,
                          void *dynamicallyAllocatedPrimitive) {
    return addMemberWhichIsLegacy_ObjectContainer(
            self, memberName,
            (Legacy_ObjectContainer *) Legacy_AtomicFreerConstructorWithData(
                    dynamicallyAllocatedPrimitive));
}

void *ObjectDestructor(Object *object) {
    object->memberList->object->destructable->destructor(object->memberList);

    free(object->object);
    free(object);

    return NULL;
}

/// @deprecated
Object *ObjectConstructorEmpty() { return ObjectConstructor("Object"); }

Object *ObjectConstructor(const char *className) {
    Object *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMemberWhichIsLegacy_ObjectContainer =
            &addMemberWhichIsLegacy_ObjectContainer;
    instance->addMemberWhichIsPrimitive = &addMemberWhichIsPrimitive;

    instance->object = Legacy_ObjectConstructorClassName(className);

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&ObjectConstructorEmpty)};
    instance->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ObjectDestructor)};
    instance->object->destructable = &destructable;

    instance->memberList = MemberListConstructorWithObjectContainer(
            (Legacy_ObjectContainer *) instance);

    // TODO: delete
    instance->memberList->addMember(
            instance->memberList, "radius",
            (Legacy_ObjectContainer *) Legacy_AtomicFreerConstructorWithData(
                    calloc(1, sizeof(int))));

    return instance;
}