#include "AutoDestructable.r"

void *deleteAllocationAddressNodeFromAllocationTable(
        Legacy_AllocationTable *OBJECT_ALLOCATION_TABLE,
        void *                  allocatedAddress) {
    return OBJECT_ALLOCATION_TABLE->allocationAddressList
            ->deleteNodeThatHasTheGivenData(
                    OBJECT_ALLOCATION_TABLE->allocationAddressList,
                    allocatedAddress);
}

Legacy_Object *
deleteAllocationAddressIfNeeded(AutoDestructable *autoDestructable) {
    if (autoDestructable == NULL) { return NULL; }

    Legacy_Object *objectContainer = autoDestructable->allocatedAddress;

    if (objectContainer->legacyObjectComponent
                ->deleteFromAllocationTableInvocationStatus ==
        WAS_NOT_INVOKED) {
        objectContainer->legacyObjectComponent
                ->deleteFromAllocationTableInvocationStatus =
                WAS_INVOKED_ONCE;

        Legacy_Object *allocatedAddressReturnValue =
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

    return objectContainer;
}

void destructAllocatedAddressUnsafe(AutoDestructable *autoDestructable) {
    if (autoDestructable == NULL) { return; }

    free(autoDestructable->legacyObjectComponent);
    free(autoDestructable);
}

Legacy_Object *
AutoDestructableDestructor(AutoDestructable *autoDestructable) {
    if (autoDestructable == NULL) { return NULL; }

    if (autoDestructable->allocatedAddress->legacyObjectComponent
                ->destructorInvocationStatus == WAS_NOT_INVOKED) {
        autoDestructable->legacyObjectComponent->destructorInvocationStatus ==
                WAS_INVOKED_ONCE;

        deleteAllocationAddressIfNeeded(autoDestructable);
    }

    if (autoDestructable->legacyObjectComponent->destructorInvocationStatus ==
        WAS_NOT_INVOKED) {
        autoDestructable->legacyObjectComponent->destructorInvocationStatus ==
                WAS_INVOKED_ONCE;

        destructAllocatedAddressUnsafe(autoDestructable);
    }
    return NULL;
}

void constructor_AutoDestructable_fields(AutoDestructable *autoDestructable) {
    autoDestructable->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("AutoDestructable");

    static Constructable const constructable = {
            .constructor =
                    (void *(*const)(void) )(&AutoDestructableConstructor)};
    autoDestructable->legacyObjectComponent->constructable = &constructable;

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AutoDestructableDestructor)};
    autoDestructable->legacyObjectComponent->destructable = &destructable;

    autoDestructable->legacyObjectComponent->destructorInvocationStatus = WAS_NOT_INVOKED;
    autoDestructable->legacyObjectComponent
            ->deleteFromAllocationTableInvocationStatus =
            WAS_NOT_INVOKED;
}

void saveObjectContainerToAllocationTable(AutoDestructable *autoDestructable) {
    autoDestructable->OBJECT_ALLOCATION_TABLE =
            getLegacy_AllocationTableList()
                    ->findLegacy_AllocationTableByClassName(
                            autoDestructable->legacyObjectComponent
                                    ->CLASS_NAME);
    if (autoDestructable->OBJECT_ALLOCATION_TABLE == NULL) {
        autoDestructable->OBJECT_ALLOCATION_TABLE =
                Legacy_AllocationTableConstructorWithClassName(
                        (char *) autoDestructable->legacyObjectComponent
                                ->CLASS_NAME);

        // Create a legacy_node that its data points to `autoDestructable->OBJECT_ALLOCATION_TABLE`.
        Legacy_Node *nodeThatItsDataPointsClassAllocationTable =
                Legacy_NodeConstructorWithData(
                        autoDestructable->OBJECT_ALLOCATION_TABLE);

        // Add this legacy_node to `GLOBAL_ALLOCATION_TABLE_LIST->legacy_allocationTableList`.
        getLegacy_AllocationTableList()->allocationTableList->addAsUnique(
                getLegacy_AllocationTableList()->allocationTableList,
                nodeThatItsDataPointsClassAllocationTable,
                getLegacy_AllocationTableList()
                        ->predicateFindLegacy_AllocationTableByClassName,
                autoDestructable->legacyObjectComponent->CLASS_NAME);
    }

    // Create a legacy_node that its data points to the "pointer of `autoDestructable->allocatedAddress`".
    Legacy_Node *nodeThatItsDataPointsToThePointerOfObj =
            Legacy_NodeConstructorWithData(autoDestructable->allocatedAddress);

    // Add this legacy_node to `autoDestructable->OBJECT_ALLOCATION_TABLE->allocationAddressList`.
    autoDestructable->OBJECT_ALLOCATION_TABLE->allocationAddressList->add(
            autoDestructable->OBJECT_ALLOCATION_TABLE->allocationAddressList,
            nodeThatItsDataPointsToThePointerOfObj);
}

AutoDestructable *AutoDestructableConstructorWithClassName(
        Legacy_Object *objectContainerToSaveItsAddressToAllocationTable,
        const char *     className) {
    AutoDestructable *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_AutoDestructable_fields(instance);

    instance->legacyObjectComponent->CLASS_NAME = className;

    // If `objectContainerToSaveItsAddressToAllocationTable` is `NULL` use `instance`.
    instance->allocatedAddress =
            objectContainerToSaveItsAddressToAllocationTable == NULL
                    ? (Legacy_Object *) instance
                    : objectContainerToSaveItsAddressToAllocationTable;
    saveObjectContainerToAllocationTable(instance);

    return instance;
}

AutoDestructable *AutoDestructableConstructor() {
    return AutoDestructableConstructorWithClassName(NULL, "AutoDestructable");
}
