#include "CircleV7.h"

CircleV7 *CircleV7Constructor() {
    Object *instance = ObjectConstructor("CircleV7");

    instance->addIntegerRValueMember(instance, PUBLIC, FIELD, "name",
                                     (IntegerRValue) "smallCircle");
    printf("%s\n", (char *) instance->getIntegerRValueMember(instance, PUBLIC,
                                                             FIELD, "name"));


    instance->addDoubleRValueMember(instance, PUBLIC, FIELD, "radius", 2.34);
    printf("%f\n", (double) instance->getDoubleRValueMember(instance, PUBLIC,
                                                            FIELD, "radius"));


    instance->addIntegerRValueMember(instance, PUBLIC, FIELD, "radiusInt", 5);
    printf("%d\n", (int) instance->getIntegerRValueMember(instance, PUBLIC,
                                                          FIELD, "radiusInt"));


    int *radiusAllocated = malloc(sizeof(int));
    *radiusAllocated     = 2;
    instance->addMemberValue(
            instance, PUBLIC, FIELD, "radiusAllocatedInt",
            (Object *) AtomicLValueConstructor(radiusAllocated, TRUE));
    printf("%d\n", *((int *) instance->getObjectMember(instance, PUBLIC, FIELD,
                                                      "radiusAllocatedInt")));


    return (CircleV7 *) instance;
}
