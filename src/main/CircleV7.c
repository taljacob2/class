#include "CircleV7.h"

CircleV7 *CircleV7Constructor() {
    Object *instance = ObjectConstructor("CircleV7");

    //    instance->addMemberValue(instance, PUBLIC, FIELD, "radius",
    //                             INTEGER_RVALUE_AS_OBJECT(2.34));

    // TODO: debug disable
    instance->addDoubleRValueMember(instance, PUBLIC, FIELD, "radius", 2.34);

    // TODO: debug
    printf("%f\n", (float) instance->getDoubleRValueMember(instance, PUBLIC,
                                                           FIELD, "radius"));


    //    instance->addIntegerRValueMember(instance, PUBLIC, FIELD, "radiusInt", 2);
    //    // TODO: debug
    //    printf("%f\n", (float) instance->getIntegerRValueMember(instance, PUBLIC,
    //                                                           FIELD, "radiusInt"));

    int *radiusAllocated = malloc(sizeof(int));
    *radiusAllocated     = 2;

    instance->addMemberValue(
            instance, PUBLIC, FIELD, "radiusAllocatedInt",
            (Object *) AtomicLValueConstructor(radiusAllocated, TRUE));
    // TODO: debug
    printf("%d\n", *((int *) instance->getMemberValue(instance, PUBLIC, FIELD,
                                                      "radiusAllocatedInt")));

    return (CircleV7 *) instance;
}
