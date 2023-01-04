#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Legacy_MemberList.r"

// Forward declaration of incomplete type
typedef struct memberList MemberList;

struct memberList {

    /// `MemberList` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *legacyObjectComponent;

    /// `MemberList` implements `AutoDestructable`.
    AutoDestructable *autoDestructable;

    Legacy_MemberList *legacyMemberList;

    Legacy_Object *(*addMemberWhichIsLegacy_Object)(
            MemberList *self, char *memberName, Legacy_Object *legacyObject);
    Legacy_Object *(*addMemberWhichIsPrimitive)(
            MemberList *self, char *memberName,
            void *dynamicallyAllocatedPrimitive);
    Legacy_Object *(*getMemberByName)(MemberList *self, char *memberName);
};

MemberList *MemberListConstructor();

#endif //MEMBERLIST_H
