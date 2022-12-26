#include "Circle.h"
#include "CircleV2.h"
#include "oop/Object/oop.h"

int main() {
    Circle *circle = CircleConstructor();

    CircleV2 *circleV2 = CircleV2Constructor();

    Object *object = ObjectConstructor("Object");

    return 0;
}
