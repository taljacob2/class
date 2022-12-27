#ifndef LEGACY_OBJECT_H
#define LEGACY_OBJECT_H

#include "Legacy_ObjectComponent.r"

// Forward declaration of incomplete type
typedef struct legacy_object Legacy_Object;

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
struct legacy_object {
    Legacy_ObjectComponent *legacyObjectComponent;
};


#endif //LEGACY_OBJECT_H
