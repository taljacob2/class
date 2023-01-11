#include "AtomicData.h"

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);
extern void addPrimitivePrivateField(Object *self, char *memberName,
                                     void *memberToAdd);
extern Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember);


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

    addPrimitivePrivateField((Object *) instance, __ATOMIC_MEMBER_NAME__,
                             dynamicallyAllocatedData);

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&AtomicDataDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}