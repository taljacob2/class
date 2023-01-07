#include "Object.r"

/* ---------------------------- GET POINTER VALUE --------------------------- */

// "private" function.
Legacy_ObjectComponent *getLegacyObjectComponent(Object *object) {
    return (Legacy_ObjectComponent *) getAnonymousPointerValueByIndex(object,
                                                                      0);
}

// "private" function.
Legacy_List *getPrivateMemberNameLegacy_List(Object *object) {
    return (Legacy_List *) getAnonymousPointerValueByIndex(object, 1);
}

// "private" function.
Legacy_List *getPublicMemberNameLegacy_List(Object *object) {
    return (Legacy_List *) getAnonymousPointerValueByIndex(object, 2);
}

// "private" function.
Legacy_MemberList *getMethodsMemberList(Object *object) {
    return (Legacy_MemberList *) getAnonymousPointerValueByIndex(object, 3);
}

// "private" function.
Legacy_MemberList *getConstructorMemberList(Object *object) {
    return (Legacy_MemberList *) getAnonymousPointerValueByIndex(object, 4);
}

// "private" function.
Legacy_MemberList *getDestructorMemberList(Object *object) {
    return (Legacy_MemberList *) getAnonymousPointerValueByIndex(object, 5);
}

// "private" function.
Legacy_MemberList *getFieldsMemberList(Object *object) {
    return (Legacy_MemberList *) getAnonymousPointerValueByIndex(object, 6);
}

// "private" function.
Legacy_MemberList *getAutoDestructable(Object *object) {
    return (Legacy_MemberList *) getAnonymousPointerValueByIndex(object, 7);
}

// "private" function.
void *getFunctionToInvokeWhenObjectIsAboutToBeDestructed(Object *object) {
    return (void *) getAnonymousPointerValueByIndex(object, 8);
}

// "private" function.
const char *getMemberName(Object *object) {
    return (const char *) getAnonymousPointerValueByIndex(object, 9);
}

// "private" function.
Object *getObjectThatContainsThisObjectAsAMember(Object *object) {
    return (Object *) getAnonymousPointerValueByIndex(object, 10);
}

/* --------------------------- SET POINTER VALUE ---------------------------- */

// "private" function.
void setLegacyObjectComponent(Object *                object,
                              Legacy_ObjectComponent *legacyObjectComponent) {
    setAnonymousPointerValueByIndex(object, 0, legacyObjectComponent);
}

// "private" function.
void setPrivateMemberNameLegacy_List(Object *object, Legacy_List *legacyList) {
    setAnonymousPointerValueByIndex(object, 1, legacyList);
}

// "private" function.
void setPublicMemberNameLegacy_List(Object *object, Legacy_List *legacyList) {
    setAnonymousPointerValueByIndex(object, 2, legacyList);
}

// "private" function.
void setMethodsMemberList(Object *object, Legacy_MemberList *legacyMemberList) {
    setAnonymousPointerValueByIndex(object, 3, legacyMemberList);
}

// "private" function.
void setConstructorMemberList(Object *           object,
                              Legacy_MemberList *legacyMemberList) {
    setAnonymousPointerValueByIndex(object, 4, legacyMemberList);
}

// "private" function.
void setDestructorMemberList(Object *           object,
                             Legacy_MemberList *legacyMemberList) {
    setAnonymousPointerValueByIndex(object, 5, legacyMemberList);
}

// "private" function.
void setFieldsMemberList(Object *object, Legacy_MemberList *legacyMemberList) {
    setAnonymousPointerValueByIndex(object, 6, legacyMemberList);
}

// "private" function.
void setAutoDestructable(Object *object, AutoDestructable *autoDestructable) {
    setAnonymousPointerValueByIndex(object, 7, autoDestructable);
}

// "private" function.
/**
 * @param object Object that is about to be destructed.
 * @param getMemberAndRemoveFromAccessModifierAndMemberList For example
 * `getPublicFieldAndRemoveFromPublicAccessModifierAndFieldsMemberList`,
 * `getNoMemberAndRemoveFromNoAccessModifierAndNoMemberList`
 */
void setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
        Object *object,
        Legacy_Object *(*getMemberAndRemoveFromAccessModifierAndMemberList)(
                Object *, Object *) ) {
    setAnonymousPointerValueByIndex(
            object, 8, getMemberAndRemoveFromAccessModifierAndMemberList);
}

