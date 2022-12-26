#include "Legacy_AllocationTable.r"
#include "AutoDestructable.r"

/// @attention This is generic for all **Legacy_Object** implementors ( = ObjectContainer).
void *
Legacy_AllocationTableDestructor(Legacy_AllocationTable *allocationTable) {
    if (allocationTable == NULL) { return NULL; }

    allocationTable->allocationAddressList
            ->Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData(
                    allocationTable->allocationAddressList);

    free(allocationTable->object);

    free(allocationTable);

    return NULL;
}

void constructor_Legacy_AllocationTable_fields(
        Legacy_AllocationTable *allocationTable) {
    allocationTable->object =
            Legacy_ObjectConstructorClassName("Legacy_AllocationTable");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(
                    &Legacy_AllocationTableConstructor)};
    allocationTable->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(
                    &Legacy_AllocationTableDestructor)};
    allocationTable->object->destructable = &destructable;

    allocationTable->className             = "";
    allocationTable->allocationAddressList = Legacy_ListConstructor();
}

Legacy_AllocationTable *Legacy_AllocationTableConstructor() {
    Legacy_AllocationTable *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_Legacy_AllocationTable_fields(instance);

    return instance;
}

Legacy_AllocationTable *
Legacy_AllocationTableConstructorWithClassName(const char *className) {
    Legacy_AllocationTable *obj = Legacy_AllocationTableConstructor();

    obj->className = className;

    return obj;
}
