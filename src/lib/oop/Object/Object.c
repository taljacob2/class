#include "Object.r"

/* ------------------------------ GET LIST ---------------------------------- */

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
MemberList *getMethodsMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerValueByIndex(object, 3);
}

// "private" function.
MemberList *getConstructorMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerValueByIndex(object, 4);
}

// "private" function.
MemberList *getDestructorMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerValueByIndex(object, 5);
}

// "private" function.
MemberList *getFieldsMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerValueByIndex(object, 6);
}

/* ------------------------------ SET LIST ---------------------------------- */

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
void setMethodsMemberList(Object *object, MemberList *memberList) {
    setAnonymousPointerValueByIndex(object, 3, memberList);
}

// "private" function.
void setConstructorMemberList(Object *object, MemberList *memberList) {
    setAnonymousPointerValueByIndex(object, 4, memberList);
}

// "private" function.
void setDestructorMemberList(Object *object, MemberList *memberList) {
    setAnonymousPointerValueByIndex(object, 5, memberList);
}

// "private" function.
void setFieldsMemberList(Object *object, MemberList *memberList) {
    setAnonymousPointerValueByIndex(object, 6, memberList);
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

/* -------------- Specific Access Modifier ------------- */

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

/* --- Specific Access Modifier & Specific MemberList --- */

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

/* ----------------------------- ADD MEMBER --------------------------------- */

// "private" function.
void addAccessModifierMemberList(Legacy_List *accessModifierLegacyList,
                                 MemberList *memberList, char *memberName,
                                 Legacy_Object *memberToAdd) {

    // Add `memberName` to accessModifierList.
    accessModifierLegacyList->addAsUnique(
            accessModifierLegacyList,
            Legacy_NodeConstructorWithData(memberName),
            predicateFindAccessModifierMemberNameByMemberName, memberName);

    // Add member to MemberList.
    memberList->addMemberWhichIsLegacy_Object(memberList, memberName,
                                              memberToAdd);
}

/* -------------- Specific Access Modifier ------------- */

// "private" function.
void addPrivateMemberList(Object *object, MemberList *memberList,
                          char *memberName, Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(object),
                                memberList, memberName, memberToAdd);
}

// "private" function.
void addPublicMemberList(Object *object, MemberList *memberList,
                         char *memberName, Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(object),
                                memberList, memberName, memberToAdd);
}

/* --- Specific Access Modifier & Specific MemberList --- */

/* --------------- Methods --------------- */

// "public" function.
void addPrivateMethod(Object *object, char *memberName,
                      Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(object),
                                getMethodsMemberList(object), memberName,
                                memberToAdd);
}

// "public" function.
void addPublicMethod(Object *object, char *memberName,
                     Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(object),
                                getMethodsMemberList(object), memberName,
                                memberToAdd);
}

/* ------------- Constructor ------------- */

// "public" function.
void addPrivateConstructor(Object *object, char *memberName,
                           Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(object),
                                getConstructorMemberList(object), memberName,
                                memberToAdd);
}

// "public" function.
void addPublicConstructor(Object *object, char *memberName,
                          Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(object),
                                getConstructorMemberList(object), memberName,
                                memberToAdd);
}

/* ------------- Destructor ------------- */

// "public" function.
void addPrivateDestructor(Object *object, char *memberName,
                          Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(object),
                                getDestructorMemberList(object), memberName,
                                memberToAdd);
}

// "public" function.
void addPublicDestructor(Object *object, char *memberName,
                         Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(object),
                                getDestructorMemberList(object), memberName,
                                memberToAdd);
}

/* --------------- Fields --------------- */

// "public" function.
void addPrivateField(Object *object, char *memberName,
                     Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPrivateMemberNameLegacy_List(object),
                                getFieldsMemberList(object), memberName,
                                memberToAdd);
}

// "public" function.
void addPublicField(Object *object, char *memberName,
                    Legacy_Object *memberToAdd) {
    addAccessModifierMemberList(getPublicMemberNameLegacy_List(object),
                                getFieldsMemberList(object), memberName,
                                memberToAdd);
}

/* ---------------------------- Implementation ------------------------------ */

// "public" function.
void addImplementation(
        Object *object, char *memberName,
        Legacy_Object *(
                *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(
                const char *) ) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);

    addPublicField(
            object, (char *) implementationMemberName,
            constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter(
                    getLegacyObjectComponent(object)->CLASS_NAME));

    free((void *) implementationMemberName);
}

// "public" function.
void addImplementationThatIsConstructedWithLegacy_Object(
        Object *object, char *memberName,
        Legacy_Object *(
                *constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAndClassNameAsParameters)(
                Legacy_Object *, const char *) ) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);

    addPublicField(
            object, (char *) implementationMemberName,
            constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAndClassNameAsParameters(
                    (Legacy_Object *) object,
                    getLegacyObjectComponent(object)->CLASS_NAME));

    free((void *) implementationMemberName);
}

