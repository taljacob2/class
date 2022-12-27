#include "ObjectContainer.r"

void storeLegacyObjectConstructorAndDestructor(
        ObjectContainer *objectContainer) {

    // `__LEGACY_OBJECT_CONSTRUCTABLE__ObjectContainer__` is stored.
    const Constructable **legacyObjectConstructable =
            malloc(sizeof(const Constructable *));
    *legacyObjectConstructable = objectContainer->legacyObject->constructable;
    objectContainer->object->addMemberWhichIsPrimitive(
            objectContainer->object,
            __LEGACY_OBJECT_CONSTRUCTABLE__ObjectContainer__,
            legacyObjectConstructable);

    // `__LEGACY_OBJECT_DESTRUCTABLE__ObjectContainer__` is stored.
    const Destructable **legacyObjectDestructable =
            malloc(sizeof(const Destructable *));
    *legacyObjectDestructable = objectContainer->object->object->destructable;
    objectContainer->object->addMemberWhichIsPrimitive(
            objectContainer->object,
            __LEGACY_OBJECT_DESTRUCTABLE__ObjectContainer__,
            legacyObjectDestructable);
}

void *invokeStoredLegacyObjectDestructor(ObjectContainer *objectContainer) {

    // Invoke destructor of `legacyObjectDestructable`.
    return (*((Destructable **) objectContainer->object->getMemberByName(
                    objectContainer->object,
                    __LEGACY_OBJECT_DESTRUCTABLE__ObjectContainer__)))
            ->destructor(objectContainer->legacyObject);
}

/// @deprecated No need to use this. But it should work.
Legacy_Object *
invokeStoredLegacyObjectConstructor(ObjectContainer *objectContainer) {

    // Invoke constructor of `legacyObjectConstructable`.
    return (*((Constructable **) objectContainer->object->getMemberByName(
                    objectContainer->object,
                    __LEGACY_OBJECT_CONSTRUCTABLE__ObjectContainer__)))
            ->constructor(objectContainer->legacyObject);
}

//
//// TODO:
///// Returns all the "public" fields / methods.
//getPublic();
//
//
//// TODO:
///// Returns all the "private" fields / methods.
//getPrivate();


/// TODO: public. TODO: test if we can invoke the `destruct` multiple times and
///     it will be still okay. maybe rename to something secret.
void *destruct(ObjectContainer *objectContainer) {
    if (objectContainer->legacyObject->destructorInvocationStatus ==
        WAS_NOT_INVOKED) {
        objectContainer->legacyObject->destructorInvocationStatus =
                WAS_INVOKED_ONCE;

        if (objectContainer->object->object->destructorInvocationStatus ==
            WAS_NOT_INVOKED) {
            objectContainer->object->object->destructorInvocationStatus =
                    WAS_INVOKED_ONCE;

            // Destruct `memberList`.
            objectContainer->object->object->destructable->destructor(
                    objectContainer->object);
        }

        // Destruct `legacyObject`.
        objectContainer->legacyObject->destructable->destructor(
                objectContainer->legacyObject);


        // TODO: DEBUG
        printf("\n\nFREEEEEEE\n\n");

        free(objectContainer);
    }

    return NULL;
}

/**
 * @deprecated private. Do not use this. It is only used for the
 *             `Constructable` assignment. Use `construct` instead.
 *
 * memory allocating `sizeof(ObjectContainer)`, then invoking legacy_Object's
 * constructor, and MemberList's constructor.
 */
ObjectContainer *constructNoClass() {
    ObjectContainer *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->legacyObject =
            Legacy_ObjectConstructorClassName("ObjectContainer");
    instance->object = ObjectConstructor("ObjectContainer");

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
 * memory allocating `sizeof(ObjectContainer)`, then invoking legacy_Object's
 * constructor, and MemberList's constructor.
 */
ObjectContainer *construct(char *className) {
    ObjectContainer *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->legacyObject = Legacy_ObjectConstructorClassName(className);
    instance->object       = ObjectConstructor(className);

    // TODO: after rename
//    instance->memberList->addMemberWhichIsLegacy_ObjectContainer(
//            instance->memberList, FIELDS,
//            ObjectConstructor("")));

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&constructNoClass)};
    instance->legacyObject->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&destruct)};
    instance->legacyObject->destructable = &destructable;

    return instance;
}