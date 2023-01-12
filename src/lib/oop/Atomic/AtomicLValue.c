#include "AtomicLValue.h"

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

const unsigned char *getATOMIC_MEMBER_NAME(AtomicLValue *atomicLValue) {
    Legacy_Node *legacyNodeThatContainsATOMIC_MEMBER_NAME =
            (Legacy_Node *) atomicLValue->getMemberValue(
                    (Object *) atomicLValue, PRIVATE, FIELD,
                    __ATOMIC_MEMBER_NAME__);
    return (const unsigned char *)
            legacyNodeThatContainsATOMIC_MEMBER_NAME->data;
}

void setData_AtomicLValue(AtomicLValue *atomicLValue,
                          void *        dynamicallyAllocatedData) {
    const unsigned char *ATOMIC_MEMBER_NAME =
            getATOMIC_MEMBER_NAME(atomicLValue);

    addPrimitivePrivateField((Object *) atomicLValue,
                             (char *) ATOMIC_MEMBER_NAME,
                             dynamicallyAllocatedData);
}

void setDataWhichIsStaticallyAllocated_AtomicLValue(
        AtomicLValue *atomicLValue, void *staticallyAllocatedData) {
    const unsigned char *ATOMIC_MEMBER_NAME =
            getATOMIC_MEMBER_NAME(atomicLValue);

    addPrimitivePrivateFieldWhichIsStaticallyAllocated(
            (Object *) atomicLValue, (char *) ATOMIC_MEMBER_NAME,
            staticallyAllocatedData);
}

void *getData_AtomicLValue(AtomicLValue *atomicLValue) {
    const unsigned char *ATOMIC_MEMBER_NAME =
            getATOMIC_MEMBER_NAME(atomicLValue);

    Legacy_Object *dataContainer =
            (Legacy_Object *) atomicLValue->getMemberValue(
                    (Object *) atomicLValue, PRIVATE, FIELD,
                    (char *) ATOMIC_MEMBER_NAME);

    return strcmp(dataContainer->legacyObjectComponent->CLASS_NAME,
                  "Legacy_AtomicFreer") == 0
                   ? ((Legacy_AtomicFreer *) dataContainer)->data
                   : ((Legacy_Node *) dataContainer)->data;
}

void *AtomicLValueDestructor(AtomicLValue *atomicLValue) {

    // A.1: Get and remove "lValue memberName" (i.e. `ATOMIC_MEMBER_NAME`).
    Legacy_Object *legacyObjectOfDataMemberName =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
                    __ATOMIC_MEMBER_NAME__, (Object *) atomicLValue);
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
                    (char *) ATOMIC_MEMBER_NAME, (Object *) atomicLValue);
    legacyObjectOfData->legacyObjectComponent->destructable->destructor(
            legacyObjectOfData);

    /*
     * A.2: `free` "lValue memberName" which is located at
     *      `Object->privateFieldMemberName(__ATOMIC_MEMBER_NAME__)`.
     */
    free((void *) ATOMIC_MEMBER_NAME);

    return ObjectDestructor((Object *) atomicLValue);
}

AtomicLValue *AtomicLValueConstructor(void *  data,
                                      BOOLEAN isDataDynamicallyAllocated) {
    AtomicLValue *instance =
            (AtomicLValue *) ObjectConstructorWithoutAnyMembers("AtomicLValue");

    // Set this `Object->memberName` to be `ATOMIC_MEMBER_NAME`.
    const unsigned char *ATOMIC_MEMBER_NAME = getRandomString(20);

    /*
     * Add a private field that its memberName is the value of
     * `__ATOMIC_MEMBER_NAME__`, and its value is the value of
     * `ATOMIC_MEMBER_NAME`.
     */
    addPrimitivePrivateFieldWhichIsStaticallyAllocated(
            (Object *) instance, __ATOMIC_MEMBER_NAME__,
            (void *) ATOMIC_MEMBER_NAME);

    if (isDataDynamicallyAllocated) {
        setData_AtomicLValue(instance, data);
    } else {
        setDataWhichIsStaticallyAllocated_AtomicLValue(instance, data);
    }

    // TODO:
    //    instance->addPublicMethod(instance, "setData", AtomicMethod(&setData_AtomicLValue));
    //    instance->addPublicMethod(instance, "getData", AtomicMethod(&getData_AtomicLValue));

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&AtomicLValueDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}
