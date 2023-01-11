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
    Legacy_Object *(*getPrivateMethod)(Object * self, char *memberName);                                \
    Legacy_Object *(*getPublicMethod)(Object * self, char *memberName);                                 \
    Legacy_Object *(*getPrivateConstructor)(Object * self, char *memberName);                           \
    Legacy_Object *(*getPublicConstructor)(Object * self, char *memberName);                            \
    Legacy_Object *(*getPrivateDestructor)(Object * self, char *memberName);                            \
    Legacy_Object *(*getPublicDestructor)(Object * self, char *memberName);                             \
    Legacy_Object *(*getPrivateField)(Object * self, char *memberName);                                 \
    Legacy_Object *(*getPublicField)(Object * self, char *memberName);                                  \
    Legacy_Object *(*getImplementation)(Object * self, char *memberName);                               \
                                                                                                        \
    void (*addPrivateMethod)(Object * self, char *memberName,                                           \
                             Object *memberToAdd);                                                      \
    void (*addPublicMethod)(Object * self, char *memberName,                                            \
                            Object *memberToAdd);                                                       \
    void (*addPrivateConstructor)(Object * self, char *memberName,                                      \
                                  Object *memberToAdd);                                                 \
    void (*addPublicConstructor)(Object * self, char *memberName,                                       \
                                 Object *memberToAdd);                                                  \
    void (*addPrivateDestructor)(Object * self, char *memberName,                                       \
                                 Object *memberToAdd);                                                  \
    void (*addPublicDestructor)(Object * self, char *memberName,                                        \
                                Object *memberToAdd);                                                   \
    void (*addPrivateField)(Object * self, char *memberName,                                            \
                            Object *memberToAdd);                                                       \
    void (*addPublicField)(Object * self, char *memberName,                                             \
                           Object *memberToAdd);                                                        \
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


#endif //OBJECTDEFINES_H
