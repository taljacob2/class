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
    void *(*getLValueMember)(                                                                           \
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
            void *lValueData, BOOLEAN isDataDynamicallyAllocated);                                      \
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
    void *(*setLValueMember)(                                                                           \
            Object * self, enum MemberAccessModifier memberAccessModifier,                              \
            enum MemberType memberType, const char *memberName,                                         \
            void *  lValueDataValueToSet,                                                               \
            BOOLEAN isDataDynamicallyAllocatedValueToSet);                                              \
    BOOLEAN(*setIntegerRValueMember)                                                                    \
    (Object * self, enum MemberAccessModifier memberAccessModifier,                                     \
     enum MemberType memberType, const char *memberName,                                                \
     IntegerRValue integerRValueValueToSet);                                                            \
    BOOLEAN(*setDoubleRValueMember)                                                                     \
    (Object * self, enum MemberAccessModifier memberAccessModifier,                                     \
     enum MemberType memberType, const char *memberName,                                                \
     DoubleRValue doubleRValueValueToSet);

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
