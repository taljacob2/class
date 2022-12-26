#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "AutoDestructable.r"
#include "Legacy_AtomicFreer.r"
#include "Legacy_StringEntry.r"


// Forward declaration of incomplete type
typedef struct memberList MemberList;

struct memberList {

    /// `MemberList` implements `Legacy_Object`.
    Legacy_Object *object;

    Legacy_List *memberEntryList;

    ObjectContainer *(*addMember)(MemberList *memberList, char *memberName,
                                  ObjectContainer *member);
    ObjectContainer *(*getMemberByName)(MemberList *memberList,
                                        char *      memberName);
};

MemberList *MemberListConstructorWithObjectContainer(
        ObjectContainer *objectContainerThatContainsThisMemberList);

#endif //MEMBERLIST_H
