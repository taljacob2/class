#include "Circle.h"
#include "CircleV2.h"
#include "oop/oop.h"

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
int main() {
    Circle *circle = CircleConstructor();

    CircleV2 *circleV2 = CircleV2Constructor();

    return 0;
}
