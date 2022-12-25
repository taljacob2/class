#include "MemberList.r"

BOOLEAN predicateFindLegacy_StringEntryByMemberName(
        const Legacy_Node *nodeThatPointsToAllocationTable,
        const char *const  memberName) {
    return strcmp(((Legacy_StringEntry *) (nodeThatPointsToAllocationTable
                                                   ->data))
                          ->key,
                  memberName) == 0;
}

void *getMemberByName(MemberList *memberList, char *memberName) {
    return memberList->memberEntryList->findNodeByPredicateOfConstString(
            memberList->memberEntryList,
            predicateFindLegacy_StringEntryByMemberName, memberName);
}

void *addMember(MemberList *memberList, char *memberName, void *member) {
    Legacy_Node *objectEntryNode = Legacy_NodeConstructorWithDataAndDataSize(
            Legacy_StringEntryConstructorWithKeyAndValue(memberName, member),
            sizeof(Legacy_StringEntry *));

    memberList->memberEntryList->addAsUnique(
            memberList->memberEntryList, objectEntryNode,
            predicateFindLegacy_StringEntryByMemberName, memberName);

    return member;
}

MemberList *MemberListDestructor(MemberList *memberList) {
    AutoDestructableV2Destructor(
            memberList->getMemberByName(memberList, "autoDestructableV2"));

    // ... Continue destructing `Circle` here ...

    memberList->memberEntryList->object->destructable->destructor(
            memberList->memberEntryList);

    free(memberList->getMemberByName(memberList, "object"));
    free(memberList);

    return NULL;
}

MemberList *MemberListConstructor() {
    MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMember       = &addMember;
    instance->getMemberByName = &getMemberByName;

    instance->memberEntryList = Legacy_ListConstructor();

    Object *object = addMember(instance, "object", ObjectConstructor());

    addMember(instance, "autoDestructableV2",
              AutoDestructableV2ConstructorWithClassName(object, "MemberList"));

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&MemberListConstructor)};
    object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&MemberListDestructor)};
    object->destructable = &destructable;

    return instance;
}
