#include "AtomicData.h"

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);
extern void addPrimitivePrivateField(Object *self, char *memberName,
                                     void *memberToAdd);
extern Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember);


void setData(AtomicData *atomicData, void *dynamicallyAllocatedData) {
    addPrimitivePrivateField((Object *) atomicData, __ATOMIC_MEMBER_NAME__,
                             dynamicallyAllocatedData);
}

void *getData(AtomicData *atomicData) {
    return atomicData->getPrivateField((Object *) atomicData,
                                       __ATOMIC_MEMBER_NAME__);
}

void *AtomicDataDestructor(AtomicData *atomicData) {
    Legacy_Object *legacyObjectOfData =
            getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
                    (Object *) atomicData, (Object *) atomicData);

    legacyObjectOfData->legacyObjectComponent->destructable->destructor(
            legacyObjectOfData);

    return ObjectDestructor((Object *) atomicData);
}

AtomicData *AtomicDataConstructor(void *dynamicallyAllocatedData) {
    AtomicData *instance = (AtomicData *) ObjectConstructor("AtomicData");

    setData(instance, dynamicallyAllocatedData);

    // TODO:
    //    instance->addPublicMethod(instance, "setData", AtomicMethod(&setData));
    //    instance->addPublicMethod(instance, "getData", AtomicMethod(&getData));

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&AtomicDataDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}