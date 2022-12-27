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

    Legacy_ObjectContainer *(*addMember)(Legacy_MemberList *legacy_memberList,
                                         char *             memberName,
                                         Legacy_ObjectContainer *member);
    Legacy_ObjectContainer *(*getMemberByName)(
            Legacy_MemberList *legacy_memberList, char *memberName);
};

Legacy_MemberList *Legacy_MemberListConstructorWithObjectContainer(
        Legacy_ObjectContainer
                *objectContainerThatContainsThisLegacy_MemberList);

#endif //LEGACY_MEMBERLIST_H
