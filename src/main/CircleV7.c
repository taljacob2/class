#include "CircleV7.h"

CircleV7 *CircleV7Constructor() {
    Object *instance = ObjectConstructor("CircleV7");


    instance->addIntegerRValueMember(instance, PUBLIC, FIELD, "name",
                                     (IntegerRValue) "smallCircle");
    printf("%s\n", (const char *) instance->getIntegerRValueMember(
                           instance, PUBLIC, FIELD, "name"));
/*        instance->setIntegerRValueMember(instance, PUBLIC, FIELD, "name",
                                         (IntegerRValue) "largeCircle");
        printf("%s\n", (const char *) instance->getIntegerRValueMember(
                instance, PUBLIC, FIELD, "name"));*/


    instance->addDoubleRValueMember(instance, PUBLIC, FIELD, "radius", 2.34);
    printf("%f\n", (double) instance->getDoubleRValueMember(instance, PUBLIC,
                                                            FIELD, "radius"));
/*        instance->setDoubleRValueMember(instance, PUBLIC, FIELD, "radius", 987.213);
        printf("%f\n", (double) instance->getDoubleRValueMember(instance, PUBLIC,
                                                                FIELD, "radius"));*/


    instance->addIntegerRValueMember(instance, PUBLIC, FIELD, "radiusInt", 5);
    printf("%d\n", (int) instance->getIntegerRValueMember(instance, PUBLIC,
                                                          FIELD, "radiusInt"));
/*        instance->setIntegerRValueMember(instance, PUBLIC, FIELD, "radiusInt",
                                         9094);
        printf("%d\n", (int) instance->getIntegerRValueMember(instance, PUBLIC,
                                                              FIELD, "radiusInt"));*/


    int *radiusAllocated = malloc(sizeof(int));
    *radiusAllocated     = 2;
    instance->addLValueMember(instance, PUBLIC, FIELD, "radiusAllocatedInt",
                              (LValue) radiusAllocated, TRUE);
    printf("%d\n", *((int *) instance->getLValueMember(instance, PUBLIC, FIELD,
                                                       "radiusAllocatedInt")));

/*        int *radiusAllocatedNew = malloc(sizeof(int));
        *radiusAllocatedNew     = 313;
        instance->setLValueMember(instance, PUBLIC, FIELD, "radiusAllocatedInt",
                                  (LValue) radiusAllocatedNew, TRUE);
        printf("%d\n", *((int *) instance->getLValueMember(instance, PUBLIC, FIELD,
                                                           "radiusAllocatedInt")));

        int radiusStaticallyAllocated = 444;
        instance->setLValueMember(instance, PUBLIC, FIELD, "radiusAllocatedInt",
                                  (LValue) &radiusStaticallyAllocated, FALSE);
        printf("%d\n", *((int *) instance->getLValueMember(instance, PUBLIC, FIELD,
                                                           "radiusAllocatedInt")));*/


    instance->toString(instance);
/*        instance->toStringMembersByMemberAccessModifier(instance, PUBLIC);
        instance->toStringMembersByMemberType(instance, DESTRUCTOR);*/

    return (CircleV7 *) instance;
}
