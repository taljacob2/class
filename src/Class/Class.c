#include "Class.r"

void print(Class *class) { printf("x = %d\n", class->x); }

void addOneToX(Class *class) { class->x += 1; }

void *deleteAllocationAddressNodeFromAllocationTable(
        Legacy_AllocationTable *CLASS_ALLOCATION_TABLE,
        void *                  allocatedAddress) {
    return CLASS_ALLOCATION_TABLE->allocationAddressList
            ->deleteNodeThatHasTheGivenData(
                    CLASS_ALLOCATION_TABLE->allocationAddressList,
                    allocatedAddress);
}

void *ClassDestructor(Class *class) {
    if (class == NULL) { return NULL; }

    if (!(class->statusCode == DESTRUCTOR_WAS_NOT_INVOKED)) { return NULL; }

    class->statusCode == DESTRUCTOR_WAS_INVOKED_ONCE;

    Class *allocatedAddress = deleteAllocationAddressNodeFromAllocationTable(
            class->CLASS_ALLOCATION_TABLE, class->allocatedAddress);

    if (allocatedAddress == NULL) {

        /*
         * The address was already deleted from
         * `class->CLASS_ALLOCATION_TABLE`, and thus had probably already
         * been freed too.
         */
        return NULL;
    }

    void *returnValue = NULL;

    if (allocatedAddress->thisObjectBase->CLASS_NAME != "Class") {
        returnValue =
                allocatedAddress->thisObjectBase->destructable->destructor(
                        allocatedAddress);
    }

    free(allocatedAddress->thisObjectBase);
    free(allocatedAddress);

    return returnValue;
}

void constructor_Class_fields(Class *class) {
    class->thisObjectBase = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&ClassConstructor)};
    class->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ClassDestructor)};
    class->thisObjectBase->destructable = &destructable;

    class->statusCode = DESTRUCTOR_WAS_NOT_INVOKED;

    // TODO: Remove redundant fields.
    class->x         = 1;
    class->print     = &print;
    class->addOneToX = &addOneToX;
}

void saveClassToAllocationTable(Class *obj) {
    obj->CLASS_ALLOCATION_TABLE =
            getLegacy_AllocationTableList()
                    ->findLegacy_AllocationTableByClassName(
                            obj->thisObjectBase->CLASS_NAME);
    if (obj->CLASS_ALLOCATION_TABLE == NULL) {
        obj->CLASS_ALLOCATION_TABLE =
                Legacy_AllocationTableConstructorWithClassName(
                        (char *) obj->thisObjectBase->CLASS_NAME);

        // Create a legacy_node that its data points to `obj->CLASS_ALLOCATION_TABLE`.
        Legacy_Node *nodeThatItsDataPointsClassAllocationTable =
                Legacy_NodeConstructorWithDataAndDataSize(
                        obj->CLASS_ALLOCATION_TABLE,
                        sizeof(Legacy_AllocationTable *));

        // Add this legacy_node to `GLOBAL_ALLOCATION_TABLE_LIST->legacy_allocationTableList`.
        getLegacy_AllocationTableList()->allocationTableList->add(
                getLegacy_AllocationTableList()->allocationTableList,
                nodeThatItsDataPointsClassAllocationTable);
    }

    // Create a legacy_node that its data points to the "pointer of `obj`".
    Legacy_Node *nodeThatItsDataPointsToThePointerOfObj =
            Legacy_NodeConstructorWithDataAndDataSize(obj, sizeof(void *));

    // Add this legacy_node to `obj->CLASS_ALLOCATION_TABLE->allocationAddressList`.
    obj->CLASS_ALLOCATION_TABLE->allocationAddressList->add(
            obj->CLASS_ALLOCATION_TABLE->allocationAddressList,
            nodeThatItsDataPointsToThePointerOfObj);
}

Class *
ClassConstructorWithClassName(void *objectToSaveItsAddressToAllocationTable,
                              const char *className) {
    Class *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Class_fields(obj);

    obj->thisObjectBase->CLASS_NAME = className;

    // If `objectToSaveItsAddressToAllocationTable` is `NULL` use `obj`.
    obj->allocatedAddress = objectToSaveItsAddressToAllocationTable == NULL
                                    ? obj
                                    : objectToSaveItsAddressToAllocationTable;
    saveClassToAllocationTable(obj->allocatedAddress);

    return obj;
}

Class *ClassConstructor() {
    return ClassConstructorWithClassName(NULL, "Class");
}
