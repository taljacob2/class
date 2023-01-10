#ifndef OBJECT_H
#define OBJECT_H

#include "AnonymousPointer.r"
#include "Legacy_MemberList.r"

// Forward declaration of incomplete type
typedef struct object Object;

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
struct object {
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;
    ANONYMOUS_POINTER_AS_FIELD;

    Legacy_Object *(*getPrivateMethod)(Object *self, char *memberName);
    Legacy_Object *(*getPublicMethod)(Object *self, char *memberName);
    Legacy_Object *(*getPrivateConstructor)(Object *self, char *memberName);
    Legacy_Object *(*getPublicConstructor)(Object *self, char *memberName);
    Legacy_Object *(*getPrivateDestructor)(Object *self, char *memberName);
    Legacy_Object *(*getPublicDestructor)(Object *self, char *memberName);
    Legacy_Object *(*getPrivateField)(Object *self, char *memberName);
    Legacy_Object *(*getPublicField)(Object *self, char *memberName);
    Legacy_Object *(*getImplementation)(Object *self, char *memberName);

    void (*addPrivateMethod)(Object *self, char *memberName,
                             Object *memberToAdd);
    void (*addPublicMethod)(Object *self, char *memberName,
                            Object *memberToAdd);
    void (*addPrivateConstructor)(Object *self, char *memberName,
                                  Object *memberToAdd);
    void (*addPublicConstructor)(Object *self, char *memberName,
                                 Object *memberToAdd);
    void (*addPrivateDestructor)(Object *self, char *memberName,
                                 Object *memberToAdd);
    void (*addPublicDestructor)(Object *self, char *memberName,
                                Object *memberToAdd);
    void (*addPrivateField)(Object *self, char *memberName,
                            Object *memberToAdd);
    void (*addPublicField)(Object *self, char *memberName, Object *memberToAdd);

    /**
     * Adds the implementation to the `fieldsLegacy_MemberList`, as a "public" field.
     *
     * @param object The object to add the implementation to.
     * @param memberName The member name you wish to call the implementation.
     *                   A common name is the class name you wish to implement.
     * @param constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter
     * The constructor to ObjectConstructor the class you wish to implement.
     * It should have 1 parameter: (const char *).
     */
    void (*addImplementation)(
            Object *self, char *memberName,
            Object *(
                    *constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter)(
                    const char *) );

    /**
     * Adds the implementation to the `fieldsLegacy_MemberList`, as a "public" field.
     *
     * For example:
     * @code
     * addImplementationThatIsConstructedWithLegacy_Object(
     *         instance, "AutoDestructable",
     *         (Legacy_Object * (*) (Legacy_Object *) )
     *                 AutoDestructableConstructorWithLegacy_Object);
     * @endcode
     *
     * @param object The object to add the implementation to.
     * @param memberName The member name you wish to call the implementation.
     *                   A common name is the class name you wish to implement.
     * @param constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter
     * The constructor to ObjectConstructor the class you wish to implement.
     * It should have 1 parameter: (Legacy_Object *).
     */
    void (*addImplementationThatIsConstructedWithLegacy_Object)(
            Object *self, char *memberName,
            Object *(
                    *constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter)(
                    Legacy_Object *) );
};

void *ObjectDestructor(Object *object);

Object *ObjectConstructor(char *className);

/// Add MemberList `#define`s for users.
#include "ObjectDefines.r"

#endif //OBJECT_H
