#include "CircleV6.h"

/// @deprecated
//DEFINE_CLASS_C(CircleV6)


// Example for using "reflection". TODO: Add to `README.md`.
extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

// TODO: Continue implementation.
CircleV6 *CircleV6Constructor() {
    CircleV6 *instance = (CircleV6 *) ObjectConstructor("ClassV6");
//    instance->addPrivateField(instance, "radius", AtomicFloat(1.213));

    return instance;
}