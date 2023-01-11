#include "AtomicData.h"

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);
extern void addPrimitivePrivateField(Object *self, char *memberName,
                                     void *memberToAdd);
extern Legacy_Object *
getPrivateFieldAndRemoveFromPrivateAccessModifierAndFieldsMemberList(
        Object *object, Object *objectThatContainsThisObjectAsAMember);
extern void        setMemberName(Object *object, const char *memberName);
extern const char *getMemberName(Object *object);


void setData(AtomicData *atomicData, void *dynamicallyAllocatedData) {
    addPrimitivePrivateField((Object *) atomicData,
                             (char *) getMemberName((Object *) atomicData),
                             dynamicallyAllocatedData);
}

void *getData(AtomicData *atomicData) {
    return atomicData->getPrivateField(
            (Object *) atomicData,
            (char *) getMemberName((Object *) atomicData));
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

AtomicData *AtomicDataConstructor(void *dynamicallyAllocatedData) {
    AtomicData *instance = (AtomicData *) ObjectConstructor("AtomicData");

    static unsigned char *ATOMIC_MEMBER_NAME;
    ATOMIC_MEMBER_NAME = getRandomString(20);

    // Set this `Object->memberName` to be `ATOMIC_MEMBER_NAME`.
    setMemberName((Object *) instance, (const char *) ATOMIC_MEMBER_NAME);

    setData(instance, dynamicallyAllocatedData);

    // TODO: debug
    //    printf("%s\n", (char *)dynamicallyAllocatedData);
    printf("%s\n", (char *) getData(instance));

    // TODO:
    //    instance->addPublicMethod(instance, "setData", AtomicMethod(&setData));
    //    instance->addPublicMethod(instance, "getData", AtomicMethod(&getData));

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&AtomicDataDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}