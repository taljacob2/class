#include "ObjectBase.r"

/**
 * @brief Destructs `ObjectBase`.
 *
 * @param objectBase The `ObjectBase` to destruct.
 * @see Destructable
 */
void ObjectBaseDestructor(ObjectBase *objectBase) {
    free(objectBase);
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

    obj->CLASS_NAME         = "ObjectBase";

    constructor_ObjectBase_fields(obj);

    return obj;
}