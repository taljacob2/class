#include "AtomicDoubleRValue.h"

/* --------------------------------- Extern --------------------------------- */

extern Object *ObjectConstructorWithoutAnyMembers(char *className);

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

extern void addPrimitivePrivateFieldWhichIsDynamicallyAllocated(
        Object *self, char *memberName, void *dynamicallyAllocatedMemberToAdd);

extern Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
        char *memberName, Object *objectThatContainsThisObjectAsAMember);

extern Legacy_Object *
getLegacyObjectMember(Object *                  self,
                      enum MemberAccessModifier memberAccessModifier,
                      enum MemberType memberType, const char *memberName);

/* ----------------------------- Implementation ----------------------------- */

void setData_AtomicDoubleRValue(AtomicDoubleRValue *atomicDoubleRValue,
                                void *primitiveDoubleNumberDataAllocation) {

    // Set `doubleNumber`.
    addPrimitivePrivateFieldWhichIsDynamicallyAllocated(
            (Object *) atomicDoubleRValue, __DOUBLE_RVALUE_MEMBER_NAME__,
            primitiveDoubleNumberDataAllocation);
}

DoubleRValue
getData_AtomicDoubleRValue(AtomicDoubleRValue *atomicDoubleRValue) {

    // "double" number as DoubleRValue.
    Legacy_Object *doubleNumberDataContainer =
            getLegacyObjectMember((Object *) atomicDoubleRValue, PRIVATE, FIELD,
                                  __DOUBLE_RVALUE_MEMBER_NAME__);
    DoubleRValue *doubleNumber =
            (DoubleRValue *) (((Legacy_Node *) doubleNumberDataContainer)
                                      ->data);

    return *doubleNumber;
}

void *AtomicDoubleRValueDestructor(AtomicDoubleRValue *atomicDoubleRValue) {

    // `doubleNumber`.
    Legacy_Object *legacyObjectOfDoubleNumberData =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
                    __DOUBLE_RVALUE_MEMBER_NAME__,
                    (Object *) atomicDoubleRValue);
    legacyObjectOfDoubleNumberData->legacyObjectComponent->destructable
            ->destructor(legacyObjectOfDoubleNumberData);

    return ObjectDestructor((Object *) atomicDoubleRValue);
}

AtomicDoubleRValue *AtomicDoubleRValueConstructor(DoubleRValue doubleRValue) {
    AtomicDoubleRValue *instance =
            (AtomicDoubleRValue *) ObjectConstructorWithoutAnyMembers(
                    "AtomicDoubleRValue");

    // Create `doubleNumber`.
    DoubleRValue *primitiveDoubleNumberDataAllocation =
            malloc(sizeof(DoubleRValue));
    *primitiveDoubleNumberDataAllocation = doubleRValue;

    setData_AtomicDoubleRValue(instance, primitiveDoubleNumberDataAllocation);

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AtomicDoubleRValueDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}
