#include "Object.r"

/**
 * @brief Destructs `Object`.
 *
 * @param object The `Object` to destruct.
 * @see Destructable
 */
void ObjectBaseDestructor(Object *object) { free(object); }

void constructor_ObjectBase_fields(Object *object) {
    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&ObjectBaseConstructor)};
    object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ObjectBaseDestructor)};
    object->destructable = &destructable;
}

Object *ObjectBaseConstructor() {
    Object *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    obj->CLASS_NAME = "Object";

    constructor_ObjectBase_fields(obj);

    return obj;
}