#include "Object.r"

/* ------------------------------ GET LIST ---------------------------------- */

// "private" function.
Legacy_ObjectComponent *getLegacyObject(Object *object) {
    return (Legacy_ObjectComponent *) getAnonymousPointerByIndex(object, 0);
}

// "private" function.
Legacy_List *getPrivateMemberNameLegacy_List(Object *object) {
    return (Legacy_List *) getAnonymousPointerByIndex(object, 1);
}

// "private" function.
Legacy_List *getPublicMemberNameLegacy_List(Object *object) {
    return (Legacy_List *) getAnonymousPointerByIndex(object, 2);
}

// "private" function.
MemberList *getMethodsMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerByIndex(object, 3);
}

// "private" function.
MemberList *getConstructorMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerByIndex(object, 4);
}

// "private" function.
MemberList *getDestructorMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerByIndex(object, 5);
}

// "private" function.
MemberList *getFieldsMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerByIndex(object, 6);
}

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
Legacy_Object *findMemberInMemberListByMemberName(MemberList *memberList,
                                                  char *      memberName) {
    return memberList->getMemberByName(memberList, memberName);
}

// "private" function.
Legacy_Object *getAccessModifierMember(Legacy_List *accessModifierLegacyList,
                                       MemberList * memberList,
                                       char *       memberName) {
    Legacy_Node *findAccessModifierMemberNameReturnValue =
            findAccessModifierMemberName(accessModifierLegacyList, memberName);
    if (findAccessModifierMemberNameReturnValue == NULL) { return NULL; }

    Legacy_Object *findMemberInMemberListByMemberNameReturnValue =
            findMemberInMemberListByMemberName(memberList, memberName);
    if (findMemberInMemberListByMemberNameReturnValue == NULL) { return NULL; }

    return findMemberInMemberListByMemberNameReturnValue;
}

/* ---------------------- Specific Access Modifier -------------------------- */

// "private" function.
Legacy_Object *getPrivateMember(Object *object, MemberList *memberList,
                                char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   memberList, memberName);
}

// "private" function.
Legacy_Object *getPublicMember(Object *object, MemberList *memberList,
                               char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   memberList, memberName);
}

/* ------------ Specific Access Modifier & Specific MemberList -------------- */

/* ------------- Methods ------------- */

// "private" function.
Legacy_Object *getPrivateMethod(Object *object, char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   getMethodsMemberList(object), memberName);
}

// "private" function.
Legacy_Object *getPublicMethod(Object *object, char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   getMethodsMemberList(object), memberName);
}

/* ------------- Constructor ------------- */

// "private" function.
Legacy_Object *getPrivateConstructor(Object *object, char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   getConstructorMemberList(object),
                                   memberName);
}

// "private" function.
Legacy_Object *getPublicConstructor(Object *object, char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   getConstructorMemberList(object),
                                   memberName);
}

/* ------------- Destructor ------------- */

// "private" function.
Legacy_Object *getPrivateDestructor(Object *object, char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   getDestructorMemberList(object), memberName);
}

// "private" function.
Legacy_Object *getPublicDestructor(Object *object, char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   getDestructorMemberList(object), memberName);
}

/* ------------- Fields ------------- */

// "private" function.
Legacy_Object *getPrivateField(Object *object, char *memberName) {
    return getAccessModifierMember(getPrivateMemberNameLegacy_List(object),
                                   getFieldsMemberList(object), memberName);
}

// "private" function.
Legacy_Object *getPublicField(Object *object, char *memberName) {
    return getAccessModifierMember(getPublicMemberNameLegacy_List(object),
                                   getFieldsMemberList(object), memberName);
}

/* ----------------------------- ADD MEMBER --------------------------------- */


