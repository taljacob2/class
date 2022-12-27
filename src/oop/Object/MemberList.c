#include "MemberList.r"

Legacy_ObjectContainer *addMemberWhichIsLegacy_ObjectContainer(
        MemberList *self, char *memberName,
        Legacy_ObjectContainer *legacyObjectContainer) {
    return self->legacy_memberList->addMember(
            self->legacy_memberList, memberName, legacyObjectContainer);
}

Legacy_ObjectContainer *
addMemberWhichIsPrimitive(MemberList *self, char *memberName,
                          void *dynamicallyAllocatedPrimitive) {
    return addMemberWhichIsLegacy_ObjectContainer(
            self, memberName,
            (Legacy_ObjectContainer *) Legacy_AtomicFreerConstructorWithData(
                    dynamicallyAllocatedPrimitive));
}

//// TODO: maybe remove. could be redundant.
//Legacy_ObjectContainer *
//addMemberWhichIsPrimitiveAnonymousPointer(MemberList *self, char *memberName) {
//    return self->addMemberWhichIsPrimitive(
//            self, memberName, calloc(1, sizeof(TYPEOF_ANONYMOUS_POINTER)));
//}

Legacy_ObjectContainer *getMemberByName_MemberList(MemberList *self,
                                                   char *      memberName) {
    return self->legacy_memberList->getMemberByName(self->legacy_memberList,
                                                    memberName);
}

void *MemberListDestructor(MemberList *object) {
    object->legacy_memberList->object->destructable->destructor(
            object->legacy_memberList);

    free(object->object);
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

    instance->object = Legacy_ObjectConstructorClassName("MemberList");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&MemberListConstructor)};
    instance->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&MemberListDestructor)};
    instance->object->destructable = &destructable;

    instance->legacy_memberList =
            Legacy_MemberListConstructorWithObjectContainer(
                    (Legacy_ObjectContainer *) instance);

    return instance;
}