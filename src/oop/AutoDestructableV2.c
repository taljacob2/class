#include "AutoDestructableV2.r"

void *deleteAllocationAddressNodeFromAllocationTable(
        Legacy_AllocationTable *OBJECT_ALLOCATION_TABLE,
        void *                  allocatedAddress) {
    return OBJECT_ALLOCATION_TABLE->allocationAddressList
            ->deleteNodeThatHasTheGivenData(
                    OBJECT_ALLOCATION_TABLE->allocationAddressList,
                    allocatedAddress);
}

Object *
deleteAllocationAddressIfNeeded(AutoDestructableV2 *autoDestructableV2) {
    if (autoDestructableV2 == NULL) { return NULL; }

    Object *object = autoDestructableV2->allocatedAddress;

    if (object->deleteFromAllocationTableInvocationStatus == WAS_NOT_INVOKED) {
        object->deleteFromAllocationTableInvocationStatus = WAS_INVOKED_ONCE;

        Object *allocatedAddressReturnValue =
                deleteAllocationAddressNodeFromAllocationTable(
                        autoDestructableV2->OBJECT_ALLOCATION_TABLE,
                        autoDestructableV2->allocatedAddress);

        if (allocatedAddressReturnValue == NULL) {

            /*
             * The address was already deleted from
             * `autoDestructableV2->OBJECT_ALLOCATION_TABLE`, and thus had probably already
             * been freed too.
             */
            return NULL;
        }
    }

    return object;
}

void destructAllocatedAddressUnsafe(AutoDestructableV2 *autoDestructableV2) {
    if (autoDestructableV2 == NULL) { return; }

    free(autoDestructableV2->object);
    free(autoDestructableV2);
}

Object *AutoDestructableV2Destructor(AutoDestructableV2 *autoDestructableV2) {
    if (autoDestructableV2 == NULL) { return NULL; }

    if (autoDestructableV2->allocatedAddress->destructorInvocationStatus ==
        WAS_NOT_INVOKED) {
        autoDestructableV2->object->destructorInvocationStatus ==
                WAS_INVOKED_ONCE;

        deleteAllocationAddressIfNeeded(autoDestructableV2);
    }

    if (autoDestructableV2->object->destructorInvocationStatus ==
        WAS_NOT_INVOKED) {
        autoDestructableV2->object->destructorInvocationStatus ==
                WAS_INVOKED_ONCE;

        destructAllocatedAddressUnsafe(autoDestructableV2);
    }
    return NULL;
}

void constructor_AutoDestructableV2_fields(
        AutoDestructableV2 *autoDestructableV2) {
    autoDestructableV2->object = ObjectConstructor();

    static Constructable const constructable = {
            .constructor =
                    (void *(*const)(void) )(&AutoDestructableV2Constructor)};
    autoDestructableV2->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AutoDestructableV2Destructor)};
    autoDestructableV2->object->destructable = &destructable;

    autoDestructableV2->object->destructorInvocationStatus = WAS_NOT_INVOKED;
    autoDestructableV2->object->deleteFromAllocationTableInvocationStatus =
            WAS_NOT_INVOKED;
}

void saveObjectToAllocationTable(AutoDestructableV2 *autoDestructableV2) {
    autoDestructableV2->OBJECT_ALLOCATION_TABLE =
            getLegacy_AllocationTableList()
                    ->findLegacy_AllocationTableByClassName(
                            autoDestructableV2->object->CLASS_NAME);
    if (autoDestructableV2->OBJECT_ALLOCATION_TABLE == NULL) {
        autoDestructableV2->OBJECT_ALLOCATION_TABLE =
                Legacy_AllocationTableConstructorWithClassName(
                        (char *) autoDestructableV2->object->CLASS_NAME);

        // Create a legacy_node that its data points to `autoDestructableV2->OBJECT_ALLOCATION_TABLE`.
        Legacy_Node *nodeThatItsDataPointsClassAllocationTable =
                Legacy_NodeConstructorWithDataAndDataSize(
                        autoDestructableV2->OBJECT_ALLOCATION_TABLE,
                        sizeof(Legacy_AllocationTable *));

        // Add this legacy_node to `GLOBAL_ALLOCATION_TABLE_LIST->legacy_allocationTableList`.
        // TODO: best practice to change `add` to `addAsUnique`.
        getLegacy_AllocationTableList()->allocationTableList->add(
                getLegacy_AllocationTableList()->allocationTableList,
                nodeThatItsDataPointsClassAllocationTable);
    }

    // Create a legacy_node that its data points to the "pointer of `autoDestructableV2->allocatedAddress`".
    Legacy_Node *nodeThatItsDataPointsToThePointerOfObj =
            Legacy_NodeConstructorWithDataAndDataSize(
                    autoDestructableV2->allocatedAddress, sizeof(Object *));

    // Add this legacy_node to `autoDestructableV2->OBJECT_ALLOCATION_TABLE->allocationAddressList`.
    // TODO: best practice to change `add` to `addAsUnique`.
    autoDestructableV2->OBJECT_ALLOCATION_TABLE->allocationAddressList->add(
            autoDestructableV2->OBJECT_ALLOCATION_TABLE->allocationAddressList,
            nodeThatItsDataPointsToThePointerOfObj);
}

AutoDestructableV2 *AutoDestructableV2ConstructorWithClassName(
        Object *    objectToSaveItsAddressToAllocationTable,
        const char *className) {
    AutoDestructableV2 *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_AutoDestructableV2_fields(instance);

    instance->object->CLASS_NAME = className;

    // If `objectToSaveItsAddressToAllocationTable` is `NULL` use `instance`.
    instance->allocatedAddress =
            objectToSaveItsAddressToAllocationTable == NULL
                    ? (Object *) instance
                    : objectToSaveItsAddressToAllocationTable;
    saveObjectToAllocationTable(instance);

    return instance;
}

AutoDestructableV2 *AutoDestructableV2Constructor() {
    return AutoDestructableV2ConstructorWithClassName(NULL,
                                                      "AutoDestructableV2");
}
