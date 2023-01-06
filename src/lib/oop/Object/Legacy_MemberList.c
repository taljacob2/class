#include "Legacy_MemberList.r"

BOOLEAN predicateFindLegacy_StringEntryByMemberName(
        const Legacy_Node *nodeThatPointsToAllocationTable,
        const char *const  memberName) {
    return strcmp(((Legacy_StringObjectContainerEntry
                            *) (nodeThatPointsToAllocationTable->data))
                          ->key,
                  memberName) == 0;
}

Legacy_Node *getMemberNodeByName(Legacy_MemberList *legacyMemberList,
                                 char *             memberName) {
    return legacyMemberList->memberEntryList->findNodeByPredicateOfConstString(
            legacyMemberList->memberEntryList,
            predicateFindLegacy_StringEntryByMemberName, memberName);
}

Legacy_StringObjectContainerEntry *
getMemberStringObjectContainerEntryByName(Legacy_MemberList *legacyMemberList,
                                          char *             memberName) {
    return (getMemberNodeByName(legacyMemberList, memberName))->data;
}

Legacy_StringObjectContainerEntry *
getMemberStringObjectContainerEntryByNameAndDeleteMemberFromList(
        Legacy_MemberList *legacyMemberList, char *memberName) {
    Legacy_Node *legacyNode = getMemberNodeByName(legacyMemberList, memberName);
    return legacyMemberList->memberEntryList->delete (
            legacyMemberList->memberEntryList, legacyNode);
}

Legacy_Object *getMemberStringObjectContainerEntryValueByName(
        Legacy_MemberList *legacyMemberList, char *memberName) {
    return getMemberStringObjectContainerEntryByName(legacyMemberList,
                                                     memberName)
            ->value;
}

Legacy_Object *
getMemberStringObjectContainerEntryValueByNameAndDeleteMemberFromList(
        Legacy_MemberList *legacyMemberList, char *memberName) {
    return getMemberStringObjectContainerEntryByNameAndDeleteMemberFromList(
                   legacyMemberList, memberName)
            ->value;
}

// "public" function.
Legacy_Object *
getMemberByName_Legacy_MemberList(Legacy_MemberList *legacyMemberList,
                                  char *             memberName) {
    return getMemberStringObjectContainerEntryValueByName(legacyMemberList,
                                                          memberName);
}

// "public" function.
Legacy_Object *getMemberByName_Legacy_MemberListAndDeleteMemberFromList(
        Legacy_MemberList *legacyMemberList, char *memberName) {
    return getMemberStringObjectContainerEntryValueByNameAndDeleteMemberFromList(
            legacyMemberList, memberName);
}

// "private" function.
Legacy_Object *addMember(Legacy_MemberList *legacyMemberList, char *memberName,
                         Legacy_Object *member) {
    Legacy_Node *objectEntryNode = Legacy_NodeConstructorWithData(
            Legacy_StringObjectContainerEntryConstructorWithKeyAndValue(
                    memberName, member));

    legacyMemberList->memberEntryList->addAsUnique(
            legacyMemberList->memberEntryList, objectEntryNode,
            predicateFindLegacy_StringEntryByMemberName, memberName);

    return member;
}

// "public" function.
Legacy_Object *
addMemberWhichIsLegacy_Object(Legacy_MemberList *legacyMemberList,
                              char *             memberName,
                              Legacy_Object *    legacyObjectContainer) {
    return addMember(legacyMemberList, memberName, legacyObjectContainer);
}

// "public" function.
Legacy_Object *addMemberWhichIsPrimitive(Legacy_MemberList *legacyMemberList,
                                         char *             memberName,
                                         void *dynamicallyAllocatedPrimitive) {
    return addMemberWhichIsLegacy_Object(
            legacyMemberList, memberName,
            (Legacy_Object *) Legacy_AtomicFreerConstructorWithData(
                    dynamicallyAllocatedPrimitive));
}

// TODO: "public" "setMember".

Legacy_MemberList *
Legacy_MemberListDestructor(Legacy_MemberList *legacyMemberList) {
    if (legacyMemberList == NULL) { return NULL; }

    legacyMemberList->memberEntryList
            ->Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData(
                    legacyMemberList->memberEntryList);

    free(legacyMemberList->legacyObjectComponent);
    free(legacyMemberList);

    return NULL;
}

Legacy_MemberList *Legacy_MemberListConstructor() {
    Legacy_MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->getMemberByName = &getMemberByName_Legacy_MemberList;
    instance->getMemberByNameAndDeleteMemberFromList =
            &getMemberByName_Legacy_MemberListAndDeleteMemberFromList;
    instance->addMemberWhichIsLegacy_Object = &addMemberWhichIsLegacy_Object;
    instance->addMemberWhichIsPrimitive     = &addMemberWhichIsPrimitive;

    instance->memberEntryList = Legacy_ListConstructor();

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("Legacy_MemberList");

    static Constructable const constructable = {
            .constructor =
                    (void *(*const)(void) )(&Legacy_MemberListConstructor)};
    instance->legacyObjectComponent->constructable = &constructable;

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&Legacy_MemberListDestructor)};
    instance->legacyObjectComponent->destructable = &destructable;

    return instance;
}
