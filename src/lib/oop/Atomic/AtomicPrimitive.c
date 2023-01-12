#include "AtomicPrimitive.h"

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

extern void *getData_AtomicData(AtomicData *atomicData);

extern void *AtomicDataDestructor(AtomicData *atomicData);

TypeOfPrimitive getData_AtomicPrimitive(AtomicPrimitive *atomicPrimitive) {
    return (*(TypeOfPrimitive *) getData_AtomicData(
            (AtomicData *) atomicPrimitive));
}

void *AtomicPrimitiveDestructor(AtomicPrimitive *atomicPrimitive) {
    return AtomicDataDestructor((AtomicData *) atomicPrimitive);
}

AtomicPrimitive *AtomicPrimitiveConstructor(TypeOfPrimitive primitiveData) {
    TypeOfPrimitive *primitiveDataAllocation = malloc(sizeof(TypeOfPrimitive));
    *primitiveDataAllocation                 = primitiveData;
    AtomicPrimitive *instance = (AtomicPrimitive *) AtomicDataConstructor(
            primitiveDataAllocation, TRUE);

    getLegacyObjectComponent((Object *) instance)->CLASS_NAME =
            "AtomicPrimitive";

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AtomicPrimitiveDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}
