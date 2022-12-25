#ifndef LEGACYSTRINGENTRY_H
#define LEGACYSTRINGENTRY_H


#include "Object.r"

// Forward declaration of incomplete type
typedef struct legacy_stringEntry Legacy_StringEntry;

struct legacy_stringEntry {

    /// `Legacy_StringEntry` implements `Object`.
    Object *object;

    char *key;
    void *value;
};


Legacy_StringEntry *Legacy_StringEntryConstructor();

Legacy_StringEntry *Legacy_StringEntryConstructorWithKeyAndValue(char *key,
                                                                 void *value);

#endif //LEGACYSTRINGENTRY_H
