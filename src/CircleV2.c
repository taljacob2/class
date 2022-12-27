#include "CircleV2.h"

void *CircleV2Destructor(CircleV2 *circlev2) {
    circlev2->legacy_memberList->object->destructable->destructor(
            circlev2->legacy_memberList);

    // ... Continue destructing `CircleV2` here ...

    free(circlev2->object);
    free(circlev2);

    return NULL;
}

CircleV2 *CircleV2Constructor() {
    CircleV2 *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->object = Legacy_ObjectConstructorClassName("CircleV2");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&CircleV2Constructor)};
    instance->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&CircleV2Destructor)};
    instance->object->destructable = &destructable;

    instance->legacy_memberList = Legacy_MemberListConstructorWithObjectContainer(
            (Legacy_ObjectContainer *) instance);

    instance->legacy_memberList->addMember(
            instance->legacy_memberList, "radius",
            (Legacy_ObjectContainer *) Legacy_AtomicFreerConstructorWithData(
                    calloc(1, sizeof(int))));

    return instance;
}