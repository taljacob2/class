#ifndef LEGACY_MEMBERLIST_H
#define LEGACY_MEMBERLIST_H

#include "AutoDestructable.r"
#include "Legacy_AtomicFreer.r"
#include "Legacy_StringObjectContainerEntry.r"


// Forward declaration of incomplete type
typedef struct legacy_memberList Legacy_MemberList;

struct legacy_memberList {

    /// `Legacy_MemberList` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *legacyObjectComponent;

    Legacy_List *memberEntryList;

    Legacy_Object *(*getMemberByName)(Legacy_MemberList *legacy_memberList,
                                      char *             memberName);
    Legacy_Object *(*getMemberByNameAndDeleteMemberFromList)(
            Legacy_MemberList *legacyMemberList, char *memberName);

    Legacy_Object *(*addMemberWhichIsLegacy_Object)(
            Legacy_MemberList *self, char *memberName,
            Legacy_Object *legacyObjectContainer);
    Legacy_Object *(*addMemberWhichIsPrimitive)(
            Legacy_MemberList *self, char *memberName,
            void *dynamicallyAllocatedPrimitive);
};

Legacy_MemberList *Legacy_MemberListConstructor();

#endif //LEGACY_MEMBERLIST_H
