#include "AtomicDoubleRValue.h"

/* --------------------------------- Extern --------------------------------- */

extern Object *ObjectConstructorWithoutAnyMembers(char *className);

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

extern void addPrimitivePrivateField(Object *self, char *memberName,
                                     void *dynamicallyAllocatedMemberToAdd);

extern void addPrimitivePrivateFieldWhichIsStaticallyAllocated(
        Object *self, char *memberName, void *staticallyAllocatedMemberToAdd);

extern Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember);

extern Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
        char *memberName, Object *objectThatContainsThisObjectAsAMember);

/* ----------------------------- Implementation ----------------------------- */

void setData_AtomicDoubleRValue(AtomicDoubleRValue *atomicDoubleRValue,
                                void *primitiveWholeNumberDataAllocation,
                                void *primitiveMantissaNumberDataAllocation) {

    // Set `wholeNumber`.
    addPrimitivePrivateField((Object *) atomicDoubleRValue,
                             __DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__,
                             primitiveWholeNumberDataAllocation);

    // Set `mantissaNumber`.
    addPrimitivePrivateField((Object *) atomicDoubleRValue,
                             __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__,
                             primitiveMantissaNumberDataAllocation);
}

DoubleRValue
getData_AtomicDoubleRValue(AtomicDoubleRValue *atomicDoubleRValue) {

    // "Whole" number as IntegerRValue.
    Legacy_Object *wholeNumberDataContainer =
            (Legacy_Object *) atomicDoubleRValue->getMemberValue(
                    (Object *) atomicDoubleRValue, PRIVATE, FIELD,
                    __DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__);
    IntegerRValue *wholeNumber =
            (IntegerRValue *) (((Legacy_Node *) wholeNumberDataContainer)
                                       ->data);

    // "Mantissa" number as IntegerRValue.
    Legacy_Object *mantissaNumberDataContainer =
            (Legacy_Object *) atomicDoubleRValue->getMemberValue(
                    (Object *) atomicDoubleRValue, PRIVATE, FIELD,
                    __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__);
    IntegerRValue *mantissaNumber =
            (IntegerRValue *) (((Legacy_Node *) mantissaNumberDataContainer)
                                       ->data);

    return (DoubleRValue)(*wholeNumber + *mantissaNumber);
}

void *AtomicDoubleRValueDestructor(AtomicDoubleRValue *atomicDoubleRValue) {

    // `wholeNumber`.
    Legacy_Object *legacyObjectOfWholeNumberData =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
                    __DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__,
                    (Object *) atomicDoubleRValue);
    legacyObjectOfWholeNumberData->legacyObjectComponent->destructable
            ->destructor(legacyObjectOfWholeNumberData);

    // `mantissaNumber`.
    Legacy_Object *legacyObjectOfMantissaNumberData =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
                    __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__,
                    (Object *) atomicDoubleRValue);
    legacyObjectOfMantissaNumberData->legacyObjectComponent->destructable
            ->destructor(legacyObjectOfMantissaNumberData);

    return ObjectDestructor((Object *) atomicDoubleRValue);
}

AtomicDoubleRValue *AtomicDoubleRValueConstructor(DoubleRValue doubleRValue) {
    AtomicDoubleRValue *instance =
            (AtomicDoubleRValue *) ObjectConstructorWithoutAnyMembers(
                    "AtomicDoubleRValue");

    // Create `wholeNumber`.
    IntegerRValue *primitiveWholeNumberDataAllocation =
            malloc(sizeof(IntegerRValue));
    IntegerRValue wholeNumber           = (IntegerRValue) doubleRValue;
    *primitiveWholeNumberDataAllocation = wholeNumber;

    // Create `mantissaNumber`.
    IntegerRValue *primitiveMantissaNumberDataAllocation =
            malloc(sizeof(IntegerRValue));
    IntegerRValue mantissaNumber = (IntegerRValue)(doubleRValue - wholeNumber);
    *primitiveMantissaNumberDataAllocation = mantissaNumber;

    setData_AtomicDoubleRValue(instance, primitiveWholeNumberDataAllocation,
                               primitiveMantissaNumberDataAllocation);

    // TODO:
    //    instance->addPublicMethod(instance, "setData", AtomicMethod(&setData_AtomicLValue));
    //    instance->addPublicMethod(instance, "getData", AtomicMethod(&getData_AtomicLValue));

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AtomicDoubleRValueDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}
