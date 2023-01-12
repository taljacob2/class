#include "AtomicLValue.h"

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

extern void addPrimitivePrivateField(Object *self, char *memberName,
                                     void *dynamicallyAllocatedMemberToAdd);

void addPrimitivePrivateFieldWhichIsStaticallyAllocated(
        Object *self, char *memberName, void *staticallyAllocatedMemberToAdd);

extern Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember);

extern void setMemberName(Object *object, const char *memberName);

extern const char *getMemberName(Object *object);


void setData_AtomicLValue(AtomicLValue *atomicLValue,
                          void *        dynamicallyAllocatedData) {
    addPrimitivePrivateField((Object *) atomicLValue,
                             (char *) getMemberName((Object *) atomicLValue),
                             dynamicallyAllocatedData);
}

void setDataWhichIsStaticallyAllocated_AtomicLValue(
        AtomicLValue *atomicLValue, void *staticallyAllocatedData) {
    addPrimitivePrivateFieldWhichIsStaticallyAllocated(
            (Object *) atomicLValue,
            (char *) getMemberName((Object *) atomicLValue),
            staticallyAllocatedData);
}

void *getData_AtomicLValue(AtomicLValue *atomicLValue) {
    Legacy_Object *dataContainer = atomicLValue->getPrivateField(
            (Object *) atomicLValue,
            (char *) getMemberName((Object *) atomicLValue));

    return strcmp(dataContainer->legacyObjectComponent->CLASS_NAME,
                  "Legacy_AtomicFreer") == 0
                   ? ((Legacy_AtomicFreer *) dataContainer)->data
                   : ((Legacy_Node *) dataContainer)->data;
}

void *AtomicLValueDestructor(AtomicLValue *atomicLValue) {
    Legacy_Object *legacyObjectOfData =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
                    (Object *) atomicLValue, (Object *) atomicLValue);

    legacyObjectOfData->legacyObjectComponent->destructable->destructor(
            legacyObjectOfData);

    // `free` this `ATOMIC_MEMBER_NAME` which is located at `Object->memberName`.
    free((char *) getMemberName((Object *) atomicLValue));

    return ObjectDestructor((Object *) atomicLValue);
}

AtomicLValue *AtomicLValueConstructor(void *  data,
                                      BOOLEAN isDataDynamicallyAllocated) {
    AtomicLValue *instance = (AtomicLValue *) ObjectConstructor("AtomicLValue");

    // Set this `Object->memberName` to be `ATOMIC_MEMBER_NAME`.
    const unsigned char *ATOMIC_MEMBER_NAME = getRandomString(20);
    setMemberName((Object *) instance, (const char *) ATOMIC_MEMBER_NAME);

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