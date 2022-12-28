#ifndef OBJECTDEFINES_H
#define OBJECTDEFINES_H

#include "AnonymousPointer.r"
#include "Concat.h"
#include "Quote.h"

#define OBJECT_FIELDS           \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
                                \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
                                \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD; \
    ANONYMOUS_POINTER_AS_FIELD;


/**
 * `Legacy_List` of raw-strings only. each string is a name of a "private" member
 * that should be found at one of the following `MemberList`s: (methods, fields,
 * constructor, destructor).
 */
#define PRIVATE "___private___"

/**
 * `Legacy_List` of raw-strings only. each string is a name of a "public" member
 * that should be found at one of the following `MemberList`s: (methods, fields,
 * constructor, destructor).
 */
#define PUBLIC "___public___"

/// `MemberList`
#define METHODS "___methods___"

/// `MemberList`
#define CONSTRUCTOR "___constructor___"

/// `MemberList`
#define DESTRUCTOR "___destructor___"

/// `MemberList`
#define FIELDS "___fields___"

#define ____CLASS_STRUCT_NAME_EXTENSION___            ___
#define ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___ Constructor
#define ___CLASS_DESTRUCTOR_METHOD_NAME_EXTENSION___  Destructor

#define DEFINE_CLASS_H(className)                                           \
                                                                            \
    typedef struct CONCAT_SURROUND(                                         \
            className, ____CLASS_STRUCT_NAME_EXTENSION___) className;       \
                                                                            \
    struct CONCAT_SURROUND(className, ____CLASS_STRUCT_NAME_EXTENSION___) { \
                                                                            \
        OBJECT_FIELDS                                                       \
    };                                                                      \
                                                                            \
    className *CONCAT(className,                                            \
                      ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___)();


#define DEFINE_CLASS_C(className)                                         \
                                                                          \
    className *CONCAT(className,                                          \
                      ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___)() {  \
        return (className *) construct(QUOTE(className));                 \
    }                                                                     \
                                                                          \
    void CONCAT(className, ___CLASS_DESTRUCTOR_METHOD_NAME_EXTENSION___)( \
            className * object) {                                         \
        destruct((Object *) object);                                      \
    }


#endif //OBJECTDEFINES_H
