#ifndef LEGACY_OBJECTCONTAINER_H
#define LEGACY_OBJECTCONTAINER_H

#include "Legacy_ObjectComponent.r"

// Forward declaration of incomplete type
typedef struct legacy_objectContainer Legacy_ObjectContainer;

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
struct legacy_objectContainer {
    Legacy_ObjectComponent *legacyObjectComponent;
};


#endif //LEGACY_OBJECTCONTAINER_H
