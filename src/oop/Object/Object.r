#ifndef OBJECT_H
#define OBJECT_H

#include "MemberList.r"

/// Add MemberList `#define`s for users.
#include "ObjectDefines.r"

// Forward declaration of incomplete type
typedef struct object Object;

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
struct object {
    Legacy_ObjectComponent *legacyObject;
    Legacy_List *           privateMemberNameLegacy_List;
    Legacy_List *           publicMemberNameLegacy_List;
    MemberList *            methodsMemberList;
    MemberList *            constructorMemberList;
    MemberList *            destructorMemberList;
    MemberList *            fieldsMemberList;
};

void *destruct(Object *object);

Object *construct(char *className);

#endif //OBJECT_H
