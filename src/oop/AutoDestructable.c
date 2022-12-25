#include "AutoDestructable.r"

void print(AutoDestructable *autoDestructable) {
    printf("x = %d\n", autoDestructable->x);
}

void addOneToX(AutoDestructable *autoDestructable) { autoDestructable->x += 1; }

void *deleteAllocationAddressNodeFromAllocationTable(
        Legacy_AllocationTable *OBJECT_ALLOCATION_TABLE,
        void *                  allocatedAddress) {
    return OBJECT_ALLOCATION_TABLE->allocationAddressList
            ->deleteNodeThatHasTheGivenData(
                    OBJECT_ALLOCATION_TABLE->allocationAddressList,
                    allocatedAddress);
}

void *deleteAllocationAddressIfNeeded(AutoDestructable *autoDestructable) {
    if (autoDestructable == NULL) { return NULL; }

    if (autoDestructable->deleteFromAllocationTableInvocationStatus ==
        WAS_NOT_INVOKED) {
        autoDestructable->deleteFromAllocationTableInvocationStatus =
                WAS_INVOKED_ONCE;

        AutoDestructable *allocatedAddressReturnValue =
                deleteAllocationAddressNodeFromAllocationTable(
                        autoDestructable->OBJECT_ALLOCATION_TABLE,
                        autoDestructable->allocatedAddress);

        if (allocatedAddressReturnValue == NULL) {

            /*
             * The address was already deleted from
             * `autoDestructable->OBJECT_ALLOCATION_TABLE`, and thus had probably already
             * been freed too.
             */
            return NULL;
        }
    }

    return autoDestructable->allocatedAddress;
}

void *destructAllocatedAddressUnsafe(AutoDestructable *autoDestructable) {
    if (autoDestructable == NULL) { return NULL; }

    void *            returnValue = NULL;
    AutoDestructable *allocatedAddressAsClass =
            autoDestructable->allocatedAddress;
    if (strcmp(allocatedAddressAsClass->object->CLASS_NAME,
               "AutoDestructable") != 0) {
        returnValue = allocatedAddressAsClass->object->destructable->destructor(
                allocatedAddressAsClass);
    }

    free(allocatedAddressAsClass->object);
    free(allocatedAddressAsClass);

    return returnValue;
}

void *AutoDestructableDestructor(AutoDestructable *autoDestructable) {
    if (autoDestructable == NULL) { return NULL; }

    if (!(autoDestructable->destructorInvocationStatus == WAS_NOT_INVOKED)) {
        return NULL;
    }

    autoDestructable->destructorInvocationStatus == WAS_INVOKED_ONCE;

    deleteAllocationAddressIfNeeded(autoDestructable);

    return destructAllocatedAddressUnsafe(autoDestructable);
}

void constructor_AutoDestructable_fields(AutoDestructable *autoDestructable) {
    autoDestructable->object = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&ClassConstructor)};
    autoDestructable->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AutoDestructableDestructor)};
    autoDestructable->object->destructable = &destructable;

    autoDestructable->destructorInvocationStatus = WAS_NOT_INVOKED;
    autoDestructable->deleteFromAllocationTableInvocationStatus =
            WAS_NOT_INVOKED;

    // TODO: Remove redundant fields.
    autoDestructable->x         = 1;
    autoDestructable->print     = &print;
    autoDestructable->addOneToX = &addOneToX;
}

void saveObjectToAllocationTable(AutoDestructable *obj) {
    obj->OBJECT_ALLOCATION_TABLE =
            getLegacy_AllocationTableList()
                    ->findLegacy_AllocationTableByClassName(
                            obj->object->CLASS_NAME);
    if (obj->OBJECT_ALLOCATION_TABLE == NULL) {
        obj->OBJECT_ALLOCATION_TABLE =
                Legacy_AllocationTableConstructorWithClassName(
                        (char *) obj->object->CLASS_NAME);

        // Create a legacy_node that its data points to `obj->OBJECT_ALLOCATION_TABLE`.
        Legacy_Node *nodeThatItsDataPointsClassAllocationTable =
                Legacy_NodeConstructorWithDataAndDataSize(
                        obj->OBJECT_ALLOCATION_TABLE,
                        sizeof(Legacy_AllocationTable *));

        // Add this legacy_node to `GLOBAL_ALLOCATION_TABLE_LIST->legacy_allocationTableList`.
        getLegacy_AllocationTableList()->allocationTableList->add(
                getLegacy_AllocationTableList()->allocationTableList,
                nodeThatItsDataPointsClassAllocationTable);
    }

    // Create a legacy_node that its data points to the "pointer of `obj`".
    Legacy_Node *nodeThatItsDataPointsToThePointerOfObj =
            Legacy_NodeConstructorWithDataAndDataSize(obj, sizeof(void *));

    // Add this legacy_node to `obj->OBJECT_ALLOCATION_TABLE->allocationAddressList`.
    obj->OBJECT_ALLOCATION_TABLE->allocationAddressList->add(
            obj->OBJECT_ALLOCATION_TABLE->allocationAddressList,
            nodeThatItsDataPointsToThePointerOfObj);
}

AutoDestructable *AutoDestructableConstructorWithClassName(
        void *objectToSaveItsAddressToAllocationTable, const char *className) {
    AutoDestructable *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_AutoDestructable_fields(obj);

    obj->object->CLASS_NAME = className;

    // If `objectToSaveItsAddressToAllocationTable` is `NULL` use `obj`.
    obj->allocatedAddress = objectToSaveItsAddressToAllocationTable == NULL
                                    ? obj
                                    : objectToSaveItsAddressToAllocationTable;
    saveObjectToAllocationTable(obj->allocatedAddress);

    return obj;
}

AutoDestructable *ClassConstructor() {
    return AutoDestructableConstructorWithClassName(NULL, "AutoDestructable");
}
