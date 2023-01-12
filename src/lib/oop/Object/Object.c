#include "Object.r"
#include "../Atomic/AtomicRValue.h"

/* --------------------------------- Extern --------------------------------- */

extern RValue getData_AtomicRValue(AtomicRValue *atomicRValue);

extern void *getData_AtomicLValue(AtomicLValue *atomicLValue);

/* ---------------------------- GET POINTER VALUE --------------------------- */

// "protected" function.
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

// "protected" function.
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

// "protected" function.
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

// "protected" function.
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

/* ----------------- Generic GET MEMBER ------------------ */

// "private" function.
TYPEOF_ANONYMOUS_POINTER
getMemberValue_Logic(Legacy_List *      accessModifierLegacyList,
                     Legacy_MemberList *legacyMemberList, char *memberName) {
    Legacy_Object *legacyObject = getAccessModifierMember(
            accessModifierLegacyList, legacyMemberList, memberName);

    TYPEOF_ANONYMOUS_POINTER returnValue =
            (TYPEOF_ANONYMOUS_POINTER)((Object *) legacyObject);

    if (strcmp(legacyObject->legacyObjectComponent->CLASS_NAME,
               "AtomicRValue") == 0) {
        returnValue = (TYPEOF_ANONYMOUS_POINTER) getData_AtomicRValue(
                (AtomicRValue *) legacyObject);
    } else if (strcmp(legacyObject->legacyObjectComponent->CLASS_NAME,
                      "AtomicLValue") == 0) {
        returnValue = (TYPEOF_ANONYMOUS_POINTER) getData_AtomicLValue(
                (AtomicLValue *) legacyObject);
    }

    return returnValue;
}

