#ifndef LEGACY_STRINGOBJECTCONTAINERENTRY_H
#define LEGACY_STRINGOBJECTCONTAINERENTRY_H


#include "Legacy_Object.r"

/* Forward declaration of incomplete type */
typedef struct legacy_stringObjectContainerEntry
        Legacy_StringObjectContainerEntry;

struct legacy_stringObjectContainerEntry {

    /** `Legacy_StringObjectContainerEntry` implements `Legacy_ObjectComponent`. */
    Legacy_ObjectComponent *object;

    char *         key;
    Legacy_Object *value;
};


Legacy_StringObjectContainerEntry *
Legacy_StringObjectContainerEntryConstructor();

Legacy_StringObjectContainerEntry *
Legacy_StringObjectContainerEntryConstructorWithKeyAndValue(
        char *key, Legacy_Object *value);

#endif /* LEGACY_STRINGOBJECTCONTAINERENTRY_H */
