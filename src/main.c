#include "Circle.h"
#include "CircleV2.h"
#include "oop/oop.h"
#include "CircleV4.h"
#include "CircleV5.h"

int main() {
    Circle *circle = CircleConstructor();

    CircleV2 *circleV2 = CircleV2Constructor();

    Object *object = ObjectConstructor("Object");

//    object->object->destructable->destructor(object);

//    AtomicInteger *atomicInteger = AtomicIntegerConstructor();

//    atomicInteger->object->object->destructable->destructor(atomicInteger);

    CircleV4 *circleV4 = CircleV4Constructor();

//    CircleV5 *circleV5 = CircleV5Constructor();



    return 0;
}