// "private" function.
void setMemberName(Object *object, const char *memberName) {
    setAnonymousPointerValueByIndex(object, 9, (void *) memberName);
}

// "private" function.
void setObjectThatContainsThisObjectAsAMember(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    setAnonymousPointerValueByIndex(object, 10,
                                    objectThatContainsThisObjectAsAMember);
}

/* ------------------ */

//// TODO: figure out how to return a function type
////  READ MORE HERE:
////  https://www.geeksforgeeks.org/returning-a-function-pointer-from-a-function-in-c-cpp/
//
//// "private" function.
//Legacy_Object *(*getPrivateMethod_FUNCTION)(Object *object,
//                                            char *memberName)(Object *object) {
//    return (Legacy_Object *
//            (*) (Object * object, char *memberName)(Object * object))
//            getAnonymousPointerByIndex(object, 7);
//}

/* ----------------------------- GET MEMBER --------------------------------- */

// "private" function.
BOOLEAN predicateFindAccessModifierMemberNameByMemberName(
        const Legacy_Node *nodeThatPointsToMemberName,
        const char *const  stringToSearch) {
    return strcmp((char *) (nodeThatPointsToMemberName->data),
                  stringToSearch) == 0;
}

// "private" function.
Legacy_Node *findAccessModifierMemberName(Legacy_List *accessModifierLegacyList,
                                          char *       memberName) {
    return accessModifierLegacyList->findNodeByPredicateOfConstString(
            accessModifierLegacyList,
            predicateFindAccessModifierMemberNameByMemberName, memberName);
}

// "private" function.
void *findAccessModifierMemberNameAndRemoveFromList(
        Legacy_List *accessModifierLegacyList, char *memberName) {
    return accessModifierLegacyList->deleteNodeThatHasTheGivenData(
            accessModifierLegacyList, memberName);
}

// "private" function.
Legacy_Node *findPrivateMemberName(Object *object, char *memberName) {
    return findAccessModifierMemberName(getPrivateMemberNameLegacy_List(object),
                                        memberName);
}

// "private" function.
Legacy_Node *findPublicMemberName(Object *object, char *memberName) {
    return findAccessModifierMemberName(getPublicMemberNameLegacy_List(object),
                                        memberName);
}

// "private" function.
BOOLEAN isPrivateMember(Object *object, char *memberName) {
    return findPrivateMemberName(object, memberName) != NULL;
}

// "private" function.
BOOLEAN isPublicMember(Object *object, char *memberName) {
    return findPublicMemberName(object, memberName) != NULL;
}

// "private" function.
Legacy_Object *
findMemberInMemberListByMemberName(Legacy_MemberList *legacyMemberList,
                                   char *             memberName) {
    return legacyMemberList->getMemberByName(legacyMemberList, memberName);
}

// "private" function.
Legacy_Object *findMemberInMemberListByMemberNameAndRemoveFromList(
        Legacy_MemberList *legacyMemberList, char *memberName) {
    return legacyMemberList->getMemberByNameAndDeleteMemberFromList(
            legacyMemberList, memberName);
}

// "private" function.
Legacy_Object *getAccessModifierMember(Legacy_List *accessModifierLegacyList,
                                       Legacy_MemberList *legacyMemberList,
                                       char *             memberName) {
    Legacy_Node *findAccessModifierMemberNameReturnValue =
            findAccessModifierMemberName(accessModifierLegacyList, memberName);
    if (findAccessModifierMemberNameReturnValue == NULL) { return NULL; }

    Legacy_Object *findMemberInMemberListByMemberNameReturnValue =
            findMemberInMemberListByMemberName(legacyMemberList, memberName);
    if (findMemberInMemberListByMemberNameReturnValue == NULL) { return NULL; }

    return findMemberInMemberListByMemberNameReturnValue;
}

