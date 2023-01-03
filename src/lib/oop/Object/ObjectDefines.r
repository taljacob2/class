#ifndef OBJECTDEFINES_H
#define OBJECTDEFINES_H

#include "AnonymousPointer.r"
#include "Concat.h"
#include "Quote.h"

#define OBJECT_FIELDS                                                                                                \
    ANONYMOUS_POINTER_AS_FIELD;                                                                                      \
    ANONYMOUS_POINTER_AS_FIELD;                                                                                      \
    ANONYMOUS_POINTER_AS_FIELD;                                                                                      \
    ANONYMOUS_POINTER_AS_FIELD;                                                                                      \
    ANONYMOUS_POINTER_AS_FIELD;                                                                                      \
    ANONYMOUS_POINTER_AS_FIELD;                                                                                      \
    ANONYMOUS_POINTER_AS_FIELD;                                                                                      \
                                                                                                                     \
    Legacy_Object *(*getPrivateMethod)(Object * object, char *memberName);                                           \
    Legacy_Object *(*getPublicMethod)(Object * object, char *memberName);                                            \
    Legacy_Object *(*getPrivateConstructor)(Object * object,                                                         \
                                            char *memberName);                                                       \
    Legacy_Object *(*getPublicConstructor)(Object * object, char *memberName);                                       \
    Legacy_Object *(*getPrivateDestructor)(Object * object, char *memberName);                                       \
    Legacy_Object *(*getPublicDestructor)(Object * object, char *memberName);                                        \
    Legacy_Object *(*getPrivateField)(Object * object, char *memberName);                                            \
    Legacy_Object *(*getPublicField)(Object * object, char *memberName);                                             \
    Legacy_Object *(*getImplementation)(Object * object, char *memberName);                                          \
                                                                                                                     \
    void (*addPrivateMethod)(Object * object, char *memberName,                                                      \
                             Legacy_Object *memberToAdd);                                                            \
    void (*addPublicMethod)(Object * object, char *memberName,                                                       \
                            Legacy_Object *memberToAdd);                                                             \
    void (*addPrivateConstructor)(Object * object, char *memberName,                                                 \
                                  Legacy_Object *memberToAdd);                                                       \
    void (*addPublicConstructor)(Object * object, char *memberName,                                                  \
                                 Legacy_Object *memberToAdd);                                                        \
    void (*addPrivateDestructor)(Object * object, char *memberName,                                                  \
                                 Legacy_Object *memberToAdd);                                                        \
    void (*addPublicDestructor)(Object * object, char *memberName,                                                   \
                                Legacy_Object *memberToAdd);                                                         \
    void (*addPrivateField)(Object * object, char *memberName,                                                       \
                            Legacy_Object *memberToAdd);                                                             \
    void (*addPublicField)(Object * object, char *memberName,                                                        \
                           Legacy_Object *memberToAdd);                                                              \
    void (*addImplementation)(                                                                                       \
            Object * object, char *memberName,                                                                       \
            Legacy_Object *(                                                                                         \
                    *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(                 \
                    const char *) );                                                                                 \
    void (*addImplementationThatIsConstructedWithLegacy_Object)(                                                     \
            Object * object, char *memberName,                                                                       \
            Legacy_Object *(                                                                                         \
                    *constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAndClassNameAsParameters)( \
                    Legacy_Object *, const char *) );


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

#define IMPLEMENTATION "__IMPLEMENTATION__"

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
