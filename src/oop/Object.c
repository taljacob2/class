#include "Object.r"

/**
 * @brief Destructs `Object`.
 *
 * @param object The `Object` to destruct.
 * @see Destructable
 */
void ObjectDestructor(Object *object) { free(object); }

void constructor_Object_fields(Object *object) {
    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&ObjectConstructor)};
    object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ObjectDestructor)};
    object->destructable = &destructable;

    object->destructorInvocationStatus                = WAS_NOT_INVOKED;
    object->deleteFromAllocationTableInvocationStatus = WAS_NOT_INVOKED;
}

Object *ObjectConstructor() {
    Object *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    obj->CLASS_NAME = "Object";

    constructor_Object_fields(obj);

    return obj;
}