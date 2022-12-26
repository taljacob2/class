#ifndef OBJECTDEFINES_H
#define OBJECTDEFINES_H

#include "AnonymousPointer.h"

#define OBJECT_CONTAINER_FIELDS \
    ANONYMOUS_POINTER;          \
    ANONYMOUS_POINTER;


/**
 * MemberList of raw-strings only. each string is a name of a "private" member
 * that should be found at one of the following MemberLists: (methods, fields,
 * constructor, destructor).
 */
#define PRIVATE "___private___"

/**
 * MemberList of raw-strings only. each string is a name of a "public" member
 * that should be found at one of the following MemberLists: (methods, fields,
 * constructor, destructor).
 */
#define PUBLIC "___public___"

/// MemberList
#define METHODS "___methods___"

/// MemberList
#define CONSTRUCTOR "___constructor___"

/// MemberList
#define DESTRUCTOR "___destructor___"

/// MemberList
#define FIELDS "___fields___"


#endif //OBJECTDEFINES_H
