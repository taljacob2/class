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

    return (CircleV7 *) instance;
}
