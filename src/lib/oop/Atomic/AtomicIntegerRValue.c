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

    instance->setLValueMember((Object *) instance, PUBLIC, CONSTRUCTOR,
                              "AtomicIntegerRValueConstructor",
                              &AtomicIntegerRValueConstructor, FALSE);
    instance->setLValueMember((Object *) instance, PUBLIC, DESTRUCTOR,
                              "AtomicIntegerRValueDestructor",
                              &AtomicIntegerRValueDestructor, FALSE);

    return instance;
}
