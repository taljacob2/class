#include "CircleV7.h"

CircleV7 *CircleV7Constructor() {
    Object *instance = ObjectConstructor("CircleV7");

    instance->addMemberValue(instance, PUBLIC, FIELD, "radius",
                             RVALUE_AS_OBJECT(2.34));

    // TODO: debug
    printf("%f\n",
           (float) instance->getMemberValue(instance, PUBLIC, FIELD, "radius"));

    return (CircleV7 *) instance;
}