// "private" function.
Legacy_Object *
getAccessModifierMemberAndRemoveFromList(Legacy_List *accessModifierLegacyList,
                                         Legacy_MemberList *legacyMemberList,
                                         char *             memberName) {
    void *findAccessModifierMemberNameReturnValue =
            findAccessModifierMemberNameAndRemoveFromList(
                    accessModifierLegacyList, memberName);
    if (findAccessModifierMemberNameReturnValue == NULL) { return NULL; }

    Legacy_Object *findMemberInMemberListByMemberNameReturnValue =
            findMemberInMemberListByMemberNameAndRemoveFromList(
                    legacyMemberList, memberName);
    if (findMemberInMemberListByMemberNameReturnValue == NULL) { return NULL; }

    return findMemberInMemberListByMemberNameReturnValue;
}

/* -------------- Specific Access Modifier ------------- */

// "private" function.
Legacy_Object *getPrivateMember(Object *           object,
                                Legacy_MemberList *legacyMemberList,
                                char *             memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   legacyMemberList, memberName);
}

// "private" function.
Legacy_Object *getPublicMember(Object *           object,
                               Legacy_MemberList *legacyMemberList,
                               char *             memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   legacyMemberList, memberName);
}

/* Specific Access Modifier & Specific Legacy_MemberList */

/* --------------- Methods --------------- */

// "public" function.
Legacy_Object *getPrivateMethod(Object *object, char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   getMethodsMemberList(object), memberName);
}

// "public" function.
Legacy_Object *getPublicMethod(Object *object, char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   getMethodsMemberList(object), memberName);
}

/* ------------- Constructor ------------- */

// "public" function.
Legacy_Object *getPrivateConstructor(Object *object, char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   getConstructorMemberList(object),
                                   memberName);
}

// "public" function.
Legacy_Object *getPublicConstructor(Object *object, char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   getConstructorMemberList(object),
                                   memberName);
}

/* ------------- Destructor ------------- */

// "public" function.
Legacy_Object *getPrivateDestructor(Object *object, char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   getDestructorMemberList(object), memberName);
}

// "public" function.
Legacy_Object *getPublicDestructor(Object *object, char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   getDestructorMemberList(object), memberName);
}

/* --------------- Fields --------------- */

// "public" function.
Legacy_Object *getPrivateField(Object *object, char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   getFieldsMemberList(object), memberName);
}

// "public" function.
Legacy_Object *getPublicField(Object *object, char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   getFieldsMemberList(object), memberName);
}

/* Get And Remove From Specific Access Modifier & Specific Legacy_MemberList */

/* --------------- Nothing --------------- */

// "private" function.
Legacy_Object *getNoMemberAndRemoveFromNoAccessModifierAndNoMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    return NULL; // Does nothing.
}

/* --------------- Methods --------------- */

// "private" function.
Legacy_Object *
getPublicMethodAndRemoveFromPublicAccessModifierAndMethodsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPublicMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getMethodsMemberList(objectThatContainsThisObjectAsAMember),
            (char *) getMemberName(object));
}

// "private" function.
Legacy_Object *
getPrivateMethodAndRemoveFromPrivateAccessModifierAndMethodsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPrivateMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getMethodsMemberList(objectThatContainsThisObjectAsAMember),
            (char *) getMemberName(object));
}

/* ------------- Constructor ------------- */

// "private" function.
Legacy_Object *
getPublicConstructorAndRemoveFromPublicAccessModifierAndConstructorMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPublicMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getConstructorMemberList(objectThatContainsThisObjectAsAMember),
            (char *) getMemberName(object));
}

// "private" function.
Legacy_Object *
getPrivateConstructorAndRemoveFromPrivateAccessModifierAndConstructorMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPrivateMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getConstructorMemberList(objectThatContainsThisObjectAsAMember),
            (char *) getMemberName(object));
}

/* ------------- Destructor ------------- */

// "private" function.
Legacy_Object *
getPublicDestructorAndRemoveFromPublicAccessModifierAndDestructorMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPublicMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getDestructorMemberList(objectThatContainsThisObjectAsAMember),
            (char *) getMemberName(object));
}

// "private" function.
Legacy_Object *
getPrivateDestructorAndRemoveFromPrivateAccessModifierAndDestructorMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPrivateMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getDestructorMemberList(objectThatContainsThisObjectAsAMember),
            (char *) getMemberName(object));
}

/* --------------- Fields --------------- */

