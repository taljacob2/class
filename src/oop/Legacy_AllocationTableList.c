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
                    iterationNodePrev->object->destructable->destructor(
                            iterationNodePrev);

            // Destruct data.
            prevAllocationTable->object->destructable->destructor(
                    prevAllocationTable);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_allocationTableList->tail`.
    if (iterationNodePrev != NULL) {

        // Destruct Node and retrieve the data.
        Legacy_AllocationTable *prevAllocationTable =
                iterationNodePrev->object->destructable->destructor(
                        iterationNodePrev);

        // Destruct data.
        prevAllocationTable->object->destructable->destructor(
                prevAllocationTable);
    }

    free(allocationTableList->object);

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
    allocationTableList->object =
            Legacy_ObjectConstructorClassName("Legacy_AllocationTableList");

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

/* Apply the constructor attribute to runBeforeMain() so that it
    is executed before main() */
void runBeforeMain(void) __attribute__((constructor));

/* Apply the destructor attribute to runAfterMain() so that it
   is executed after main() */
void runAfterMain(void) __attribute__((destructor));

/* implementation of runBeforeMain */
void runBeforeMain(void) { getLegacy_AllocationTableList(); }

/* implementation of runAfterMain */
void runAfterMain(void) {
    Legacy_AllocationTableListDestructor(getLegacy_AllocationTableList());
}
