#include "CircleV2.h"

void *CircleV2Destructor(CircleV2 *circlev2) {
    circlev2->memberList->object->destructable->destructor(
            circlev2->memberList);

    // ... Continue destructing `CircleV2` here ...

    free(circlev2->object);
    free(circlev2);

    return NULL;
}

CircleV2 *CircleV2Constructor() {
    CircleV2 *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->object = ObjectConstructorClassName("CircleV2");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&CircleV2Constructor)};
    instance->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&CircleV2Destructor)};
    instance->object->destructable = &destructable;

    instance->memberList = MemberListConstructor();

    instance->memberList->addMember(
            instance->memberList, "radius",
            (ObjectContainer *) Legacy_AtomicFreerConstructorWithData(
                    calloc(1, sizeof(int))));

    return instance;
}