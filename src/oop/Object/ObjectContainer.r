#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "MemberList.r"

#define __LEGACY_OBJECT_CONSTRUCTABLE__ObjectContainer__ \
    "legacyObjectConstructable"
#define __LEGACY_OBJECT_DESTRUCTABLE__ObjectContainer__ \
    "legacyObjectDestructable"


// Forward declaration of incomplete type
typedef struct objectContainer ObjectContainer;

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
struct objectContainer {
    Legacy_Object *legacyObject;
    MemberList *       object;
};

void storeLegacyObjectConstructorAndDestructor(
        ObjectContainer *objectContainer);

void *invokeStoredLegacyObjectDestructor(ObjectContainer *objectContainer);

void *destruct(ObjectContainer *objectContainer);

ObjectContainer *construct(char *className);

#endif //OBJECTCONTAINER_H
