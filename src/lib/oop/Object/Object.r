#ifndef OBJECT_H
#define OBJECT_H

#include "MemberList.r"

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

    Legacy_Object *(*getPrivateMethod)(Object *object, char *memberName);
    Legacy_Object *(*getPublicMethod)(Object *object, char *memberName);
    Legacy_Object *(*getPrivateConstructor)(Object *object, char *memberName);
    Legacy_Object *(*getPublicConstructor)(Object *object, char *memberName);
    Legacy_Object *(*getPrivateDestructor)(Object *object, char *memberName);
    Legacy_Object *(*getPublicDestructor)(Object *object, char *memberName);
    Legacy_Object *(*getPrivateField)(Object *object, char *memberName);
    Legacy_Object *(*getPublicField)(Object *object, char *memberName);

    void (*addPrivateMethod)(Object *object, char *memberName,
                             Legacy_Object *memberToAdd);
    void (*addPublicMethod)(Object *object, char *memberName,
                            Legacy_Object *memberToAdd);
    void (*addPrivateConstructor)(Object *object, char *memberName,
                                  Legacy_Object *memberToAdd);
    void (*addPublicConstructor)(Object *object, char *memberName,
                                 Legacy_Object *memberToAdd);
    void (*addPrivateDestructor)(Object *object, char *memberName,
                                 Legacy_Object *memberToAdd);
    void (*addPublicDestructor)(Object *object, char *memberName,
                                Legacy_Object *memberToAdd);
    void (*addPrivateField)(Object *object, char *memberName,
                            Legacy_Object *memberToAdd);
    void (*addPublicField)(Object *object, char *memberName,
                           Legacy_Object *memberToAdd);
};

void addImplementation(
        Object *object, char *memberName,
        Legacy_Object *(
                *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(
                const char *) );

Legacy_Object *getImplementation(Object *object, char *memberName);

void *destruct(Object *object);

Object *construct(char *className);

/// Add MemberList `#define`s for users.
#include "ObjectDefines.r"

#endif //OBJECT_H
