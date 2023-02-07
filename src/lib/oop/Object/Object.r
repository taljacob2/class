#ifndef OBJECT_H
#define OBJECT_H

#include "../Atomic/LValueDefines.h"
#include "../Atomic/RValueDefines.h"
#include "AnonymousPointer.r"
#include "Legacy_MemberList.r"

enum MemberAccessModifier { PRIVATE, PUBLIC };
enum MemberType { METHOD, CONSTRUCTOR, DESTRUCTOR, FIELD };

/* Forward declaration of incomplete type */
typedef struct object Object;

/** @see how to polymorph https://stackoverflow.com/a/8194632/14427765 */
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

    Object *(*getObjectMember)(Object *                  self,
                               enum MemberAccessModifier memberAccessModifier,
                               enum MemberType           memberType,
                               const char *              memberName);
    LValue (*getLValueMember)(Object *                  self,
                              enum MemberAccessModifier memberAccessModifier,
                              enum MemberType           memberType,
                              const char *              memberName);
    IntegerRValue (*getIntegerRValueMember)(
            Object *self, enum MemberAccessModifier accessModifier,
            enum MemberType memberType, const char *memberName);
    DoubleRValue (*getDoubleRValueMember)(
            Object *self, enum MemberAccessModifier accessModifier,
            enum MemberType memberType, const char *memberName);
    Legacy_Object *(*getImplementation)(Object *self, char *memberName);

    void (*addObjectMember)(Object *                  self,
                            enum MemberAccessModifier memberAccessModifier,
                            enum MemberType memberType, const char *memberName,
                            Object *memberToAdd);
    void (*addLValueMember)(Object *                  self,
                            enum MemberAccessModifier memberAccessModifier,
                            enum MemberType memberType, const char *memberName,
                            LValue  lValueData,
                            BOOLEAN isDataDynamicallyAllocated);
    void (*addIntegerRValueMember)(
            Object *self, enum MemberAccessModifier memberAccessModifier,
            enum MemberType memberType, const char *memberName,
            IntegerRValue integerRValue);
    void (*addDoubleRValueMember)(
            Object *self, enum MemberAccessModifier memberAccessModifier,
            enum MemberType memberType, const char *memberName,
            DoubleRValue doubleRValue);

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

    Object *(*setSelf)(Object *self, Object *value);
    Object *(*setObjectMember)(Object *                  self,
                               enum MemberAccessModifier memberAccessModifier,
                               enum MemberType           memberType,
                               const char *              memberName,
                               Object *                  memberValueToSet);
    LValue (*setLValueMember)(Object *                  self,
                              enum MemberAccessModifier memberAccessModifier,
                              enum MemberType           memberType,
                              const char *              memberName,
                              LValue                    lValueDataValueToSet,
                              BOOLEAN isDataDynamicallyAllocatedValueToSet);
    BOOLEAN(*setIntegerRValueMember)
    (Object *self, enum MemberAccessModifier memberAccessModifier,
     enum MemberType memberType, const char *memberName,
     IntegerRValue integerRValueValueToSet);
    BOOLEAN(*setDoubleRValueMember)
    (Object *self, enum MemberAccessModifier memberAccessModifier,
     enum MemberType memberType, const char *memberName,
     DoubleRValue doubleRValueValueToSet);

    BOOLEAN(*toStringMembersByMemberAccessModifier)
    (Object *self, enum MemberAccessModifier memberAccessModifier);
    BOOLEAN(*toStringMembersByMemberType)
    (Object *self, enum MemberType memberType);
    void (*toString)(Object *self);
};

void *ObjectDestructor(Object *object);

Object *ObjectConstructor(char *className);

#include "ObjectDefines.r"

#endif /* OBJECT_H */