/// TODO: public. TODO: test if we can invoke the `destruct` multiple times and
///     it will be still okay. maybe rename to something secret.
void *destruct(Object *object) {

    // TODO: DEBUG
    printf("\n\ndestruct invoked\n\n");

    if (object->legacyObject->destructorInvocationStatus == WAS_NOT_INVOKED) {
        object->legacyObject->destructorInvocationStatus = WAS_INVOKED_ONCE;

        if (object->privateMemberNameLegacy_List->legacyObjectComponent
                    ->destructorInvocationStatus == WAS_NOT_INVOKED) {
            object->privateMemberNameLegacy_List->legacyObjectComponent
                    ->destructorInvocationStatus = WAS_INVOKED_ONCE;

            // Destruct `privateMemberNameLegacy_List`.
            object->privateMemberNameLegacy_List->legacyObjectComponent
                    ->destructable->destructor(
                            object->privateMemberNameLegacy_List);
        }

        if (object->publicMemberNameLegacy_List->legacyObjectComponent
                    ->destructorInvocationStatus == WAS_NOT_INVOKED) {
            object->publicMemberNameLegacy_List->legacyObjectComponent
                    ->destructorInvocationStatus = WAS_INVOKED_ONCE;

            // Destruct `publicMemberNameLegacy_List`.
            object->publicMemberNameLegacy_List->legacyObjectComponent
                    ->destructable->destructor(
                            object->publicMemberNameLegacy_List);
        }

        if (object->methodsMemberList->legacyObjectComponent
                    ->destructorInvocationStatus == WAS_NOT_INVOKED) {
            object->methodsMemberList->legacyObjectComponent
                    ->destructorInvocationStatus = WAS_INVOKED_ONCE;

            // Destruct `methodsMemberList`.
            object->methodsMemberList->legacyObjectComponent->destructable
                    ->destructor(object->methodsMemberList);
        }

        if (object->constructorMemberList->legacyObjectComponent
                    ->destructorInvocationStatus == WAS_NOT_INVOKED) {
            object->constructorMemberList->legacyObjectComponent
                    ->destructorInvocationStatus = WAS_INVOKED_ONCE;

            // Destruct `constructorMemberList`.
            object->constructorMemberList->legacyObjectComponent->destructable
                    ->destructor(object->constructorMemberList);
        }

        if (object->destructorMemberList->legacyObjectComponent
                    ->destructorInvocationStatus == WAS_NOT_INVOKED) {
            object->destructorMemberList->legacyObjectComponent
                    ->destructorInvocationStatus = WAS_INVOKED_ONCE;

            // Destruct `destructorMemberList`.
            object->destructorMemberList->legacyObjectComponent->destructable
                    ->destructor(object->destructorMemberList);
        }

        if (object->fieldsMemberList->legacyObjectComponent
                    ->destructorInvocationStatus == WAS_NOT_INVOKED) {
            object->fieldsMemberList->legacyObjectComponent
                    ->destructorInvocationStatus = WAS_INVOKED_ONCE;

            // Destruct `fieldsMemberList`.
            object->fieldsMemberList->legacyObjectComponent->destructable
                    ->destructor(object->fieldsMemberList);
        }

        // Destruct `legacyObject`.
        object->legacyObject->destructable->destructor(object->legacyObject);


        // TODO: DEBUG
        printf("\n\nFREEEEEEE\n\n");

        free(object);
    }

    return NULL;
}

/**
 * @deprecated private. Do not use this. It is only used for the
 *             `Constructable` assignment. Use `construct` instead.
 *
 * memory allocating `sizeof(Object)`, then invoking legacy_ObjectComponent's
 * constructor, and MemberList's constructor.
 */
Object *constructNoClass() {
    Object *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->legacyObject =
            Legacy_ObjectComponentConstructorClassName("Object");
    instance->methodsMemberList = MemberListConstructor("Object");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&constructNoClass)};
    instance->legacyObject->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&destruct)};
    instance->legacyObject->destructable = &destructable;

    return instance;
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

    instance->legacyObject =
            Legacy_ObjectComponentConstructorClassName(className);
    instance->privateMemberNameLegacy_List = Legacy_ListConstructor();
    instance->publicMemberNameLegacy_List  = Legacy_ListConstructor();
    instance->methodsMemberList            = MemberListConstructor();
    instance->constructorMemberList        = MemberListConstructor();
    instance->destructorMemberList         = MemberListConstructor();
    instance->fieldsMemberList             = MemberListConstructor();

    //    // TODO: after rename
    //    instance->methodsMemberList->addMemberWhichIsLegacy_Object(
    //            instance->methodsMemberList, FIELDS,
    //            (Legacy_Object *) MemberListConstructor());


    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&constructNoClass)};
    instance->legacyObject->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&destruct)};
    instance->legacyObject->destructable = &destructable;

    return instance;
}