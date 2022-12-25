#include "Circle.h"

void *CircleDestructor(Circle *circle) {
    AutoDestructableDestructor(circle->autoDestructable);

    // ... Continue destructing `Circle` here ...

    free(circle->object);
    free(circle);

    return NULL;
}

Circle *CircleConstructor() {
    Circle *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    obj->object = ObjectConstructor();

    obj->autoDestructable = AutoDestructableConstructorWithClassName(
            (ObjectContainer *) obj, "Circle");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&CircleConstructor)};
    obj->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&CircleDestructor)};
    obj->object->destructable = &destructable;

    return obj;
}