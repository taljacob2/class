#include "CircleV4.h"

CircleV4 *CircleV4Constructor() {
    return (CircleV4 *) ObjectConstructor(QUOTE(CircleV4));
}

void CircleV4Destructor(CircleV4 *object) {
    ObjectDestructor((Object *) object); }