/// @deprecated
void addImplementationThatIsConstructedWithLegacy_ObjectAsParameter(
        Object *object, char *memberName,
        Legacy_Object *(
                *constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAndClassNameAsParameters)(
                Legacy_Object *, const char *),
        Legacy_Object *
                legacyObjectTheConstructorOfMemberClassToImplementUsesAsParameter) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);

    addPublicField(
            object, (char *) implementationMemberName,
            constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAndClassNameAsParameters(
                    legacyObjectTheConstructorOfMemberClassToImplementUsesAsParameter,
                    getLegacyObjectComponent(object)->CLASS_NAME));

    free((void *) implementationMemberName);
}

// "public" function.
Legacy_Object *getImplementation(Object *object, char *memberName) {
    const char *implementationMemberName = concat(IMPLEMENTATION, memberName);
    Legacy_Object *returnValue =
            getPublicField(object, (char *) implementationMemberName);
    free((void *) implementationMemberName);
    return returnValue;
}

/* ----------------------- Constructor & Destructor ------------------------= */

/// TODO: public. TODO: test if we can invoke the `destruct` multiple times and
///     it will be still okay. maybe rename to something secret.
void *destruct(Object *object) {
    if (object == NULL) { return NULL; }

    /*
     * May or may not actually implement "AutoDestructable", for it to be
     * destructed.
     */
    AutoDestructableDestructor(
            (AutoDestructable *) getImplementation(object, "AutoDestructable"));

    // TODO: DEBUG
    printf("\n\ndestruct invoked\n\n");


    // Destruct `privateMemberNameLegacy_List`.
    getPrivateMemberNameLegacy_List(object)
            ->legacyObjectComponent->destructable->destructor(
                    object->privateMemberNameLegacy_List);

    // Destruct `publicMemberNameLegacy_List`.
    getPublicMemberNameLegacy_List(object)
            ->legacyObjectComponent->destructable->destructor(
                    object->publicMemberNameLegacy_List);

    // Destruct `methodsLegacy_MemberList`.
    getMethodsMemberList(object)
            ->legacyObjectComponent->destructable->destructor(
                    object->methodsLegacy_MemberList);

    // Destruct `constructorLegacy_MemberList`.
    getConstructorMemberList(object)
            ->legacyObjectComponent->destructable->destructor(
                    object->constructorLegacy_MemberList);

    // Destruct `destructorLegacy_MemberList`.
    getDestructorMemberList(object)
            ->legacyObjectComponent->destructable->destructor(
                    object->destructorLegacy_MemberList);

    // Destruct `fieldsLegacy_MemberList`.
    getFieldsMemberList(object)
            ->legacyObjectComponent->destructable->destructor(
                    object->fieldsLegacy_MemberList);

    // Destruct `legacyObjectComponent`.
    free(getLegacyObjectComponent(object));

    // TODO: DEBUG
    printf("\n\nFREEEEEEE\n\n");

    free(object);

    return NULL;
}

void init_fields(Object *object) {
    setPrivateMemberNameLegacy_List(object, Legacy_ListConstructor());
    setPublicMemberNameLegacy_List(object, Legacy_ListConstructor());
    setMethodsMemberList(object, MemberListConstructor());
    setConstructorMemberList(object, MemberListConstructor());
    setDestructorMemberList(object, MemberListConstructor());
    setFieldsMemberList(object, MemberListConstructor());

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

    setLegacyObjectComponent(
            instance, Legacy_ObjectComponentConstructorClassName("Object"));

    init_fields(instance);

    addImplementationThatIsConstructedWithLegacy_Object(
            instance, "AutoDestructable",
            (Legacy_Object * (*) (Legacy_Object *, const char *) )
                    AutoDestructableConstructorWithClassName);

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&constructNoClass)};
    getLegacyObjectComponent(instance)->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&destruct)};
    getLegacyObjectComponent(instance)->destructable = &destructable;

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

    setLegacyObjectComponent(
            instance, Legacy_ObjectComponentConstructorClassName(className));

    init_fields(instance);

    addImplementationThatIsConstructedWithLegacy_Object(
            instance, "AutoDestructable",
            (Legacy_Object * (*) (Legacy_Object *, const char *) )
                    AutoDestructableConstructorWithClassName);

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&constructNoClass)};
    getLegacyObjectComponent(instance)->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&destruct)};
    getLegacyObjectComponent(instance)->destructable = &destructable;

    return instance;
}

Object *constructWithoutAutoDestructable(char *className) {
    Object *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    setLegacyObjectComponent(
            instance, Legacy_ObjectComponentConstructorClassName(className));

    init_fields(instance);

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&constructNoClass)};
    getLegacyObjectComponent(instance)->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&destruct)};
    getLegacyObjectComponent(instance)->destructable = &destructable;

    return instance;
}
