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

Legacy_Object *getMemberStringObjectContainerEntryValueByName(
        Legacy_MemberList *legacyMemberList, char *memberName) {
    return getMemberStringObjectContainerEntryByName(legacyMemberList,
                                                     memberName)
            ->value;
}

Legacy_Object *
getMemberByName_Legacy_MemberList(Legacy_MemberList *legacyMemberList,
                                  char *             memberName) {
    return getMemberStringObjectContainerEntryValueByName(legacyMemberList,
                                                          memberName);
}

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

// TODO: "public" "setMember".

Legacy_MemberList *
Legacy_MemberListDestructor(Legacy_MemberList *legacyMemberList) {
    if (legacyMemberList == NULL) { return NULL; }

    AutoDestructableDestructor(
            (AutoDestructable *) legacyMemberList->getMemberByName(
                    legacyMemberList, "AutoDestructable"));

    legacyMemberList->memberEntryList
            ->Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData(
                    legacyMemberList->memberEntryList);

    free(legacyMemberList->legacyObjectComponent);
    free(legacyMemberList);

    return NULL;
}

/// @deprecated
Legacy_MemberList *Legacy_MemberListConstructor() {
    Legacy_MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMember       = &addMember;
    instance->getMemberByName = &getMemberByName_Legacy_MemberList;

    instance->memberEntryList = Legacy_ListConstructor();

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("Legacy_MemberList");

    addMember(instance, "AutoDestructable",
              (Legacy_Object *) AutoDestructableConstructorWithClassName(
                      (Legacy_Object *) instance,
                      instance->legacyObjectComponent->CLASS_NAME));

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

Legacy_MemberList *Legacy_MemberListConstructorWithLegacy_Object(
        Legacy_Object *legacyObjectThatContainsThisLegacy_MemberList) {
    Legacy_MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMember       = &addMember;
    instance->getMemberByName = &getMemberByName_Legacy_MemberList;

    instance->memberEntryList = Legacy_ListConstructor();

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("Legacy_MemberList");

    addMember(instance, "AutoDestructable",
              (Legacy_Object *) AutoDestructableConstructorWithClassName(
                      (Legacy_Object *)
                              legacyObjectThatContainsThisLegacy_MemberList,
                      legacyObjectThatContainsThisLegacy_MemberList
                              ->legacyObjectComponent->CLASS_NAME));

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
