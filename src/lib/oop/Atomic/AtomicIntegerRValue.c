#include "AtomicIntegerRValue.h"

/* --------------------------------- Extern --------------------------------- */

extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

extern void *getData_AtomicLValue(AtomicLValue *atomicLValue);

extern void *AtomicLValueDestructor(AtomicLValue *atomicLValue);

/* ----------------------------- Implementation ----------------------------- */

IntegerRValue
getData_AtomicIntegerRValue(AtomicIntegerRValue *atomicIntegerRValue) {
    return (*(IntegerRValue *) getData_AtomicLValue(
            (AtomicLValue *) atomicIntegerRValue));
}

void *AtomicIntegerRValueDestructor(AtomicIntegerRValue *atomicRValue) {
    return AtomicLValueDestructor((AtomicLValue *) atomicRValue);
}

AtomicIntegerRValue *
AtomicIntegerRValueConstructor(IntegerRValue integerRValue) {
    IntegerRValue *primitiveDataAllocation = malloc(sizeof(IntegerRValue));
    *primitiveDataAllocation               = integerRValue;
    AtomicIntegerRValue *instance =
            (AtomicIntegerRValue *) AtomicLValueConstructor(
                    primitiveDataAllocation, TRUE);

    getLegacyObjectComponent((Object *) instance)->CLASS_NAME =
            "AtomicIntegerRValue";

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&AtomicIntegerRValueDestructor)};
    getLegacyObjectComponent((Object *) instance)->destructable = &destructable;

    return instance;
}
