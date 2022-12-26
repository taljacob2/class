#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "AutoDestructable.r"
#include "Legacy_StringEntry.r"


// Forward declaration of incomplete type
typedef struct memberList MemberList;

struct memberList {

    /// `MemberList` implements `Object`.
    Object *object;

    Legacy_List *memberEntryList;

    void *(*addMember)(MemberList *memberList, char *memberName, void *member);
    void *(*getMemberByName)(MemberList *memberList, char *memberName);
};

MemberList *MemberListConstructor();

#endif //MEMBERLIST_H
