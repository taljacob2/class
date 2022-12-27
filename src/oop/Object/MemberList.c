#include "MemberList.r"

Legacy_Object *
addMemberWhichIsLegacy_ObjectContainer(MemberList *self, char *memberName,
                                       Legacy_Object *legacyObjectContainer) {
    return self->legacyMemberList->addMember(self->legacyMemberList, memberName,
                                             legacyObjectContainer);
}

Legacy_Object *addMemberWhichIsPrimitive(MemberList *self, char *memberName,
                                         void *dynamicallyAllocatedPrimitive) {
    return addMemberWhichIsLegacy_ObjectContainer(
            self, memberName,
            (Legacy_Object *) Legacy_AtomicFreerConstructorWithData(
                    dynamicallyAllocatedPrimitive));
}

//// TODO: maybe remove. could be redundant.
//Legacy_Object *
//addMemberWhichIsPrimitiveAnonymousPointer(MemberList *self, char *memberName) {
//    return self->addMemberWhichIsPrimitive(
//            self, memberName, calloc(1, sizeof(TYPEOF_ANONYMOUS_POINTER)));
//}

Legacy_Object *getMemberByName_MemberList(MemberList *self, char *memberName) {
    return self->legacyMemberList->getMemberByName(self->legacyMemberList,
                                                   memberName);
}

void *MemberListDestructor(MemberList *object) {
    object->legacyMemberList->legacyObjectComponent->destructable->destructor(
            object->legacyMemberList);

    free(object->legacyObjectComponent);
    free(object);

    return NULL;
}

MemberList *MemberListConstructor() {
    MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMemberWhichIsLegacy_ObjectContainer =
            &addMemberWhichIsLegacy_ObjectContainer;
    instance->addMemberWhichIsPrimitive = &addMemberWhichIsPrimitive;
    instance->getMemberByName           = &getMemberByName_MemberList;

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("MemberList");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&MemberListConstructor)};
    instance->legacyObjectComponent->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&MemberListDestructor)};
    instance->legacyObjectComponent->destructable = &destructable;

    instance->legacyMemberList = Legacy_MemberListConstructorWithLegacy_Object(
            (Legacy_Object *) instance);

    return instance;
}