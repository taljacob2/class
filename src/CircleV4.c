#include "CircleV4.h"

CircleV4 *CircleV4Constructor() {
    return (CircleV4 *) construct(QUOTE(CircleV4));
}

void CircleV4Destructor(CircleV4 *objectContainer) {
    destruct((Object *) objectContainer);
}
