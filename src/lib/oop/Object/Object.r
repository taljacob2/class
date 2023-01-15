#ifndef OBJECT_H
#define OBJECT_H

#include "../Atomic/RValueDefines.h"
#include "AnonymousPointer.r"
#include "Legacy_MemberList.r"

enum AccessModifier { SELF_ACCESS_MODIFIER, PRIVATE, PUBLIC };
enum MemberType { SELF_MEMBER_TYPE, METHOD, CONSTRUCTOR, DESTRUCTOR, FIELD };

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

    Object *(*getObjectMember)(Object *self, enum AccessModifier accessModifier,
                               enum MemberType memberType,
                               const char *    memberName);

    void (*addIntegerRValueMember)(Object *            self,
                                   enum AccessModifier accessModifier,
                                   enum MemberType     memberType,
                                   const char *        memberName,
                                   IntegerRValue       integerRValue);
    IntegerRValue (*getIntegerRValueMember)(Object *            self,
                                            enum AccessModifier accessModifier,
                                            enum MemberType     memberType,
                                            const char *        memberName);
    void (*addDoubleRValueMember)(Object *            self,
                                  enum AccessModifier accessModifier,
                                  enum MemberType     memberType,
                                  const char *        memberName,
                                  DoubleRValue        doubleRValue);
    DoubleRValue (*getDoubleRValueMember)(Object *            self,
                                          enum AccessModifier accessModifier,
                                          enum MemberType     memberType,
                                          const char *        memberName);

    Legacy_Object *(*getImplementation)(Object *self, char *memberName);

    // TODO: rename.
    void (*addMemberValue)(Object *self, enum AccessModifier accessModifier,
                           enum MemberType memberType, const char *memberName,
                           Object *memberToAdd);

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

#include "ObjectDefines.r"

#endif //OBJECT_H
