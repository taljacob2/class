#include "CircleV4.h"

ObjectContainer *CircleV4Constructor() { return construct(QUOTE(CircleV4)); }

void CircleV4Destructor(ObjectContainer *objectContainer) {
    destruct(objectContainer);
}
