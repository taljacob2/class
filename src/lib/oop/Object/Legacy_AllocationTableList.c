#include "Legacy_AllocationTableList.r"

Legacy_AllocationTableList *getLegacy_AllocationTableList() {
    static Legacy_AllocationTableList *instance = NULL;

    // Do lock here.
    if (instance == NULL) {
        instance = Legacy_AllocationTableListConstructor();
    }
    // Do unlock.

    return instance;
}

Legacy_AllocationTable *getGenericLegacy_AllocationTable() {
    Legacy_AllocationTable *legacyAllocationTable =
            getLegacy_AllocationTableList()
                    ->findLegacy_AllocationTableByClassName(
                            __GENERIC_ALLOCATION_TABLE_NAME__);

    if (legacyAllocationTable == NULL) {
        legacyAllocationTable = Legacy_AllocationTableConstructorWithClassName(
                (char *) __GENERIC_ALLOCATION_TABLE_NAME__);

        /*
         * Create a legacy_node that its data points to
         * `__GENERIC_ALLOCATION_TABLE_NAME__` Legacy_AllocationTable.
         */
        Legacy_Node *nodeThatItsDataPointsClassAllocationTable =
                Legacy_NodeConstructorWithData(legacyAllocationTable);

        /*
         * Add this legacy_node to
         * `GLOBAL_ALLOCATION_TABLE_LIST->legacy_allocationTableList`.
         */
        getLegacy_AllocationTableList()->allocationTableList->addAsUnique(
                getLegacy_AllocationTableList()->allocationTableList,
                nodeThatItsDataPointsClassAllocationTable,
                getLegacy_AllocationTableList()
                        ->predicateFindLegacy_AllocationTableByClassName,
                __GENERIC_ALLOCATION_TABLE_NAME__);
    }

    return legacyAllocationTable;
}

BOOLEAN predicateFindLegacy_AllocationTableByClassName(
        const Legacy_Node *nodeThatPointsToAllocationTable,
        const char *const  allocationTableClassName) {
    return strcmp(((Legacy_AllocationTable *) (nodeThatPointsToAllocationTable
                                                       ->data))
                          ->className,
                  allocationTableClassName) == 0;
}

/// @attention This is **not** generic.
void DestructLegacy_AllocationTableListNonGeneric(
        Legacy_List *allocationTableList) {
    if (allocationTableList == NULL) { return; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode           = allocationTableList->head;
         iterationNode != NULL; iterationNode = iterationNode->next) {
        if (iterationNodePrev != NULL) {

            // Destruct Node and retrieve the data.
            Legacy_AllocationTable *prevAllocationTable =
                    iterationNodePrev->legacyObjectComponent->destructable
                            ->destructor(iterationNodePrev);

            // Destruct data.
            prevAllocationTable->legacyObjectComponent->destructable
                    ->destructor(prevAllocationTable);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_allocationTableList->tail`.
    if (iterationNodePrev != NULL) {

        // Destruct Node and retrieve the data.
        Legacy_AllocationTable *prevAllocationTable =
                iterationNodePrev->legacyObjectComponent->destructable
                        ->destructor(iterationNodePrev);

        // Destruct data.
        prevAllocationTable->legacyObjectComponent->destructable->destructor(
                prevAllocationTable);
    }

    free(allocationTableList->legacyObjectComponent);

    free(allocationTableList);
}

/// @attention This is **not** generic.
void Legacy_AllocationTableListDestructor(
        Legacy_AllocationTableList *allocationTableList) {
    if (allocationTableList == NULL) { return; }

    DestructLegacy_AllocationTableListNonGeneric(
            allocationTableList->allocationTableList);

    free(allocationTableList->object);

    free(allocationTableList);
}

Legacy_AllocationTable *
findLegacy_AllocationTableByClassName(const char *allocationTableClassName) {
    Legacy_Node *foundNode =
            getLegacy_AllocationTableList()
                    ->allocationTableList->findNodeByPredicateOfConstString(
                            getLegacy_AllocationTableList()
                                    ->allocationTableList,
                            predicateFindLegacy_AllocationTableByClassName,
                            allocationTableClassName);

    if (foundNode != NULL) {
        return ((Legacy_AllocationTable *) (foundNode->data));
    } else {
        return NULL;
    }
}

void constructor_Legacy_AllocationTableList_fields(
        Legacy_AllocationTableList *allocationTableList) {
    allocationTableList->object = Legacy_ObjectComponentConstructorClassName(
            "Legacy_AllocationTableList");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(
                    &Legacy_AllocationTableListConstructor)};
    allocationTableList->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(
                    &Legacy_AllocationTableListDestructor)};
    allocationTableList->object->destructable = &destructable;

    allocationTableList->allocationTableList = Legacy_ListConstructor();

    allocationTableList->findLegacy_AllocationTableByClassName =
            &findLegacy_AllocationTableByClassName;
    allocationTableList->predicateFindLegacy_AllocationTableByClassName =
            &predicateFindLegacy_AllocationTableByClassName;
}


Legacy_AllocationTableList *Legacy_AllocationTableListConstructor() {
    Legacy_AllocationTableList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_Legacy_AllocationTableList_fields(instance);

    return instance;
}

// -----------------------------------------------------------------------------

/*
 * See more here: https://www.geeksforgeeks.org/functions-that-are-executed-before-and-after-main-in-c/
 */

/*
 * Apply the constructor attribute to runBeforeMain_Legacy_AllocationTableList()
 * so that it is executed before main()
 */
void runBeforeMain_Legacy_AllocationTableList(void)
        __attribute__((constructor));

/*
 * Apply the destructor attribute to runAfterMain_Legacy_AllocationTableList()
 * so that it is executed after main()
 */
void runAfterMain_Legacy_AllocationTableList(void) __attribute__((destructor));

/* implementation of runBeforeMain_Legacy_AllocationTableList */
void runBeforeMain_Legacy_AllocationTableList(void) {
    getLegacy_AllocationTableList();
}

/* implementation of runAfterMain_Legacy_AllocationTableList */
void runAfterMain_Legacy_AllocationTableList(void) {
    Legacy_AllocationTableListDestructor(getLegacy_AllocationTableList());
}
