#ifndef OBJECTDEFINES_H
#define OBJECTDEFINES_H

#include "AnonymousPointer.r"
#include "Concat.h"
#include "Quote.h"

#define OBJECT_FIELDS                                                                                   \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
    ANONYMOUS_POINTER_AS_FIELD;                                                                         \
                                                                                                        \
    TYPEOF_ANONYMOUS_POINTER(*getMemberValue)                                                           \
    (Object * self, enum AccessModifier accessModifier,                                                 \
     enum MemberType memberType, const char *memberName);                                               \
                                                                                                        \
    void (*addIntegerRValueMember)(                                                                     \
            Object * self, enum AccessModifier accessModifier,                                          \
            enum MemberType memberType, const char *memberName,                                         \
            IntegerRValue integerRValue);                                                               \
    IntegerRValue (*getIntegerRValueMember)(                                                            \
            Object * self, enum AccessModifier accessModifier,                                          \
            enum MemberType memberType, const char *memberName);                                        \
    void (*addDoubleRValueMember)(                                                                      \
            Object * self, enum AccessModifier accessModifier,                                          \
            enum MemberType memberType, const char *memberName,                                         \
            DoubleRValue doubleRValue);                                                                 \
    DoubleRValue (*getDoubleRValueMember)(                                                              \
            Object * self, enum AccessModifier accessModifier,                                          \
            enum MemberType memberType, const char *memberName);                                        \
                                                                                                        \
    Legacy_Object *(*getImplementation)(Object * self, char *memberName);                               \
                                                                                                        \
    void (*addMemberValue)(Object * self, enum AccessModifier accessModifier,                           \
                           enum MemberType memberType, const char *memberName,                          \
                           Object *memberToAdd);                                                        \
                                                                                                        \
    void (*addImplementation)(                                                                          \
            Object * self, char *memberName,                                                            \
            Object *(                                                                                   \
                    *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(    \
                    const char *) );                                                                    \
    void (*addImplementationThatIsConstructedWithLegacy_Object)(                                        \
            Object * self, char *memberName,                                                            \
            Object *(                                                                                   \
                    *constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter)( \
                    Legacy_Object *) );

#define IMPLEMENTATION      "__IMPLEMENTATION__"
#define DEFAULT_DESTRUCTOR  "__DefaultDestructor__"
#define DEFAULT_CONSTRUCTOR "__DefaultConstructor__"

#define ____CLASS_STRUCT_NAME_EXTENSION___            ___
#define ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___ Constructor
#define ___CLASS_DESTRUCTOR_METHOD_NAME_EXTENSION___  Destructor

#define DEFINE_CLASS_H(ClassName)                                           \
                                                                            \
    typedef struct CONCAT_SURROUND(                                         \
            ClassName, ____CLASS_STRUCT_NAME_EXTENSION___) ClassName;       \
                                                                            \
    struct CONCAT_SURROUND(ClassName, ____CLASS_STRUCT_NAME_EXTENSION___) { \
                                                                            \
        OBJECT_FIELDS                                                       \
    };


#endif //OBJECTDEFINES_H
