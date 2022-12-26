#include "Circle.h"

void *CircleDestructor(Circle *circle) {
    AutoDestructableDestructor(circle->autoDestructable);

    // ... Continue destructing `Circle` here ...

    free(circle->object);
    free(circle);

    return NULL;
}

Circle *CircleConstructor() {
    Circle *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->object = ObjectConstructorClassName("Circle");

    instance->autoDestructable = AutoDestructableConstructorWithClassName(
            (ObjectContainer *) instance, instance->object->CLASS_NAME);

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&CircleConstructor)};
    instance->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&CircleDestructor)};
    instance->object->destructable = &destructable;

    return instance;
}