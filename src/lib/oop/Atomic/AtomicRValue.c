#include "AtomicRValue.h"

/* --------------------------------- Extern --------------------------------- */

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

extern void *getData_AtomicLValue(AtomicLValue *atomicLValue);

extern void *AtomicLValueDestructor(AtomicLValue *atomicLValue);

/* ----------------------------- Implementation ----------------------------- */

RValue getData_AtomicRValue(AtomicRValue *atomicRValue) {
    return (*(RValue *) getData_AtomicLValue((AtomicLValue *) atomicRValue));
}

void *AtomicRValueDestructor(AtomicRValue *atomicRValue) {
    return AtomicLValueDestructor((AtomicLValue *) atomicRValue);
}

AtomicRValue *AtomicRValueConstructor(RValue rValue) {
    RValue *primitiveDataAllocation = malloc(sizeof(RValue));
    *primitiveDataAllocation        = rValue;
    AtomicRValue *instance          = (AtomicRValue *) AtomicLValueConstructor(
            primitiveDataAllocation, TRUE);

    getLegacyObjectComponent((Object *) instance)->CLASS_NAME = "AtomicRValue";

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&AtomicRValueDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}
