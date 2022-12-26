#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "AutoDestructable.r"
#include "Legacy_AtomicFreer.r"
#include "Legacy_StringObjectContainerEntry.r"


// Forward declaration of incomplete type
typedef struct memberList MemberList;

struct memberList {

    /// `MemberList` implements `Legacy_Object`.
    Legacy_Object *object;

    Legacy_List *memberEntryList;

    Legacy_ObjectContainer *(*addMember)(MemberList *memberList, char *memberName,
                                         Legacy_ObjectContainer *member);
    Legacy_ObjectContainer *(*getMemberByName)(MemberList *memberList,
                                        char *      memberName);
};

MemberList *MemberListConstructorWithObjectContainer(
        Legacy_ObjectContainer *objectContainerThatContainsThisMemberList);

#endif //MEMBERLIST_H
