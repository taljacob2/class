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
    Legacy_Object *(*getImplementationAndRemoveIt)(Object * object,                                                  \
                                                   char *memberName);                                                \
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

#define IMPLEMENTATION "__IMPLEMENTATION__"

#define ____CLASS_STRUCT_NAME_EXTENSION___            ___
#define ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___ Constructor
#define ___CLASS_DESTRUCTOR_METHOD_NAME_EXTENSION___  Destructor

#define DEFINE_CLASS_H(ClassName)                                             \
                                                                              \
    typedef struct CONCAT_SURROUND(                                           \
            ClassName, ____CLASS_STRUCT_NAME_EXTENSION___) ClassName;         \
                                                                              \
    struct CONCAT_SURROUND(ClassName, ____CLASS_STRUCT_NAME_EXTENSION___) {   \
                                                                              \
        OBJECT_FIELDS                                                         \
    };                                                                        \
                                                                              \
    ClassName *CONCAT(ClassName,                                              \
                      ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___)();       \
                                                                              \
    ClassName *CONCAT(                                                        \
            CONCAT(ClassName, ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___), \
            WithoutAutoDestructable)();


#define DEFINE_CLASS_C(ClassName)                                             \
                                                                              \
    ClassName *CONCAT(ClassName,                                              \
                      ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___)() {      \
        return (ClassName *) construct(QUOTE(ClassName));                     \
    }                                                                         \
                                                                              \
    ClassName *CONCAT(                                                        \
            CONCAT(ClassName, ___CLASS_CONSTRUCTOR_METHOD_NAME_EXTENSION___), \
            WithoutAutoDestructable)() {                                      \
        return (ClassName *) constructWithoutAutoDestructable(                \
                QUOTE(ClassName));                                            \
    }                                                                         \
                                                                              \
    void CONCAT(ClassName, ___CLASS_DESTRUCTOR_METHOD_NAME_EXTENSION___)(     \
            ClassName * object) {                                             \
        destruct((Object *) object);                                          \
    }


#define INVOKE_DESTRUCTOR(ClassName, instance)                      \
    CONCAT(ClassName, ___CLASS_DESTRUCTOR_METHOD_NAME_EXTENSION___) \
    ((ClassName *) instance)


#endif //OBJECTDEFINES_H
