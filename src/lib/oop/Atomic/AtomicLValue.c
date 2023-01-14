#include "AtomicLValue.h"

/* --------------------------------- Extern --------------------------------- */

extern Object *ObjectConstructorWithoutAnyMembers(char *className);

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

extern void addPrimitivePrivateFieldWhichIsDynamicallyAllocated(Object *self, char *memberName,
                                     void *dynamicallyAllocatedMemberToAdd);

extern void addPrimitivePrivateFieldWhichIsStaticallyAllocated(
        Object *self, char *memberName, void *staticallyAllocatedMemberToAdd);

extern Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
        char *memberName, Object *objectThatContainsThisObjectAsAMember);

/* ----------------------------- Implementation ----------------------------- */

/* ---------------- ADD ---------------- */

void addDataWhichIsDynamicallyAllocated_AtomicLValue(
        AtomicLValue *atomicLValue, void *dynamicallyAllocatedData) {
    addPrimitivePrivateFieldWhichIsDynamicallyAllocated(
            (Object *) atomicLValue, __ATOMIC_LVALUE_MEMBER_NAME__,
            dynamicallyAllocatedData);
}

void addDataWhichIsStaticallyAllocated_AtomicLValue(
        AtomicLValue *atomicLValue, void *staticallyAllocatedData) {
    addPrimitivePrivateFieldWhichIsStaticallyAllocated(
            (Object *) atomicLValue, __ATOMIC_LVALUE_MEMBER_NAME__,
            staticallyAllocatedData);
}

/* ---------------- GET ---------------- */

void *getData_AtomicLValue(AtomicLValue *atomicLValue) {
    Legacy_Object *dataContainer =
            (Legacy_Object *) atomicLValue->getMemberValue(
                    (Object *) atomicLValue, PRIVATE, FIELD,
                    __ATOMIC_LVALUE_MEMBER_NAME__);

    return strcmp(dataContainer->legacyObjectComponent->CLASS_NAME,
                  "Legacy_AtomicFreer") == 0
                   ? ((Legacy_AtomicFreer *) dataContainer)->data
                   : ((Legacy_Node *) dataContainer)->data;
}

/* ---------------- SET ---------------- */

void setDataWhichIsDynamicallyAllocated_AtomicLValue(
        AtomicLValue *atomicLValue, void *dynamicallyAllocatedData) {
    setPrimitivePrivateField((Object *) atomicLValue,
                             __ATOMIC_LVALUE_MEMBER_NAME__,
                             dynamicallyAllocatedData);
}

void setDataWhichIsStaticallyAllocated_AtomicLValue(
        AtomicLValue *atomicLValue, void *staticallyAllocatedData) {
    setPrimitivePrivateFieldWhichIsStaticallyAllocated(
            (Object *) atomicLValue, __ATOMIC_LVALUE_MEMBER_NAME__,
            staticallyAllocatedData);
}

void setData(AtomicLValue *atomicLValue, void *data,
             BOOLEAN isDataDynamicallyAllocated) {
    if (isDataDynamicallyAllocated) {
        setDataWhichIsDynamicallyAllocated_AtomicLValue(atomicLValue, data);
    } else {
        setDataWhichIsStaticallyAllocated_AtomicLValue(atomicLValue, data);
    }
}

/* ------ Constructor & Destructor ------ */

void *AtomicLValueDestructor(AtomicLValue *atomicLValue) {

    /*
     * B.1: Get and remove lValue which is located at "__ATOMIC_LVALUE_MEMBER_NAME__"
     *      (i.e. `Object->privateFieldMemberName(__ATOMIC_LVALUE_MEMBER_NAME__)`).
     * B.2: Destruct lValue.
     */
    Legacy_Object *legacyObjectOfData =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberListProtected(
                    __ATOMIC_LVALUE_MEMBER_NAME__, (Object *) atomicLValue);
    legacyObjectOfData->legacyObjectComponent->destructable->destructor(
            legacyObjectOfData);

    return ObjectDestructor((Object *) atomicLValue);
}

AtomicLValue *AtomicLValueConstructor(void *  data,
                                      BOOLEAN isDataDynamicallyAllocated) {
    AtomicLValue *instance =
            (AtomicLValue *) ObjectConstructorWithoutAnyMembers("AtomicLValue");

    if (isDataDynamicallyAllocated) {
        addDataWhichIsDynamicallyAllocated_AtomicLValue(instance, data);
    } else {
        addDataWhichIsStaticallyAllocated_AtomicLValue(instance, data);
    }

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&AtomicLValueDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}
