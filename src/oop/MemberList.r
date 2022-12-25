#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "AutoDestructableV2.r"
#include "Legacy_StringEntry.r"


// Forward declaration of incomplete type
typedef struct memberList MemberList;

struct memberList {
    Legacy_List *memberEntryList;

    void *(*addMember)(MemberList *memberList, char *memberName, void *member);
    void *(*getMemberByName)(MemberList *memberList, char *memberName);
};

#endif //MEMBERLIST_H
