#include "Object.r"

Legacy_ObjectComponent *getLegacyObject(Object *object) {
    return (Legacy_ObjectComponent *) getAnonymousPointerByIndex(object, 0);
}

Legacy_List *getPrivateMemberNameLegacy_List(Object *object) {
    return (Legacy_List *) getAnonymousPointerByIndex(object, 1);
}

Legacy_List *getPublicMemberNameLegacy_List(Object *object) {
    return (Legacy_List *) getAnonymousPointerByIndex(object, 2);
}

MemberList *getMethodsMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerByIndex(object, 3);
}

MemberList *getConstructorMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerByIndex(object, 4);
}

MemberList *getDestructorMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerByIndex(object, 5);
}

MemberList *getFieldsMemberList(Object *object) {
    return (MemberList *) getAnonymousPointerByIndex(object, 6);
}

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