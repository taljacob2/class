#include "MemberList.r"

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

void *MemberListDestructor(MemberList *memberList) {
    if (memberList == NULL) { return NULL; }

    AutoDestructableDestructor(memberList->autoDestructable);

    memberList->legacyMemberList->legacyObjectComponent->destructable
            ->destructor(memberList->legacyMemberList);

    free(memberList->legacyObjectComponent);
    free(memberList);

    return NULL;
}

MemberList *MemberListConstructor() {
    MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMemberWhichIsLegacy_Object =
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

    instance->legacyMemberList = Legacy_MemberListConstructor();

    return instance;
}