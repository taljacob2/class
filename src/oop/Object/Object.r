#ifndef OBJECT_H
#define OBJECT_H

#include "Legacy_MemberList.r"

// Forward declaration of incomplete type
typedef struct object Object;

struct object {

    /// `Object` implements `Legacy_Object`.
    Legacy_Object *object;

    Legacy_MemberList *legacy_memberList;

    Legacy_ObjectContainer *(*addMemberWhichIsLegacy_ObjectContainer)(
            Object *self, char *memberName,
            Legacy_ObjectContainer *legacyObjectContainer);
    Legacy_ObjectContainer *(*addMemberWhichIsPrimitive)(
            Object *self, char *memberName,
            void *dynamicallyAllocatedPrimitive);
    Legacy_ObjectContainer *(*getMemberByName)(Object *self, char *memberName);
};

Object *ObjectConstructor(const char *className);

/// Add Object `#define`s for users.
#include "ObjectDefines.r"

#endif //OBJECT_H
