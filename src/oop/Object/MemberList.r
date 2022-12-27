#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Legacy_MemberList.r"

// Forward declaration of incomplete type
typedef struct memberList MemberList;

struct memberList {

    /// `MemberList` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *legacyObjectComponent;

    Legacy_MemberList *legacyMemberList;

    Legacy_Object *(*addMemberWhichIsLegacy_ObjectContainer)(
            MemberList *self, char *memberName,
            Legacy_Object *legacyObjectContainer);
    Legacy_Object *(*addMemberWhichIsPrimitive)(
            MemberList *self, char *memberName,
            void *dynamicallyAllocatedPrimitive);
    Legacy_Object *(*getMemberByName)(MemberList *self, char *memberName);
};

MemberList *MemberListConstructor();

/// Add MemberList `#define`s for users.
#include "ObjectDefines.r"

#endif //MEMBERLIST_H