// "public" function.
TYPEOF_ANONYMOUS_POINTER getMemberValue(Object *            self,
                                        enum AccessModifier accessModifier,
                                        enum MemberType     memberType,
                                        const char *        memberName) {
    Legacy_List *      accessModifierLegacyList = NULL;
    Legacy_MemberList *legacyMemberList         = NULL;

    switch (accessModifier) {
        case PRIVATE:
            accessModifierLegacyList = getPrivateMemberNameLegacy_List(self);
            break;

        case PUBLIC:
            accessModifierLegacyList = getPublicMemberNameLegacy_List(self);
            break;
    }

    switch (memberType) {
        case METHOD:
            legacyMemberList = getMethodsMemberList(self);
            break;

        case CONSTRUCTOR:
            legacyMemberList = getConstructorMemberList(self);
            break;

        case DESTRUCTOR:
            legacyMemberList = getDestructorMemberList(self);
            break;

        case FIELD:
            legacyMemberList = getFieldsMemberList(self);
            break;
    }

    return getMemberValue_Logic(accessModifierLegacyList, legacyMemberList,
                                (char *) memberName);
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

// "protected" function.
Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
        char *memberName, Object *objectThatContainsThisObjectAsAMember) {
    if (objectThatContainsThisObjectAsAMember == NULL) { return NULL; }
    return getAccessModifierMemberAndRemoveFromList(
            getPrivateMemberNameLegacy_List(
                    objectThatContainsThisObjectAsAMember),
            getFieldsMemberList(objectThatContainsThisObjectAsAMember),
            memberName);
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

// "protected" function.
void addPrimitiveAccessModifierMemberList(Legacy_List *accessModifierLegacyList,
                                          Legacy_MemberList *legacyMemberList,
                                          char *memberName, void *memberToAdd) {

    // Add `memberName` to accessModifierList.
    accessModifierLegacyList->addAsUnique(
            accessModifierLegacyList,
            Legacy_NodeConstructorWithData(memberName),
            predicateFindAccessModifierMemberNameByMemberName, memberName);

    // Add member to MemberList.
    legacyMemberList->addMemberWhichIsPrimitive(legacyMemberList, memberName,
                                                memberToAdd);
}

// "protected" function.
void addPrimitiveAccessModifierMemberListWhichIsStaticallyAllocated(
        Legacy_List *      accessModifierLegacyList,
        Legacy_MemberList *legacyMemberList, char *memberName,
        void *memberToAdd) {

    // Add `memberName` to accessModifierList.
    accessModifierLegacyList->addAsUnique(
            accessModifierLegacyList,
            Legacy_NodeConstructorWithData(memberName),
            predicateFindAccessModifierMemberNameByMemberName, memberName);

    // Add member to MemberList.
    legacyMemberList->addMemberWhichIsLegacy_Object(
            legacyMemberList, memberName,
            (Legacy_Object *) Legacy_NodeConstructorWithData(memberToAdd));
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

// "protected" function.
void addPrimitivePrivateField(Object *self, char *memberName,
                              void *dynamicallyAllocatedMemberToAdd) {
    setObjectThatContainsThisObjectAsAMember(self, self);
    addPrimitiveAccessModifierMemberList(getPrivateMemberNameLegacy_List(self),
                                         getFieldsMemberList(self), memberName,
                                         dynamicallyAllocatedMemberToAdd);
}

// "protected" function.
void addPrimitivePrivateFieldWhichIsStaticallyAllocated(
        Object *self, char *memberName, void *staticallyAllocatedMemberToAdd) {
    setObjectThatContainsThisObjectAsAMember(self, self);
    addPrimitiveAccessModifierMemberListWhichIsStaticallyAllocated(
            getPrivateMemberNameLegacy_List(self), getFieldsMemberList(self),
            memberName, staticallyAllocatedMemberToAdd);
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

/* ----------------- Generic ADD MEMBER ------------------ */

// "public" function.
void addMemberValue(Object *self, enum AccessModifier accessModifier,
                    enum MemberType memberType, const char *memberName,
                    Object *memberToAdd) {
    switch (accessModifier) {
        case PRIVATE:
            switch (memberType) {
                case METHOD:
                    addPrivateMethod(self, (char *) memberName, memberToAdd);
                    break;

                case CONSTRUCTOR:
                    addPrivateConstructor(self, (char *) memberName,
                                          memberToAdd);
                    break;

                case DESTRUCTOR:
                    addPrivateDestructor(self, (char *) memberName,
                                         memberToAdd);
                    break;

                case FIELD:
                    addPrivateField(self, (char *) memberName, memberToAdd);
                    break;
            }
            break;

        case PUBLIC:
            switch (memberType) {
                case METHOD:
                    addPublicMethod(self, (char *) memberName, memberToAdd);
                    break;

                case CONSTRUCTOR:
                    addPublicConstructor(self, (char *) memberName,
                                         memberToAdd);
                    break;

                case DESTRUCTOR:
                    addPublicDestructor(self, (char *) memberName, memberToAdd);
                    break;

                case FIELD:
                    addPublicField(self, (char *) memberName, memberToAdd);
                    break;
            }
            break;
    }
}

/* ---------------------------- Implementation ------------------------------ */

// "public" function. TODO: remove redundant code
void addImplementation(
        Object *self, char *memberName,
        Object *(
                *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(
                const char *) ) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);

    addMemberValue(
            self, PUBLIC, FIELD, (char *) implementationMemberName,
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

    addMemberValue(
            self, PUBLIC, FIELD, (char *) implementationMemberName,
            constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter(
                    (Legacy_Object *) self));

    free((void *) implementationMemberName);
}

// "public" function.
// TODO: change return type to (Object *)
Legacy_Object *getImplementation(Object *self, char *memberName) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);
    Legacy_Object *returnValue           = (Legacy_Object *) getMemberValue(
            self, PUBLIC, FIELD, (char *) implementationMemberName);
    free((void *) implementationMemberName);
    return returnValue;
}


/* ----------------------- Destructor Private ------------------------= */

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
            entry->value->legacyObjectComponent->destructable->destructor(
                    entry->value);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->head`.
    if (iterationNodePrev != NULL) {
        Legacy_StringObjectContainerEntry *entry = iterationNodePrev->data;
        entry->value->legacyObjectComponent->destructable->destructor(
                entry->value);
    }
}

// "private" function.
void destructMemberList(Legacy_MemberList *legacyMemberList) {

    // Destruct `legacyMemberList` Legacy_Objects.
    invokeDestructorOfAllNodesAndDoNotDeleteTheNodesFromMemberList(
            legacyMemberList);

    // Destruct `legacyMemberList` supposing it is empty of Nodes.
    free(legacyMemberList->memberEntryList->legacyObjectComponent);
    free(legacyMemberList->memberEntryList);
    free(legacyMemberList->legacyObjectComponent);
    free(legacyMemberList);
}

// "private" function.
void destructAccessModifierList(Legacy_List *legacyList) {

    // Destruct `accessModifierLegacy_List` supposing it is empty of Nodes.
    free(legacyList->legacyObjectComponent);
    free(legacyList);
}

// "private" function.
void destructObjectMembers(Object *object) {
    if (object == NULL) { return; }

    // Destruct `methodsLegacy_MemberList`.
    destructMemberList(getMethodsMemberList(object));

    // Destruct `constructorLegacy_MemberList`.
    destructMemberList(getConstructorMemberList(object));

    // Destruct `destructorLegacy_MemberList`.
    destructMemberList(getDestructorMemberList(object));

    // Destruct `fieldsLegacy_MemberList`.
    destructMemberList(getFieldsMemberList(object));

    // Destruct `privateMemberNameLegacy_List`.
    destructAccessModifierList(getPrivateMemberNameLegacy_List(object));

    // Destruct `publicMemberNameLegacy_List`.
    destructAccessModifierList(getPublicMemberNameLegacy_List(object));
}

// "private" function.
void destructObjectSelf(Object *object) {
    if (object == NULL) { return; }

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
}

/* ----------------------- Constructor & Destructor ------------------------= */

/// TODO: public. TODO: test if we can invoke the `ObjectDestructor` multiple times and
///     it will be still okay. maybe rename to something secret.
void *ObjectDestructor(Object *object) {
    if (object == NULL) { return NULL; }

    destructObjectMembers(object);
    destructObjectSelf(object);

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

    object->getMemberValue    = &getMemberValue;
    object->getImplementation = &getImplementation;

    object->addMemberValue    = &addMemberValue;
    object->addImplementation = &addImplementation;
    object->addImplementationThatIsConstructedWithLegacy_Object =
            &addImplementationThatIsConstructedWithLegacy_Object;
}

// "protected" function.
Object *ObjectConstructorWithoutAnyMembers(char *className) {
    Object *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    setLegacyObjectComponent(
            instance, Legacy_ObjectComponentConstructorClassName(className));

    init_fields(instance);

    setAutoDestructable(instance, AutoDestructableConstructorWithLegacy_Object(
                                          (Legacy_Object *) instance));

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ObjectDestructor)};
    getLegacyObjectComponent(instance)->destructable = &destructable;

    return instance;
}

/// TODO: public. maybe rename to something secret.
/**
 * memory allocating `sizeof(Object)`, then invoking legacy_ObjectComponent's
 * constructor, and MemberList's constructor.
 */
Object *ObjectConstructor(char *className) {
    Object *instance = ObjectConstructorWithoutAnyMembers(className);

    addMemberValue(
            instance, PUBLIC, CONSTRUCTOR, DEFAULT_CONSTRUCTOR,
            (Object *) AtomicLValueConstructor(&ObjectConstructor, FALSE));

    addMemberValue(
            instance, PUBLIC, DESTRUCTOR, DEFAULT_DESTRUCTOR,
            (Object *) AtomicLValueConstructor(&ObjectDestructor, FALSE));

    return instance;
}

void addIntegerRValueMember(Object *self, enum AccessModifier accessModifier,
                            enum MemberType memberType, const char *memberName,
                            IntegerRValue integerRValue) {
    addMemberValue(self, accessModifier, memberType, memberName,
                   INTEGER_RVALUE_AS_OBJECT(integerRValue));
}

IntegerRValue getIntegerRValueMember(Object *            self,
                                     enum AccessModifier accessModifier,
                                     enum MemberType     memberType,
                                     const char *        memberName) {
    return getMemberValue(self, accessModifier, memberType, memberName);
}

void addDoubleRValueMember(Object *self, enum AccessModifier accessModifier,
                           enum MemberType memberType, const char *memberName,
                           DoubleRValue doubleRValue) {
    TYPEOF_ANONYMOUS_POINTER wholeNumber =
            (TYPEOF_ANONYMOUS_POINTER) doubleRValue;

    TYPEOF_ANONYMOUS_POINTER mantissaNumber =
            (TYPEOF_ANONYMOUS_POINTER)(doubleRValue - wholeNumber);

    // "Whole" number as IntegerRValue.
    const char *wholeNumberMemberName =
            concat(memberName, __DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__);
    addIntegerRValueMember(self, accessModifier, memberType,
                           wholeNumberMemberName, wholeNumber);
    free((void *) wholeNumberMemberName);

    // "Mantissa" number as IntegerRValue.
    const char *mantissaNumberMemberName =
            concat(memberName, __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__);
    addIntegerRValueMember(self, accessModifier, memberType,
                           mantissaNumberMemberName, mantissaNumber);
    free((void *) mantissaNumberMemberName);
}

DoubleRValue getDoubleRValueMember(Object *            self,
                                   enum AccessModifier accessModifier,
                                   enum MemberType     memberType,
                                   const char *        memberName) {

    // "Whole" number as IntegerRValue.
    const char *wholeNumberMemberName =
            concat(memberName, __DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__);
    DoubleRValue wholeNumber = (DoubleRValue) getIntegerRValueMember(
            self, accessModifier, memberType, wholeNumberMemberName);
    free((void *) wholeNumberMemberName);

    // "Mantissa" number as IntegerRValue.
    const char *mantissaNumberMemberName =
            concat(memberName, __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__);
    DoubleRValue mantissaNumber = (DoubleRValue) getIntegerRValueMember(
            self, accessModifier, memberType, mantissaNumberMemberName);
    free((void *) mantissaNumberMemberName);

    return wholeNumber + mantissaNumber;
}
