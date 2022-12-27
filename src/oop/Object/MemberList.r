#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Legacy_MemberList.r"

// Forward declaration of incomplete type
typedef struct memberList MemberList;

struct memberList {

    /// `MemberList` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *object;

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

MemberList *MemberListConstructor();

/// Add MemberList `#define`s for users.
#include "ObjectDefines.r"

#endif //MEMBERLIST_H
