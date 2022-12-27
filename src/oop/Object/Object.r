#ifndef OBJECT_H
#define OBJECT_H

#include "MemberList.r"

// Forward declaration of incomplete type
typedef struct object Object;

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
struct object {
    Legacy_ObjectComponent *legacyObject;
    MemberList *   memberList;
};

void storeLegacyObjectConstructorAndDestructor(Object *object);

void *invokeStoredLegacyObjectDestructor(Object *object);

void *destruct(Object *object);

Object *construct(char *className);

#endif //OBJECT_H
