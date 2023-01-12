#include "AtomicData.h"

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


void setData(AtomicData *atomicData, void *dynamicallyAllocatedData) {
    addPrimitivePrivateField((Object *) atomicData,
                             (char *) getMemberName((Object *) atomicData),
                             dynamicallyAllocatedData);
}

void setDataWhichIsStaticallyAllocated(AtomicData *atomicData,
                                       void *      staticallyAllocatedData) {
    addPrimitivePrivateFieldWhichIsStaticallyAllocated(
            (Object *) atomicData,
            (char *) getMemberName((Object *) atomicData),
            staticallyAllocatedData);
}

void *getData_AtomicData(AtomicData *atomicData) {
    Legacy_Object *dataContainer = atomicData->getPrivateField(
            (Object *) atomicData,
            (char *) getMemberName((Object *) atomicData));

    return strcmp(dataContainer->legacyObjectComponent->CLASS_NAME,
                  "Legacy_AtomicFreer") == 0
                   ? ((Legacy_AtomicFreer *) dataContainer)->data
                   : ((Legacy_Node *) dataContainer)->data;
}

void *AtomicDataDestructor(AtomicData *atomicData) {
    Legacy_Object *legacyObjectOfData =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
                    (Object *) atomicData, (Object *) atomicData);

    legacyObjectOfData->legacyObjectComponent->destructable->destructor(
            legacyObjectOfData);

    // `free` this `ATOMIC_MEMBER_NAME` which is located at `Object->memberName`.
    free((char *) getMemberName((Object *) atomicData));

    return ObjectDestructor((Object *) atomicData);
}

AtomicData *AtomicDataConstructor(void *  data,
                                  BOOLEAN isDataDynamicallyAllocated) {
    AtomicData *instance = (AtomicData *) ObjectConstructor("AtomicData");

    // Set this `Object->memberName` to be `ATOMIC_MEMBER_NAME`.
    const unsigned char *ATOMIC_MEMBER_NAME = getRandomString(20);
    setMemberName((Object *) instance, (const char *) ATOMIC_MEMBER_NAME);

    if (isDataDynamicallyAllocated) {
        setData(instance, data);
    } else {
        setDataWhichIsStaticallyAllocated(instance, data);
    }

    // TODO:
    //    instance->addPublicMethod(instance, "setData", AtomicMethod(&setData));
    //    instance->addPublicMethod(instance, "getData", AtomicMethod(&getData_AtomicData));

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&AtomicDataDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}