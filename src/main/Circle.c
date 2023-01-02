#include "Circle.h"

void *CircleDestructor(Circle *circle) {
    AutoDestructableDestructor(circle->autoDestructable);

    // ... Continue destructing `Circle` here ...

    free(circle->legacyObjectComponent);
    free(circle);

    return NULL;
}

Circle *CircleConstructor() {
    Circle *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("Circle");

    instance->autoDestructable = AutoDestructableConstructorWithClassName(
            (Legacy_Object *) instance,
            instance->legacyObjectComponent->CLASS_NAME);

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&CircleConstructor)};
    instance->legacyObjectComponent->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&CircleDestructor)};
    instance->legacyObjectComponent->destructable = &destructable;

    return instance;
}