#ifndef LEGACY_STRINGOBJECTCONTAINERENTRY_H
#define LEGACY_STRINGOBJECTCONTAINERENTRY_H


#include "Legacy_ObjectContainer.r"

// Forward declaration of incomplete type
typedef struct legacy_stringObjectContainerEntry
        Legacy_StringObjectContainerEntry;

struct legacy_stringObjectContainerEntry {

    /// `Legacy_StringObjectContainerEntry` implements `Legacy_Object`.
    Legacy_Object *object;

    char *                  key;
    Legacy_ObjectContainer *value;
};


Legacy_StringObjectContainerEntry *
Legacy_StringObjectContainerEntryConstructor();

Legacy_StringObjectContainerEntry *
Legacy_StringObjectContainerEntryConstructorWithKeyAndValue(
        char *key, Legacy_ObjectContainer *value);

#endif //LEGACY_STRINGOBJECTCONTAINERENTRY_H
