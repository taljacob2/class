#include "Legacy_ObjectComponent.r"

/* Pre-declare privately. */
Legacy_ObjectComponent *Legacy_ObjectComponentConstructor();

/**
 * @brief Destructs `Legacy_ObjectComponent`.
 *
 * @param legacyObjectComponent The `Legacy_ObjectComponent` to ObjectDestructor.
 * @see Destructable
 */
void Legacy_ObjectComponentDestructor(
        Legacy_ObjectComponent *legacyObjectComponent) {
    free(legacyObjectComponent);
}

void constructor_Legacy_Object_fields(
        Legacy_ObjectComponent *legacyObjectComponent) {
    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(
                    &Legacy_ObjectComponentDestructor)};
    legacyObjectComponent->destructable = &destructable;

    legacyObjectComponent->destructorInvocationStatus = WAS_NOT_INVOKED;
}

/**
 * @deprecated Do not use this implementation, because then you could probably
 * neglect not initializing `CLASS_NAME`.
 */
Legacy_ObjectComponent *Legacy_ObjectComponentConstructor() {
    Legacy_ObjectComponent *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->CLASS_NAME = "Legacy_ObjectComponent";

    constructor_Legacy_Object_fields(instance);

    return instance;
}

Legacy_ObjectComponent *
Legacy_ObjectComponentConstructorClassName(const char *className) {
    Legacy_ObjectComponent *instance = Legacy_ObjectComponentConstructor();

    instance->CLASS_NAME = className;

    return instance;
}