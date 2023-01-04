#include "CircleV2.h"

void *CircleV2Destructor(CircleV2 *circlev2) {
    circlev2->legacyMemberList->legacyObjectComponent->destructable->destructor(
            circlev2->legacyMemberList);

    // ... Continue destructing `CircleV2` here ...

    free(circlev2->legacyObjectComponent);
    free(circlev2);

    return NULL;
}

CircleV2 *CircleV2Constructor() {
    CircleV2 *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("CircleV2");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&CircleV2Constructor)};
    instance->legacyObjectComponent->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&CircleV2Destructor)};
    instance->legacyObjectComponent->destructable = &destructable;

    instance->legacyMemberList = Legacy_MemberListConstructor();

    instance->legacyMemberList->addMember(
            instance->legacyMemberList, "radius",
            (Legacy_Object *) Legacy_AtomicFreerConstructorWithData(
                    calloc(1, sizeof(int))));

    return instance;
}