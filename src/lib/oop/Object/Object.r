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

    Legacy_Object *(*getPrivateMethod)(Object *object, char *memberName);
    Legacy_Object *(*getPublicMethod)(Object *object, char *memberName);
    Legacy_Object *(*getPrivateConstructor)(Object *object, char *memberName);
    Legacy_Object *(*getPublicConstructor)(Object *object, char *memberName);
    Legacy_Object *(*getPrivateDestructor)(Object *object, char *memberName);
    Legacy_Object *(*getPublicDestructor)(Object *object, char *memberName);
    Legacy_Object *(*getPrivateField)(Object *object, char *memberName);
    Legacy_Object *(*getPublicField)(Object *object, char *memberName);
    Legacy_Object *(*getImplementation)(Object *object, char *memberName);

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

    /**
     * Adds the implementation to the `fieldsLegacy_MemberList`, as a "public" field.
     *
     * @param object The object to add the implementation to.
     * @param memberName The member name you wish to call the implementation.
     *                   A common name is the class name you wish to implement.
     * @param constructorOfMemberClassToImplement__ThisConstructorHasAClassNameAsAParameter
     * The constructor to construct the class you wish to implement.
     * It should have 1 parameter: (const char *).
     */
    void (*addImplementation)(
            Object *object, char *memberName,
            Legacy_Object *(
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
     * The constructor to construct the class you wish to implement.
     * It should have 1 parameter: (Legacy_Object *).
     */
    void (*addImplementationThatIsConstructedWithLegacy_Object)(
            Object *object, char *memberName,
            Legacy_Object *(
                    *constructorOfMemberClassToImplement__ThisConstructorHasALegacy_ObjectAsParameter)(
                    Legacy_Object *) );
};

void *destruct(Object *object);

Object *construct(char *className);

Object *constructWithoutAutoDestructable(char *className);

/// Add MemberList `#define`s for users.
#include "ObjectDefines.r"

#endif //OBJECT_H
