#ifndef LEGACYSTRINGENTRY_H
#define LEGACYSTRINGENTRY_H


#include "ObjectContainer.r"

// Forward declaration of incomplete type
typedef struct legacy_stringEntry Legacy_StringEntry;

struct legacy_stringEntry {

    /// `Legacy_StringEntry` implements `Legacy_Object`.
    Legacy_Object *object;

    char *           key;
    ObjectContainer *value;
};


Legacy_StringEntry *Legacy_StringEntryConstructor();

Legacy_StringEntry *
Legacy_StringEntryConstructorWithKeyAndValue(char *key, ObjectContainer *value);

#endif //LEGACYSTRINGENTRY_H
