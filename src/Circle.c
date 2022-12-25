#include "Circle.h"

void *ClassInheritorDestructor(Circle *classInheritor) {
    AutoDestructableDestructor(classInheritor->autoDestructable);

    // ... Continue destructing `Circle` here ...
    free(classInheritor);

    return NULL;
}

Circle *CircleConstructor() {
    Circle *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    obj->autoDestructable =
            AutoDestructableConstructorWithClassName(obj, "Circle");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&CircleConstructor)};
    obj->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ClassInheritorDestructor)};
    obj->object->destructable = &destructable;

    return obj;
}