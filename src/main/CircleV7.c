#include "CircleV7.h"

CircleV7 *CircleV7Constructor() {
    Object *instance = ObjectConstructor("CircleV7");

//    instance->addMemberValue(instance, PUBLIC, FIELD, "radius",
//                             RVALUE_AS_OBJECT(2.34));
//
//    // TODO: debug
//    printf("%f\n",
//           (float) instance->getMemberValue(instance, PUBLIC, FIELD, "radius"));










    float *floatAllocation = (float *)malloc(sizeof(float));
    *floatAllocation = 2.34f;

    instance->addMemberValue(instance, PUBLIC, FIELD, "radius",
            (Object *) AtomicLValueConstructor(floatAllocation, TRUE));

    // TODO: debug
    printf("%f\n",
           (float) instance->getMemberValue(instance, PUBLIC, FIELD, "radius"));



    return (CircleV7 *) instance;
}
