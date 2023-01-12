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

extern const unsigned char *getATOMIC_MEMBER_NAME(AtomicLValue *atomicLValue);

void setData_AtomicDoubleRValue(AtomicDoubleRValue *atomicDoubleRValue,
                                void *primitiveWholeNumberDataAllocation,
                                void *primitiveMantissaNumberDataAllocation) {
    const unsigned char *ATOMIC_MEMBER_NAME =
            getATOMIC_MEMBER_NAME((AtomicLValue *) atomicDoubleRValue);

    // Set `wholeNumber`.
    const char *wholeNumberMemberName =
            concat((const char *) ATOMIC_MEMBER_NAME,
                   __DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__);
    addPrimitivePrivateField((Object *) atomicDoubleRValue,
                             (char *) wholeNumberMemberName,
                             primitiveWholeNumberDataAllocation);
    free((void *) wholeNumberMemberName);

    // Set `mantissaNumber`.
    const char *mantissaNumberMemberName =
            concat((const char *) ATOMIC_MEMBER_NAME,
                   __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__);
    addPrimitivePrivateField((Object *) atomicDoubleRValue,
                             (char *) mantissaNumberMemberName,
                             primitiveMantissaNumberDataAllocation);
    free((void *) mantissaNumberMemberName);
}

DoubleRValue getData_AtomicDoubleRValue(AtomicLValue *atomicLValue) {
    const unsigned char *ATOMIC_MEMBER_NAME =
            getATOMIC_MEMBER_NAME(atomicLValue);

    // "Whole" number as IntegerRValue.
    const char *wholeNumberMemberName =
            concat((const char *) ATOMIC_MEMBER_NAME,
                   __DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__);
    Legacy_Object *wholeNumberDataContainer =
            (Legacy_Object *) atomicLValue->getMemberValue(
                    (Object *) atomicLValue, PRIVATE, FIELD,
                    (char *) wholeNumberMemberName);
    IntegerRValue wholeNumber =
            (IntegerRValue)(((Legacy_Node *) wholeNumberDataContainer)->data);
    free((void *) wholeNumberMemberName);

    // "Mantissa" number as IntegerRValue.
    const char *mantissaNumberMemberName =
            concat((const char *) ATOMIC_MEMBER_NAME,
                   __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__);
    Legacy_Object *mantissaNumberDataContainer =
            (Legacy_Object *) atomicLValue->getMemberValue(
                    (Object *) atomicLValue, PRIVATE, FIELD,
                    (char *) mantissaNumberMemberName);
    IntegerRValue mantissaNumber = (IntegerRValue)(
            ((Legacy_Node *) mantissaNumberDataContainer)->data);
    free((void *) mantissaNumberMemberName);

    return (DoubleRValue)(wholeNumber + mantissaNumber);
}

// TODO:
void *AtomicDoubleRValueDestructor(AtomicDoubleRValue *atomicDoubleRValue) {

    // A.1: Get and remove "lValue memberName" (i.e. `ATOMIC_MEMBER_NAME`).
    Legacy_Object *legacyObjectOfDataMemberName =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
                    __ATOMIC_MEMBER_NAME__, (Object *) atomicDoubleRValue);
    const unsigned char *ATOMIC_MEMBER_NAME =
            legacyObjectOfDataMemberName->legacyObjectComponent->destructable
                    ->destructor(legacyObjectOfDataMemberName);

    /*
     * B.1: Get and remove lValue which is located at "lValue memberName"
     *      (i.e. `Object->privateFieldMemberName(ATOMIC_MEMBER_NAME)`).
     * B.2: Destruct lValue.
     */
    Legacy_Object *legacyObjectOfData =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
                    (char *) ATOMIC_MEMBER_NAME, (Object *) atomicDoubleRValue);
    legacyObjectOfData->legacyObjectComponent->destructable->destructor(
            legacyObjectOfData);

    /*
     * A.2: `free` "lValue memberName" which is located at
     *      `Object->privateFieldMemberName(__ATOMIC_MEMBER_NAME__)`.
     */
    free((void *) ATOMIC_MEMBER_NAME);

    return ObjectDestructor((Object *) atomicDoubleRValue);
}

AtomicDoubleRValue *AtomicDoubleRValueConstructor(DoubleRValue doubleRValue) {
    AtomicDoubleRValue *instance =
            (AtomicDoubleRValue *) ObjectConstructorWithoutAnyMembers(
                    "AtomicDoubleRValue");

    const unsigned char *ATOMIC_MEMBER_NAME = getRandomString(20);

    /*
     * Add a private field that its memberName is the value of
     * `__ATOMIC_MEMBER_NAME__`, and its value is the value of
     * `ATOMIC_MEMBER_NAME`.
     */
    addPrimitivePrivateFieldWhichIsStaticallyAllocated(
            (Object *) instance, __ATOMIC_MEMBER_NAME__,
            (void *) ATOMIC_MEMBER_NAME);

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
