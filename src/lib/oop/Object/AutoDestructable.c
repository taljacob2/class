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

    Legacy_Object *legacyObject = autoDestructable->allocatedAddress;

    Legacy_Object *allocatedAddressReturnValue =
            deleteAllocationAddressNodeFromAllocationTable(
                    getGenericLegacy_AllocationTable(),
                    autoDestructable->allocatedAddress);

    if (allocatedAddressReturnValue == NULL) {

        /*
         * The address was already deleted from
         * `getGenericLegacy_AllocationTable()`, and thus had probably already
         * been freed too.
         */
        return NULL;
    }

    return legacyObject;
}

void destructAllocatedAddressUnsafe(AutoDestructable *autoDestructable) {
    if (autoDestructable == NULL) { return; }

    free(autoDestructable->legacyObjectComponent);
    free(autoDestructable);
}

Legacy_Object *AutoDestructableDestructor(AutoDestructable *autoDestructable) {
    if (autoDestructable == NULL) { return NULL; }

    if (autoDestructable->allocatedAddress->legacyObjectComponent
                ->destructorInvocationStatus == WAS_NOT_INVOKED) {
        autoDestructable->allocatedAddress->legacyObjectComponent
                        ->destructorInvocationStatus == WAS_INVOKED_ONCE;

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
}

void saveLegacy_ObjectToAllocationTable(AutoDestructable *autoDestructable) {

    /*
     * Create a legacy_node that its data points to the "pointer of
     * `autoDestructable->allocatedAddress`".
     */
    Legacy_Node *nodeThatItsDataPointsToThePointerOfObj =
            Legacy_NodeConstructorWithData(autoDestructable->allocatedAddress);

    /*
     * Add this legacy_node to
     * `getGenericLegacy_AllocationTable()->allocationAddressList`.
     */
    getGenericLegacy_AllocationTable()->allocationAddressList->add(
            getGenericLegacy_AllocationTable()->allocationAddressList,
            nodeThatItsDataPointsToThePointerOfObj);
}

AutoDestructable *AutoDestructableConstructorWithClassName(
        Legacy_Object *legacyObjectToSaveItsAddressToAllocationTable,
        const char *   className) {
    AutoDestructable *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_AutoDestructable_fields(instance);

    instance->legacyObjectComponent->CLASS_NAME = className;

    /*
     * If `legacyObjectToSaveItsAddressToAllocationTable` is `NULL` use
     * `instance`.
     */
    instance->allocatedAddress =
            legacyObjectToSaveItsAddressToAllocationTable == NULL
                    ? (Legacy_Object *) instance
                    : legacyObjectToSaveItsAddressToAllocationTable;
    saveLegacy_ObjectToAllocationTable(instance);

    return instance;
}

AutoDestructable *AutoDestructableConstructor() {
    return AutoDestructableConstructorWithClassName(NULL, "AutoDestructable");
}
