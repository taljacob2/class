#include "Object.r"

/// TODO: public. TODO: test if we can invoke the `destruct` multiple times and
///     it will be still okay. maybe rename to something secret.
void *destruct(Object *object) {

    // TODO: DEBUG
    printf("\n\ndestruct invoked\n\n");

    if (object->legacyObject->destructorInvocationStatus == WAS_NOT_INVOKED) {
        object->legacyObject->destructorInvocationStatus = WAS_INVOKED_ONCE;

        if (object->memberList->legacyObjectComponent
                    ->destructorInvocationStatus == WAS_NOT_INVOKED) {
            object->memberList->legacyObjectComponent
                    ->destructorInvocationStatus = WAS_INVOKED_ONCE;

            // Destruct `memberList`.
            object->memberList->legacyObjectComponent->destructable->destructor(
                    object->memberList);
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
    instance->memberList = MemberListConstructor("Object");

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
    instance->memberList = MemberListConstructor(className);

//    // TODO: after rename
//    instance->memberList->addMemberWhichIsLegacy_Object(
//            instance->memberList, FIELDS,
//            (Legacy_Object *) MemberListConstructor());


    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&constructNoClass)};
    instance->legacyObject->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&destruct)};
    instance->legacyObject->destructable = &destructable;

    return instance;
}