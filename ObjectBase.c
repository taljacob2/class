#include "ObjectBase.h"

/**
 * @brief Destructs `ObjectBase`.
 *
 * Ensures there is no possibility to free the same address twice.
 *
 * @param objectBase The `ObjectBase` to destruct.
 * @see Destructable
 */
void ObjectBaseDestructor(ObjectBase *objectBase) {
    if (objectBase == NULL) { return; }

    if (objectBase->ALLOCATION_ADDRESS == NULL) { return; }

    free(objectBase->ALLOCATION_ADDRESS);

    objectBase->ALLOCATION_ADDRESS = NULL;
}

void constructor_ObjectBase_fields(ObjectBase *objectBase) {
    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&ObjectBaseConstructor)};
    objectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ObjectBaseDestructor)};
    objectBase->destructable = &destructable;
}

ObjectBase *ObjectBaseConstructor() {
    ObjectBase *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    obj->ALLOCATION_ADDRESS = obj;
    obj->CLASS_NAME         = "ObjectBase";

    constructor_ObjectBase_fields(obj);

    return obj;
}