// "private" function.
Legacy_Object *
getPublicFieldAndRemoveFromPublicAccessModifierAndFieldsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPublicMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getFieldsMemberList(objectThatContainsThisObjectAsAMember),
            (char *) getMemberName(object));
}

// "private" function.
Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPrivateMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getFieldsMemberList(objectThatContainsThisObjectAsAMember),
            (char *) getMemberName(object));
}

/* ----------------------------- ADD MEMBER --------------------------------- */

// "private" function.
void addAccessModifierMemberList(Legacy_List *      accessModifierLegacyList,
                                 Legacy_MemberList *legacyMemberList,
                                 char *memberName, Object *memberToAdd) {
    setMemberName(memberToAdd, memberName);

    // Add `memberName` to accessModifierList.
    accessModifierLegacyList->addAsUnique(
            accessModifierLegacyList,
            Legacy_NodeConstructorWithData(memberName),
            predicateFindAccessModifierMemberNameByMemberName, memberName);

    // Add member to MemberList.
    legacyMemberList->addMemberWhichIsLegacy_Object(
            legacyMemberList, memberName, (Legacy_Object *) memberToAdd);
}

/* --- Specific Access Modifier & Specific MemberList --- */

/* --------------- Methods --------------- */

// "public" function.
void addPrivateMethod(Object *self, char *memberName, Object *memberToAdd) {
    setObjectThatContainsThisObjectAsAMember(memberToAdd, self);
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(self),
                                getMethodsMemberList(self), memberName,
                                memberToAdd);
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            memberToAdd,
            getPrivateMethodAndRemoveFromPrivateAccessModifierAndMethodsMemberList);
}

// "public" function.
void addPublicMethod(Object *self, char *memberName, Object *memberToAdd) {
    setObjectThatContainsThisObjectAsAMember(memberToAdd, self);
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(self),
                                getMethodsMemberList(self), memberName,
                                memberToAdd);
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            memberToAdd,
            getPublicMethodAndRemoveFromPublicAccessModifierAndMethodsMemberList);
}

/* ------------- Constructor ------------- */

// "public" function.
void addPrivateConstructor(Object *self, char *memberName,
                           Object *memberToAdd) {
    setObjectThatContainsThisObjectAsAMember(memberToAdd, self);
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(self),
                                getConstructorMemberList(self), memberName,
                                memberToAdd);
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            memberToAdd,
            getPrivateConstructorAndRemoveFromPrivateAccessModifierAndConstructorMemberList);
}

// "public" function.
void addPublicConstructor(Object *self, char *memberName, Object *memberToAdd) {
    setObjectThatContainsThisObjectAsAMember(memberToAdd, self);
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(self),
                                getConstructorMemberList(self), memberName,
                                memberToAdd);
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            memberToAdd,
            getPublicConstructorAndRemoveFromPublicAccessModifierAndConstructorMemberList);
}

/* ------------- Destructor ------------- */

// "public" function.
void addPrivateDestructor(Object *self, char *memberName, Object *memberToAdd) {
    setObjectThatContainsThisObjectAsAMember(memberToAdd, self);
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(self),
                                getDestructorMemberList(self), memberName,
                                memberToAdd);
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            memberToAdd,
            getPrivateDestructorAndRemoveFromPrivateAccessModifierAndDestructorMemberList);
}

// "public" function.
void addPublicDestructor(Object *self, char *memberName, Object *memberToAdd) {
    setObjectThatContainsThisObjectAsAMember(memberToAdd, self);
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(self),
                                getDestructorMemberList(self), memberName,
                                memberToAdd);
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            memberToAdd,
            getPublicDestructorAndRemoveFromPublicAccessModifierAndDestructorMemberList);
}

/* --------------- Fields --------------- */

// "public" function.
void addPrivateField(Object *self, char *memberName, Object *memberToAdd) {
    setObjectThatContainsThisObjectAsAMember(memberToAdd, self);
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(self),
                                getFieldsMemberList(self), memberName,
                                memberToAdd);
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            memberToAdd,
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList);
}

// "public" function.
void addPublicField(Object *self, char *memberName, Object *memberToAdd) {
    setObjectThatContainsThisObjectAsAMember(memberToAdd, self);
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(self),
                                getFieldsMemberList(self), memberName,
                                memberToAdd);
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            memberToAdd,
            getPublicFieldAndRemoveFromPublicAccessModifierAndFieldsMemberList);
}

