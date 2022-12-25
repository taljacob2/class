#include "ClassInheritor.h"

void *ClassInheritorDestructor(ClassInheritor *classInheritor) {
    ClassDestructor(classInheritor->class);

    // ... Continue destructing `ClassInheritor` here ...
    free(classInheritor);

    return NULL;
}

ClassInheritor *ClassInheritorConstructor() {
    ClassInheritor *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    obj->class = ClassConstructorWithClassName(obj, "ClassInheritor");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&ClassInheritorConstructor)};
    obj->class->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ClassInheritorDestructor)};
    obj->class->thisObjectBase->destructable = &destructable;

    return obj;
}