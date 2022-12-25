#include "Legacy_StringEntry.r"

/**
 * @brief `Destructs`s the given legacy_stringEntry, and returns its
 *        `legacy_stringEntry->value`.
 *
 * @param stringEntry
 * @return
 */
void *Legacy_StringEntryDestructor(Legacy_StringEntry *stringEntry) {
    if (stringEntry == NULL) { return NULL; }

    void *stringEntryValue = stringEntry->value;

    free(stringEntry->object);

    free(stringEntry);

    return stringEntryValue;
}

void constructor_Legacy_StringEntry_fields(Legacy_StringEntry *stringEntry) {
    stringEntry->object = ObjectConstructor();

    static Constructable const constructable = {
            .constructor =
                    (void *(*const)(void) )(&Legacy_StringEntryConstructor)};
    stringEntry->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&Legacy_StringEntryDestructor)};
    stringEntry->object->destructable = &destructable;

    stringEntry->key   = NULL;
    stringEntry->value = NULL;
}

Legacy_StringEntry *Legacy_StringEntryConstructor() {
    Legacy_StringEntry *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_Legacy_StringEntry_fields(instance);

    return instance;
}

Legacy_StringEntry *Legacy_StringEntryConstructorWithKeyAndValue(char *key,
                                                                 void *value) {
    Legacy_StringEntry *instance = Legacy_StringEntryConstructor();

    instance->key   = key;
    instance->value = value;

    return instance;
}
