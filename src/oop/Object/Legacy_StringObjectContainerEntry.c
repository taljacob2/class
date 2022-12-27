#include "Legacy_StringObjectContainerEntry.r"

/**
 * @brief `Destructs`s the given legacy_stringObjectContainerEntry, and returns its
 *        `legacy_stringObjectContainerEntry->value`.
 *
 * @param stringObjectContainerEntry
 * @return
 */
void *Legacy_StringObjectContainerEntryDestructor(
        Legacy_StringObjectContainerEntry *stringObjectContainerEntry) {
    if (stringObjectContainerEntry == NULL) { return NULL; }

    void *valueDestructorReturnValue =
            stringObjectContainerEntry->value->legacyObjectComponent
                    ->destructable->destructor(
                    stringObjectContainerEntry->value);

    free(stringObjectContainerEntry->object);

    free(stringObjectContainerEntry);

    return valueDestructorReturnValue;
}

void constructor_Legacy_StringObjectContainerEntry_fields(
        Legacy_StringObjectContainerEntry *stringObjectContainerEntry) {
    stringObjectContainerEntry->object =
            Legacy_ObjectComponentConstructorClassName(
                    "Legacy_StringObjectContainerEntry");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(
                    &Legacy_StringObjectContainerEntryConstructor)};
    stringObjectContainerEntry->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(
                    &Legacy_StringObjectContainerEntryDestructor)};
    stringObjectContainerEntry->object->destructable = &destructable;

    stringObjectContainerEntry->key   = NULL;
    stringObjectContainerEntry->value = NULL;
}

Legacy_StringObjectContainerEntry *
Legacy_StringObjectContainerEntryConstructor() {
    Legacy_StringObjectContainerEntry *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_Legacy_StringObjectContainerEntry_fields(instance);

    return instance;
}

Legacy_StringObjectContainerEntry *
Legacy_StringObjectContainerEntryConstructorWithKeyAndValue(
        char *key, Legacy_Object *value) {
    Legacy_StringObjectContainerEntry *instance =
            Legacy_StringObjectContainerEntryConstructor();

    instance->key   = key;
    instance->value = value;

    return instance;
}
