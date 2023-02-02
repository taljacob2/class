#include "Object.r"
#include "../Atomic/AtomicDoubleRValue.h"

/* --------------------------------- Extern --------------------------------- */

/* ------- GET ------- */

extern void *getData_AtomicLValue(AtomicLValue *atomicLValue);

extern IntegerRValue
getData_AtomicIntegerRValue(AtomicIntegerRValue *atomicIntegerRValue);

extern DoubleRValue
getData_AtomicDoubleRValue(AtomicDoubleRValue *atomicDoubleRValue);

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
AutoDestructable *getAutoDestructable(Object *object) {
    return (AutoDestructable *) getAnonymousPointerValueByIndex(object, 7);
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
BOOLEAN
isAccessModifierLegacyListContainsMember(Legacy_List *accessModifierLegacyList,
                                         char *       memberName) {
    return accessModifierLegacyList->findNodeByPredicateOfConstString(
                   accessModifierLegacyList,
                   predicateFindAccessModifierMemberNameByMemberName,
                   memberName) != NULL;
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
Legacy_List *getAccessModifierLegacyListByAccessModifier(
        Object *self, enum MemberAccessModifier memberAccessModifier) {
    Legacy_List *accessModifierLegacyList = NULL;

    switch (memberAccessModifier) {
        case PRIVATE:
            accessModifierLegacyList = getPrivateMemberNameLegacy_List(self);
            break;

        case PUBLIC:
            accessModifierLegacyList = getPublicMemberNameLegacy_List(self);
            break;
    }

    return accessModifierLegacyList;
}

// "private" function.
Legacy_MemberList *getLegacyMemberListByMemberType(Object *        self,
                                                   enum MemberType memberType) {
    Legacy_MemberList *legacyMemberList = NULL;

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

    return legacyMemberList;
}

// "protected" function.
Legacy_Object *
getLegacyObjectMember(Object *                  self,
                      enum MemberAccessModifier memberAccessModifier,
                      enum MemberType memberType, const char *memberName) {
    Legacy_List *accessModifierLegacyList =
            getAccessModifierLegacyListByAccessModifier(self,
                                                        memberAccessModifier);
    Legacy_MemberList *legacyMemberList =
            getLegacyMemberListByMemberType(self, memberType);

    Legacy_Object *legacyObject = getAccessModifierMember(
            accessModifierLegacyList, legacyMemberList, (char *) memberName);

    // TODO: DEBUG. Need to print to stderr, with `__LINE__` and `__FILE__` locations.
    if (legacyObject == NULL) {
        fprintf(stderr, "The memberName `%s` was not found in the Object.\n",
                memberName);
    }

    return legacyObject;
}

// "public" function.
Object *getObjectMember(Object *                  self,
                        enum MemberAccessModifier memberAccessModifier,
                        enum MemberType memberType, const char *memberName) {
    Legacy_Object *legacyObject = getLegacyObjectMember(
            self, memberAccessModifier, memberType, memberName);

    Object *returnValue = (Object *) legacyObject;

    return returnValue;
}

// "public" function.
LValue getLValueMember(Object *                  self,
                       enum MemberAccessModifier memberAccessModifier,
                       enum MemberType memberType, const char *memberName) {
    Legacy_Object *legacyObject = getLegacyObjectMember(
            self, memberAccessModifier, memberType, memberName);

    void *returnValue = NULL;

    if (legacyObject != NULL &&
        strcmp(legacyObject->legacyObjectComponent->CLASS_NAME,
               "AtomicLValue") == 0) {
        returnValue =
                (void *) getData_AtomicLValue((AtomicLValue *) legacyObject);
    }

    return (LValue) returnValue;
}

// TODO: make public.
// "public" function.
IntegerRValue
getIntegerRValueMember(Object *                  self,
                       enum MemberAccessModifier memberAccessModifier,
                       enum MemberType memberType, const char *memberName) {
    Legacy_Object *legacyObject = getLegacyObjectMember(
            self, memberAccessModifier, memberType, memberName);

    IntegerRValue returnValue = 0;

    if (legacyObject != NULL &&
        strcmp(legacyObject->legacyObjectComponent->CLASS_NAME,
               "AtomicIntegerRValue") == 0) {
        returnValue = (IntegerRValue) getData_AtomicIntegerRValue(
                (AtomicIntegerRValue *) legacyObject);
    }

    return returnValue;
}

// TODO: make public.
// "public" function.
DoubleRValue
getDoubleRValueMember(Object *                  self,
                      enum MemberAccessModifier memberAccessModifier,
                      enum MemberType memberType, const char *memberName) {
    Legacy_Object *legacyObject = getLegacyObjectMember(
            self, memberAccessModifier, memberType, memberName);

    DoubleRValue returnValue = 0;

    if (legacyObject != NULL &&
        strcmp(legacyObject->legacyObjectComponent->CLASS_NAME,
               "AtomicDoubleRValue") == 0) {
        returnValue = (DoubleRValue) getData_AtomicDoubleRValue(
                (AtomicDoubleRValue *) legacyObject);
    }

    return returnValue;
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
void addPrimitivePrivateFieldWhichIsDynamicallyAllocated(
        Object *self, char *memberName, void *dynamicallyAllocatedMemberToAdd) {
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
void addObjectMember(Object *                  self,
                     enum MemberAccessModifier memberAccessModifier,
                     enum MemberType memberType, const char *memberName,
                     Object *memberToAdd) {
    switch (memberAccessModifier) {
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

// "public" function.
void addLValueMember(Object *                  self,
                     enum MemberAccessModifier memberAccessModifier,
                     enum MemberType memberType, const char *memberName,
                     LValue lValueData, BOOLEAN isDataDynamicallyAllocated) {
    AtomicLValue *atomicLValue =
            AtomicLValueConstructor(lValueData, isDataDynamicallyAllocated);

    if (memberType == DESTRUCTOR) {

        // Abort `AutoDestructable` by destructing it.
        AutoDestructableDestructor(
                getAutoDestructable((Object *) atomicLValue));
        setAutoDestructable((Object *) atomicLValue, NULL);
    }

    addObjectMember(self, memberAccessModifier, memberType, memberName,
                    (Object *) atomicLValue);
}

// "public" function.
void addIntegerRValueMember(Object *                  self,
                            enum MemberAccessModifier memberAccessModifier,
                            enum MemberType memberType, const char *memberName,
                            IntegerRValue integerRValue) {
    addObjectMember(self, memberAccessModifier, memberType, memberName,
                    (Object *) AtomicIntegerRValueConstructor(integerRValue));
}

// "public" function.
void addDoubleRValueMember(Object *                  self,
                           enum MemberAccessModifier memberAccessModifier,
                           enum MemberType memberType, const char *memberName,
                           DoubleRValue doubleRValue) {
    addObjectMember(self, memberAccessModifier, memberType, memberName,
                    (Object *) AtomicDoubleRValueConstructor(doubleRValue));
}

/* ----------------------------- SET MEMBER --------------------------------- */

// "protected" function.
void setPrimitiveAccessModifierMemberListWhichIsDynamicallyAllocated(
        Legacy_MemberList *legacyMemberList, char *memberName,
        void *memberToSet) {

    // Set member to MemberList.
    legacyMemberList->setMemberWhichIsPrimitive(legacyMemberList, memberName,
                                                memberToSet);
}

// "protected" function.
void setPrimitiveAccessModifierMemberListWhichIsStaticallyAllocated(
        Legacy_MemberList *legacyMemberList, char *memberName,
        void *memberToSet) {

    // Set member to MemberList.
    legacyMemberList->setMemberWhichIsLegacy_Object(
            legacyMemberList, memberName,
            (Legacy_Object *) Legacy_NodeConstructorWithData(memberToSet));
}

// "protected" function.
void setPrimitivePrivateFieldWhichIsDynamicallyAllocated(
        Object *self, char *memberName, void *dynamicallyAllocatedMemberToSet) {
    setObjectThatContainsThisObjectAsAMember(self, self);
    setPrimitiveAccessModifierMemberListWhichIsDynamicallyAllocated(
            getFieldsMemberList(self), memberName,
            dynamicallyAllocatedMemberToSet);
}

// "protected" function.
void setPrimitivePrivateFieldWhichIsStaticallyAllocated(
        Object *self, char *memberName, void *staticallyAllocatedMemberToSet) {
    setObjectThatContainsThisObjectAsAMember(self, self);
    setPrimitiveAccessModifierMemberListWhichIsStaticallyAllocated(
            getFieldsMemberList(self), memberName,
            staticallyAllocatedMemberToSet);
}

/* ----------------- Generic SET MEMBER ------------------ */

// "private" function.
void getAccessModifierAndMemberType(
        Object *object, enum MemberAccessModifier *outMemberAccessModifier,
        enum MemberType *outMemberType) {
    const int THE_GIVEN_OBJECT_HAS_NO_PARENT_OBJECTS = -1;

    Legacy_Object *(*functionToInvoke)(Object *, Object *) =
            getFunctionToInvokeWhenObjectIsAboutToBeDestructed(object);
    if (functionToInvoke ==
        &getPrivateMethodAndRemoveFromPrivateAccessModifierAndMethodsMemberList) {
        *outMemberAccessModifier = PRIVATE;
        *outMemberType           = METHOD;
    } else if (
            functionToInvoke ==
            &getPublicMethodAndRemoveFromPublicAccessModifierAndMethodsMemberList) {
        *outMemberAccessModifier = PUBLIC;
        *outMemberType           = METHOD;
    } else if (
            functionToInvoke ==
            &getPrivateConstructorAndRemoveFromPrivateAccessModifierAndConstructorMemberList) {
        *outMemberAccessModifier = PRIVATE;
        *outMemberType           = CONSTRUCTOR;
    } else if (
            functionToInvoke ==
            &getPublicConstructorAndRemoveFromPublicAccessModifierAndConstructorMemberList) {
        *outMemberAccessModifier = PUBLIC;
        *outMemberType           = CONSTRUCTOR;
    } else if (
            functionToInvoke ==
            &getPrivateDestructorAndRemoveFromPrivateAccessModifierAndDestructorMemberList) {
        *outMemberAccessModifier = PRIVATE;
        *outMemberType           = DESTRUCTOR;
    } else if (
            functionToInvoke ==
            &getPublicDestructorAndRemoveFromPublicAccessModifierAndDestructorMemberList) {
        *outMemberAccessModifier = PUBLIC;
        *outMemberType           = DESTRUCTOR;
    } else if (
            functionToInvoke ==
            &getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList) {
        *outMemberAccessModifier = PRIVATE;
        *outMemberType           = FIELD;
    } else if (
            functionToInvoke ==
            &getPublicFieldAndRemoveFromPublicAccessModifierAndFieldsMemberList) {
        *outMemberAccessModifier = PUBLIC;
        *outMemberType           = FIELD;
    } else if (functionToInvoke ==
               &getNoMemberAndRemoveFromNoAccessModifierAndNoMemberList) {
        *outMemberAccessModifier = THE_GIVEN_OBJECT_HAS_NO_PARENT_OBJECTS;
        *outMemberType           = THE_GIVEN_OBJECT_HAS_NO_PARENT_OBJECTS;
    }
}

// "public" function.
Object *setSelf(Object *self, Object *value) {
    if (self == NULL) { return NULL; }

    getLegacyObjectComponent(self)->destructable->destructor(self);
    self = value;

    return value;
}

// "public" function.
Object *setObjectMember(Object *                  self,
                        enum MemberAccessModifier memberAccessModifier,
                        enum MemberType memberType, const char *memberName,
                        Object *memberValueToSet) {
    if (self == NULL) { return NULL; }

    Object *objectMember =
            getObjectMember(self, memberAccessModifier, memberType, memberName);
    if (objectMember == NULL) { return NULL; }

    getLegacyObjectComponent(objectMember)
            ->destructable->destructor(objectMember);
    addObjectMember(self, memberAccessModifier, memberType, memberName,
                    memberValueToSet);

    return memberValueToSet;
}

// "public" function.
LValue setLValueMember(Object *                  self,
                       enum MemberAccessModifier memberAccessModifier,
                       enum MemberType memberType, const char *memberName,
                       LValue  lValueDataValueToSet,
                       BOOLEAN isDataDynamicallyAllocatedValueToSet) {
    if (self == NULL) { return (LValue) NULL; }

    Object *objectMember =
            getObjectMember(self, memberAccessModifier, memberType, memberName);
    if (objectMember == NULL) { return (LValue) NULL; }

    getLegacyObjectComponent(objectMember)
            ->destructable->destructor(objectMember);
    addLValueMember(self, memberAccessModifier, memberType, memberName,
                    lValueDataValueToSet, isDataDynamicallyAllocatedValueToSet);

    return lValueDataValueToSet;
}

// "public" function.
BOOLEAN
setIntegerRValueMember(Object *                  self,
                       enum MemberAccessModifier memberAccessModifier,
                       enum MemberType memberType, const char *memberName,
                       IntegerRValue integerRValueValueToSet) {
    if (self == NULL) { return FALSE; }

    Object *objectMember =
            getObjectMember(self, memberAccessModifier, memberType, memberName);
    if (objectMember == NULL) { return FALSE; }

    getLegacyObjectComponent(objectMember)
            ->destructable->destructor(objectMember);
    addIntegerRValueMember(self, memberAccessModifier, memberType, memberName,
                           integerRValueValueToSet);

    return TRUE;
}

// "public" function.
BOOLEAN
setDoubleRValueMember(Object *                  self,
                      enum MemberAccessModifier memberAccessModifier,
                      enum MemberType memberType, const char *memberName,
                      DoubleRValue doubleRValueValueToSet) {
    if (self == NULL) { return FALSE; }

    Object *objectMember =
            getObjectMember(self, memberAccessModifier, memberType, memberName);
    if (objectMember == NULL) { return FALSE; }

    getLegacyObjectComponent(objectMember)
            ->destructable->destructor(objectMember);
    addDoubleRValueMember(self, memberAccessModifier, memberType, memberName,
                          doubleRValueValueToSet);

    return TRUE;
}

/* ---------------------------- Implementation ------------------------------ */

// "public" function. TODO: remove redundant code
void addImplementation(
        Object *self, char *memberName,
        Object *(
                *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(
                const char *) ) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);

    addObjectMember(
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

    addObjectMember(
            self, PUBLIC, FIELD, (char *) implementationMemberName,
            constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter(
                    (Legacy_Object *) self));

    free((void *) implementationMemberName);
}

// "public" function.
// TODO: change return type to (Object *)
Legacy_Object *getImplementation(Object *self, char *memberName) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);
    Legacy_Object *returnValue           = (Legacy_Object *) getObjectMember(
            self, PUBLIC, FIELD, (char *) implementationMemberName);
    free((void *) implementationMemberName);
    return returnValue;
}

/* ------------------------------- toString --------------------------------= */

const char *
getAccessModifierToString(enum MemberAccessModifier memberAccessModifier) {
    switch (memberAccessModifier) {
        case PRIVATE:
            return "private";
        case PUBLIC:
            return "public";
        default:
            return NULL;
    }
}

const char *getMemberTypeToString(enum MemberType memberType) {
    switch (memberType) {
        case METHOD:
            return "METHOD";
        case CONSTRUCTOR:
            return "CONSTRUCTOR";
        case DESTRUCTOR:
            return "DESTRUCTOR";
        case FIELD:
            return "FIELD";
        default:
            return NULL;
    }
}

// "private" function.
void toString_ObjectMemberAccessModifierLegacy_ListPRIVATE(
        Legacy_List *             accessModifierList,
        enum MemberAccessModifier memberAccessModifier) {
    if (accessModifierList == NULL) {
        printf("NULL");
        return;
    }

    const char *accessModifierToString =
            getAccessModifierToString(memberAccessModifier);

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode           = accessModifierList->head;
         iterationNode != NULL; iterationNode = iterationNode->next) {
        if (iterationNodePrev != NULL) {
            if (iterationNodePrev != accessModifierList->head) {
                putchar('\n');
            }
            printf("%s", accessModifierToString);
            putchar(' ');
            printf("%s", (char *) iterationNodePrev->data);
            putchar(';');
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        if (iterationNodePrev != accessModifierList->head) { putchar('\n'); }
        printf("%s", accessModifierToString);
        putchar(' ');
        printf("%s", (char *) iterationNodePrev->data);
        putchar(';');
    }

    if (accessModifierList->size > 0) { putchar('\n'); }
}

// "public" function.
BOOLEAN toString_ObjectMemberAccessModifierList(
        Object *self, enum MemberAccessModifier memberAccessModifier) {
    Legacy_List *legacyList = getAccessModifierLegacyListByAccessModifier(
            self, memberAccessModifier);

    toString_ObjectMemberAccessModifierLegacy_ListPRIVATE(legacyList,
                                                          memberAccessModifier);

    return legacyList == NULL ? FALSE : (BOOLEAN) legacyList->size;
}

// "private" function.
enum MemberAccessModifier getAccessModifierOfMember(Object *self,
                                                    char *  memberName) {
    if (isPrivateMember(self, memberName)) {
        return PRIVATE;
    } else {
        return PUBLIC;
    }
}

// "private" function.
void toString_ObjectMemberTypeListPRIVATE(Object *           self,
                                          Legacy_MemberList *legacyMemberList,
                                          enum MemberType    memberType) {
    if (legacyMemberList == NULL) {
        printf("NULL");
        return;
    }
    if (legacyMemberList->memberEntryList == NULL) {
        printf("NULL");
        return;
    }

    const char *memberTypeToString = getMemberTypeToString(memberType);

    const Legacy_List *list = legacyMemberList->memberEntryList;

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev != NULL) {
            if (iterationNodePrev != list->head) { putchar('\n'); }
            Legacy_StringObjectContainerEntry *entry =
                    (Legacy_StringObjectContainerEntry *)
                            iterationNodePrev->data;
            char *memberName = (char *) entry->key;
            printf("%s", getAccessModifierToString(
                                 getAccessModifierOfMember(self, memberName)));
            putchar(' ');
            printf("%s", memberTypeToString);
            putchar(' ');
            printf("%s", (char *) memberName);
            putchar(';');
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        if (iterationNodePrev != list->head) { putchar('\n'); }
        Legacy_StringObjectContainerEntry *entry =
                (Legacy_StringObjectContainerEntry *) iterationNodePrev->data;
        char *memberName = (char *) entry->key;
        printf("%s", getAccessModifierToString(
                             getAccessModifierOfMember(self, memberName)));
        putchar(' ');
        printf("%s", memberTypeToString);
        putchar(' ');
        printf("%s", (char *) memberName);
        putchar(';');
    }

    if (list->size > 0) { putchar('\n'); }
}

// "public" function.
BOOLEAN toString_ObjectMemberTypeList(Object *        self,
                                      enum MemberType memberType) {
    Legacy_MemberList *legacyMemberList =
            getLegacyMemberListByMemberType(self, memberType);

    toString_ObjectMemberTypeListPRIVATE(self, legacyMemberList, memberType);

    if (legacyMemberList == NULL) { return FALSE; }
    const Legacy_List *list = legacyMemberList->memberEntryList;
    return list == NULL ? FALSE : (BOOLEAN) list->size;
}

// "public" function.
void toString_Object(Object *self) {

    printf("%s {", getLegacyObjectComponent(self)->CLASS_NAME);
    putchar('\n');

    toString_ObjectMemberAccessModifierList(self, PRIVATE) ? putchar('\n')
                                                           : FALSE;
    toString_ObjectMemberAccessModifierList(self, PUBLIC) ? putchar('\n')
                                                          : FALSE;

    toString_ObjectMemberTypeList(self, FIELD) ? putchar('\n') : FALSE;
    toString_ObjectMemberTypeList(self, CONSTRUCTOR) ? putchar('\n') : FALSE;
    toString_ObjectMemberTypeList(self, DESTRUCTOR) ? putchar('\n') : FALSE;
    toString_ObjectMemberTypeList(self, METHOD) ? putchar('\n') : FALSE;

    putchar('}');
    putchar('\n');
}

/* -------------------------- Destructor Private ---------------------------= */

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
    AutoDestructableDestructor(getAutoDestructable(object));

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

// TODO: Maybe remove. Redundant code.
void invokeAllDestructorsWithTheGivenAccessModifierInReversedOrder(
        Object *self, enum MemberAccessModifier memberAccessModifier) {
    Legacy_MemberList *destructorMemberList = getDestructorMemberList(self);
    Legacy_List *      accessModifierLegacyList =
            getAccessModifierLegacyListByAccessModifier(self,
                                                        memberAccessModifier);

    // TODO: in `Legacy_List`: make a Foreach and ForeachReversedOrder functions.
    //TODO:
    Legacy_List *list = destructorMemberList->memberEntryList;
    if (list == NULL) { return; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->tail; iterationNode != NULL;
         iterationNode              = iterationNode->prev) {
        if (iterationNodePrev != NULL) {
            Legacy_StringObjectContainerEntry *
                    legacy_StringObjectContainerEntry = iterationNodePrev->data;

            if (isAccessModifierLegacyListContainsMember(
                        accessModifierLegacyList,
                        legacy_StringObjectContainerEntry->key)) {
                AtomicLValue *atomicLValueThatContainsDestructor =
                        (AtomicLValue *)
                                legacy_StringObjectContainerEntry->value;

                // Get the destructor and invoke it.
                void *(*destructor)(Object *) =
                        (void *(*) (Object *) ) getData_AtomicLValue(
                                atomicLValueThatContainsDestructor);
                if (destructor != NULL) { destructor(self); }
            }
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->head`.
    if (iterationNodePrev != NULL) {
        Legacy_StringObjectContainerEntry *legacy_StringObjectContainerEntry =
                iterationNodePrev->data;

        if (isAccessModifierLegacyListContainsMember(
                    accessModifierLegacyList,
                    legacy_StringObjectContainerEntry->key)) {
            AtomicLValue *atomicLValueThatContainsDestructor =
                    (AtomicLValue *) legacy_StringObjectContainerEntry->value;

            // Get the destructor and invoke it.
            void *(*destructor)(Object *) =
                    (void *(*) (Object *) ) getData_AtomicLValue(
                            atomicLValueThatContainsDestructor);
            if (destructor != NULL) { destructor(self); }
        }
    }
}

void invokeAllDestructorsWithTheGivenAccessModifierInStraightOrder(
        Object *self, enum MemberAccessModifier memberAccessModifier) {
    Legacy_MemberList *destructorMemberList = getDestructorMemberList(self);
    Legacy_List *      accessModifierLegacyList =
            getAccessModifierLegacyListByAccessModifier(self,
                                                        memberAccessModifier);

    // TODO: in `Legacy_List`: make a Foreach and ForeachReversedOrder functions.
    //TODO:
    Legacy_List *list = destructorMemberList->memberEntryList;
    if (list == NULL) { return; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev != NULL) {
            Legacy_StringObjectContainerEntry *
                    legacy_StringObjectContainerEntry = iterationNodePrev->data;

            if (isAccessModifierLegacyListContainsMember(
                        accessModifierLegacyList,
                        legacy_StringObjectContainerEntry->key)) {
                AtomicLValue *atomicLValueThatContainsDestructor =
                        (AtomicLValue *)
                                legacy_StringObjectContainerEntry->value;

                // Get the destructor and invoke it.
                void *(*destructor)(Object *) =
                        (void *(*) (Object *) ) getData_AtomicLValue(
                                atomicLValueThatContainsDestructor);
                if (destructor != NULL) { destructor(self); }
            }
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        Legacy_StringObjectContainerEntry *legacy_StringObjectContainerEntry =
                iterationNodePrev->data;

        if (isAccessModifierLegacyListContainsMember(
                    accessModifierLegacyList,
                    legacy_StringObjectContainerEntry->key)) {
            AtomicLValue *atomicLValueThatContainsDestructor =
                    (AtomicLValue *) legacy_StringObjectContainerEntry->value;

            // Get the destructor and invoke it.
            void *(*destructor)(Object *) =
                    (void *(*) (Object *) ) getData_AtomicLValue(
                            atomicLValueThatContainsDestructor);
            if (destructor != NULL) { destructor(self); }
        }
    }
}

void *DefaultDestructor(Object *self) {

    /*
     * If `getLegacyObjectComponent(self)->destructable->destructor` was
     * overwritten, then invoke it.
     */
    if (getLegacyObjectComponent(self)->destructable->destructor !=
        (void *(*const)(void *) )(&DefaultDestructor)) {
        getLegacyObjectComponent(self)->destructable->destructor(self);
    } else {

        // Invoke all "public" destructors in straight order.
        invokeAllDestructorsWithTheGivenAccessModifierInStraightOrder(self,
                                                                      PUBLIC);
    }
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

    object->getObjectMember        = &getObjectMember;
    object->getLValueMember        = &getLValueMember;
    object->getIntegerRValueMember = &getIntegerRValueMember;
    object->getDoubleRValueMember  = &getDoubleRValueMember;
    object->getImplementation      = &getImplementation;

    object->addObjectMember        = &addObjectMember;
    object->addLValueMember        = &addLValueMember;
    object->addIntegerRValueMember = &addIntegerRValueMember;
    object->addDoubleRValueMember  = &addDoubleRValueMember;
    object->addImplementation = &addImplementation; // TODO: remove redundant.
    object->addImplementationThatIsConstructedWithLegacy_Object =
            &addImplementationThatIsConstructedWithLegacy_Object;

    object->setSelf                = &setSelf;
    object->setObjectMember        = &setObjectMember;
    object->setLValueMember        = &setLValueMember;
    object->setIntegerRValueMember = &setIntegerRValueMember;
    object->setDoubleRValueMember  = &setDoubleRValueMember;
    //    object->setImplementation = &setImplementation; // TODO:


    object->toStringMembersByMemberAccessModifier =
            &toString_ObjectMemberAccessModifierList;
    object->toStringMembersByMemberType = &toString_ObjectMemberTypeList;
    object->toString                    = &toString_Object;
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
            .destructor = (void *(*const)(void *) )(&DefaultDestructor)};
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

    // TODO: maybe redundant code.
    //    // TODO: make `DefaultConstructor` that invokes all constructors in straight order.
    //    instance->addLValueMember(instance, PUBLIC, CONSTRUCTOR,
    //                              "ObjectConstructor",
    //                              (LValue) &ObjectConstructor, FALSE);

    instance->addLValueMember(instance, PUBLIC, DESTRUCTOR,
                              "void *ObjectDestructor(Object *object)",
                              (LValue) &ObjectDestructor, FALSE);

    return instance;
}