/* ---------------------------- Implementation ------------------------------ */

// "public" function. TODO: remove redundant code
void addImplementation(
        Object *self, char *memberName,
        Object *(
                *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(
                const char *) ) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);

    addPublicField(
            self, (char *) implementationMemberName,
            constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter(
                    getLegacyObjectComponent(self)->CLASS_NAME));

    free((void *) implementationMemberName);
}

// "public" function.
void addImplementationThatIsConstructedWithLegacy_Object(
        Object *self, char *memberName,
        Object *(
                *constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter)(
                Legacy_Object *) ) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);

    addPublicField(
            self, (char *) implementationMemberName,
            constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter(
                    (Legacy_Object *) self));

    free((void *) implementationMemberName);
}

// "public" function.
Legacy_Object *getImplementation(Object *self, char *memberName) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);
    Legacy_Object *returnValue =
            getPublicField(self, (char *) implementationMemberName);
    free((void *) implementationMemberName);
    return returnValue;
}


/* ----------------------- Constructor & Destructor ------------------------= */

// "private" function.
void invokeDestructorOfAllNodesAndDoNotDeleteTheNodesFromMemberList(
        Legacy_MemberList *legacyMemberList) {
    if (legacyMemberList == NULL) { return; }
    Legacy_List *list = legacyMemberList->memberEntryList;
    if (list == NULL) { return; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->tail; iterationNode != NULL;
         iterationNode              = iterationNode->prev) {
        if (iterationNodePrev != NULL) {
            Legacy_StringObjectContainerEntry *entry = iterationNodePrev->data;
            Object *object = (Object *) entry->value;
            destruct(object);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->head`.
    if (iterationNodePrev != NULL) {
        Legacy_StringObjectContainerEntry *entry = iterationNodePrev->data;
        Object *object = (Object *) entry->value;
        destruct(object);
    }
}

/* ----------------------- Constructor & Destructor ------------------------= */

/// TODO: public. TODO: test if we can invoke the `destruct` multiple times and
///     it will be still okay. maybe rename to something secret.
void *destruct(Object *object) {
    if (object == NULL) { return NULL; }

    // Destruct `methodsLegacy_MemberList`.
    invokeDestructorOfAllNodesAndDoNotDeleteTheNodesFromMemberList(
            getMethodsMemberList(object));
    // Destruct `methodsLegacy_MemberList` supposing it is empty of Nodes.
    free(getMethodsMemberList(object)->memberEntryList->legacyObjectComponent);
    free(getMethodsMemberList(object)->memberEntryList);
    free(getMethodsMemberList(object)->legacyObjectComponent);
    free(getMethodsMemberList(object));

    // Destruct `constructorLegacy_MemberList`.
    invokeDestructorOfAllNodesAndDoNotDeleteTheNodesFromMemberList(
            getConstructorMemberList(object));
    // Destruct `constructorLegacy_MemberList` supposing it is empty of Nodes.
    free(getConstructorMemberList(object)
                 ->memberEntryList->legacyObjectComponent);
    free(getConstructorMemberList(object)->memberEntryList);
    free(getConstructorMemberList(object)->legacyObjectComponent);
    free(getConstructorMemberList(object));

    // Destruct `destructorLegacy_MemberList`.
    invokeDestructorOfAllNodesAndDoNotDeleteTheNodesFromMemberList(
            getDestructorMemberList(object));
    // Destruct `destructorLegacy_MemberList` supposing it is empty of Nodes.
    free(getDestructorMemberList(object)
                 ->memberEntryList->legacyObjectComponent);
    free(getDestructorMemberList(object)->memberEntryList);
    free(getDestructorMemberList(object)->legacyObjectComponent);
    free(getDestructorMemberList(object));

    // Destruct `fieldsLegacy_MemberList`.
    invokeDestructorOfAllNodesAndDoNotDeleteTheNodesFromMemberList(
            getFieldsMemberList(object));
    // Destruct `fieldsLegacy_MemberList` supposing it is empty of Nodes.
    free(getFieldsMemberList(object)->memberEntryList->legacyObjectComponent);
    free(getFieldsMemberList(object)->memberEntryList);
    free(getFieldsMemberList(object)->legacyObjectComponent);
    free(getFieldsMemberList(object));

    // Destruct `privateMemberNameLegacy_List` supposing it is empty of Nodes.
    free(getPrivateMemberNameLegacy_List(object)->legacyObjectComponent);
    free(getPrivateMemberNameLegacy_List(object));

    // Destruct `publicMemberNameLegacy_List` supposing it is empty of Nodes.
    free(getPublicMemberNameLegacy_List(object)->legacyObjectComponent);
    free(getPublicMemberNameLegacy_List(object));

//
//    // Destruct `privateMemberNameLegacy_List` knowing it is empty from Nodes.
//    getPrivateMemberNameLegacy_List(object)
//            ->legacyObjectComponent->destructable->destructor(
//                    getPrivateMemberNameLegacy_List(object));
//
//    // Destruct `publicMemberNameLegacy_List` knowing it is empty from Nodes.
//    getPublicMemberNameLegacy_List(object)
//            ->legacyObjectComponent->destructable->destructor(
//                    getPublicMemberNameLegacy_List(object));

    // Invoke `getFunctionToInvokeWhenObjectIsAboutToBeDestructed`.
    Legacy_Object *(*functionToInvoke)(Object *, Object *) =
            getFunctionToInvokeWhenObjectIsAboutToBeDestructed(object);
    functionToInvoke(object, getObjectThatContainsThisObjectAsAMember(object));

    // Destruct `autoDestructable`.
    AutoDestructableDestructor(
            (AutoDestructable *) getAutoDestructable(object));

    // Destruct `legacyObjectComponent`.
    free(getLegacyObjectComponent(object));

    free(object);

    return NULL;
}

void init_fields(Object *object) {
    setPrivateMemberNameLegacy_List(object, Legacy_ListConstructor());
    setPublicMemberNameLegacy_List(object, Legacy_ListConstructor());
    setMethodsMemberList(object, Legacy_MemberListConstructor());
    setConstructorMemberList(object, Legacy_MemberListConstructor());
    setDestructorMemberList(object, Legacy_MemberListConstructor());
    setFieldsMemberList(object, Legacy_MemberListConstructor());
    setFunctionToInvokeWhenObjectIsAboutToBeDestructed(
            object, getNoMemberAndRemoveFromNoAccessModifierAndNoMemberList);
    setMemberName(object, NULL);
    setObjectThatContainsThisObjectAsAMember(object, NULL);

    object->getPrivateMethod      = &getPrivateMethod;
    object->getPublicMethod       = &getPublicMethod;
    object->getPrivateConstructor = &getPrivateConstructor;
    object->getPublicConstructor  = &getPublicConstructor;
    object->getPrivateDestructor  = &getPrivateDestructor;
    object->getPublicDestructor   = &getPublicDestructor;
    object->getPrivateField       = &getPrivateField;
    object->getPublicField        = &getPublicField;
    object->getImplementation     = &getImplementation;

    object->addPrivateMethod      = &addPrivateMethod;
    object->addPublicMethod       = &addPublicMethod;
    object->addPrivateConstructor = &addPrivateConstructor;
    object->addPublicConstructor  = &addPublicConstructor;
    object->addPrivateDestructor  = &addPrivateDestructor;
    object->addPublicDestructor   = &addPublicDestructor;
    object->addPrivateField       = &addPrivateField;
    object->addPublicField        = &addPublicField;
    object->addImplementation     = &addImplementation;
    object->addImplementationThatIsConstructedWithLegacy_Object =
            &addImplementationThatIsConstructedWithLegacy_Object;
}

/// TODO: public. maybe rename to something secret.
/**
 * memory allocating `sizeof(Object)`, then invoking legacy_ObjectComponent's
 * constructor, and MemberList's constructor.
 */
Object *construct(char *className) {
    Object *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    setLegacyObjectComponent(
            instance, Legacy_ObjectComponentConstructorClassName(className));

    init_fields(instance);

    setAutoDestructable(instance, AutoDestructableConstructorWithLegacy_Object(
                                          (Legacy_Object *) instance));

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&construct)};
    getLegacyObjectComponent(instance)->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&destruct)};
    getLegacyObjectComponent(instance)->destructable = &destructable;

    return instance;
}
