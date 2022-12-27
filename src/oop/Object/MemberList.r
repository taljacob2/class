#ifndef OBJECT_H
#define OBJECT_H

#include "Legacy_MemberList.r"

// Forward declaration of incomplete type
typedef struct memberList MemberList;

struct memberList {

    /// `MemberList` implements `Legacy_Object`.
    Legacy_Object *object;

    Legacy_MemberList *legacy_memberList;

    Legacy_ObjectContainer *(*addMemberWhichIsLegacy_ObjectContainer)(
            MemberList *self, char *memberName,
            Legacy_ObjectContainer *legacyObjectContainer);
    Legacy_ObjectContainer *(*addMemberWhichIsPrimitive)(
            MemberList *self, char *memberName,
            void *dynamicallyAllocatedPrimitive);
    Legacy_ObjectContainer *(*getMemberByName)(MemberList *self,
                                               char *      memberName);
};

MemberList *ObjectConstructor(const char *className);

/// Add MemberList `#define`s for users.
#include "ObjectDefines.r"

#endif //OBJECT_H
