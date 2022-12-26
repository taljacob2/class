#include "Legacy_Object.r"

// Pre-declare privately.
Legacy_Object *Legacy_ObjectConstructor();

/**
 * @brief Destructs `Legacy_Object`.
 *
 * @param object The `Legacy_Object` to destruct.
 * @see Destructable
 */
void Legacy_ObjectDestructor(Legacy_Object *object) { free(object); }

void constructor_Legacy_Object_fields(Legacy_Object *object) {
    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&Legacy_ObjectConstructor)};
    object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&Legacy_ObjectDestructor)};
    object->destructable = &destructable;

    object->destructorInvocationStatus                = WAS_NOT_INVOKED;
    object->deleteFromAllocationTableInvocationStatus = WAS_NOT_INVOKED;
}

/**
 * @deprecated Do not use this implementation, because then you could probably
 * neglect not initializing `CLASS_NAME`.
 */
Legacy_Object *Legacy_ObjectConstructor() {
    Legacy_Object *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->CLASS_NAME = "Legacy_Object";

    constructor_Legacy_Object_fields(instance);

    return instance;
}

Legacy_Object *Legacy_ObjectConstructorClassName(const char *className) {
    Legacy_Object *instance = Legacy_ObjectConstructor();

    instance->CLASS_NAME = className;

    return instance;
}