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
    Object *(*getObjectMember)(                                                                         \
            Object * self, enum MemberAccessModifier memberAccessModifier,                              \
            enum MemberType memberType, const char *memberName);                                        \
    LValue (*getLValueMember)(                                                                          \
            Object * self, enum MemberAccessModifier memberAccessModifier,                              \
            enum MemberType memberType, const char *memberName);                                        \
    IntegerRValue (*getIntegerRValueMember)(                                                            \
            Object * self, enum MemberAccessModifier accessModifier,                                    \
            enum MemberType memberType, const char *memberName);                                        \
    DoubleRValue (*getDoubleRValueMember)(                                                              \
            Object * self, enum MemberAccessModifier accessModifier,                                    \
            enum MemberType memberType, const char *memberName);                                        \
    Legacy_Object *(*getImplementation)(Object * self, char *memberName);                               \
                                                                                                        \
    void (*addObjectMember)(Object * self,                                                              \
                            enum MemberAccessModifier memberAccessModifier,                             \
                            enum MemberType           memberType,                                       \
                            const char *memberName, Object *memberToAdd);                               \
    void (*addLValueMember)(                                                                            \
            Object * self, enum MemberAccessModifier memberAccessModifier,                              \
            enum MemberType memberType, const char *memberName,                                         \
            LValue lValueData, BOOLEAN isDataDynamicallyAllocated);                                     \
    void (*addIntegerRValueMember)(                                                                     \
            Object * self, enum MemberAccessModifier memberAccessModifier,                              \
            enum MemberType memberType, const char *memberName,                                         \
            IntegerRValue integerRValue);                                                               \
    void (*addDoubleRValueMember)(                                                                      \
            Object * self, enum MemberAccessModifier memberAccessModifier,                              \
            enum MemberType memberType, const char *memberName,                                         \
            DoubleRValue doubleRValue);                                                                 \
    void (*addImplementation)(                                                                          \
            Object * self, char *memberName,                                                            \
            Object *(                                                                                   \
                    *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(    \
                    const char *) );                                                                    \
    void (*addImplementationThatIsConstructedWithLegacy_Object)(                                        \
            Object * self, char *memberName,                                                            \
            Object *(                                                                                   \
                    *constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter)( \
                    Legacy_Object *) );                                                                 \
                                                                                                        \
    Object *(*setSelf)(Object * self, Object * value);                                                  \
    Object *(*setObjectMember)(                                                                         \
            Object * self, enum MemberAccessModifier memberAccessModifier,                              \
            enum MemberType memberType, const char *memberName,                                         \
            Object *memberValueToSet);                                                                  \
    LValue (*setLValueMember)(                                                                          \
            Object * self, enum MemberAccessModifier memberAccessModifier,                              \
            enum MemberType memberType, const char *memberName,                                         \
            LValue  lValueDataValueToSet,                                                               \
            BOOLEAN isDataDynamicallyAllocatedValueToSet);                                              \
    BOOLEAN(*setIntegerRValueMember)                                                                    \
    (Object * self, enum MemberAccessModifier memberAccessModifier,                                     \
     enum MemberType memberType, const char *memberName,                                                \
     IntegerRValue integerRValueValueToSet);                                                            \
    BOOLEAN(*setDoubleRValueMember)                                                                     \
    (Object * self, enum MemberAccessModifier memberAccessModifier,                                     \
     enum MemberType memberType, const char *memberName,                                                \
     DoubleRValue doubleRValueValueToSet);                                                              \
                                                                                                        \
    BOOLEAN(*toStringMembersByMemberAccessModifier)                                                     \
    (Object * self, enum MemberAccessModifier memberAccessModifier);                                    \
    BOOLEAN(*toStringMembersByMemberType)                                                               \
    (Object * self, enum MemberType memberType);                                                        \
    void (*toString)(Object * self);


#define IMPLEMENTATION "__IMPLEMENTATION__"

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


#define DESTRUCT_OBJECT(objectToDestruct)                                  \
    ((void (*)(Object *))((Object *) objectToDestruct)                     \
             ->getLValueMember((Object *) objectToDestruct, PUBLIC,        \
                               DESTRUCTOR,                                 \
                               "void *ObjectDestructor(Object *object)"))( \
            (Object *) objectToDestruct)

#endif /* OBJECTDEFINES_H */
