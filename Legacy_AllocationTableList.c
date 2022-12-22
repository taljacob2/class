#include "Legacy_AllocationTableList.h"

/**
 * Singleton implementation.
 *
 * @attention Remember to `free` this singleton on the program's exit.
 *
 * @return
 * @see https://stackoverflow.com/a/803699/14427765
 */
Legacy_AllocationTableList *getLegacy_AllocationTableList() {
    static Legacy_AllocationTableList *instance = NULL;

    // Do lock here.
    if (instance == NULL) {
        instance                     = Legacy_AllocationTableListConstructor();
        GLOBAL_ALLOCATION_TABLE_LIST = instance;
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
         iterationNode != NULL; iterationNode = iterationNode->next,
                     iterationNodePrev        = iterationNode) {
        if (iterationNodePrev != NULL) {
            Legacy_AllocationTable *prevAllocationTable =
                    ((Legacy_AllocationTable *) (iterationNodePrev->data));
            prevAllocationTable->thisObjectBase->destructable->destructor(
                    prevAllocationTable);
        }
    }

    // `iterationNodePrev` is `legacy_allocationTableList->tail`.
    if (iterationNodePrev != NULL) {
        Legacy_AllocationTable *prevAllocationTable =
                ((Legacy_AllocationTable *) (iterationNodePrev->data));
        prevAllocationTable->thisObjectBase->destructable->destructor(
                prevAllocationTable);
    }

    free(allocationTableList->thisObjectBase);

    free(allocationTableList);
}

/// @attention This is **not** generic.
void Legacy_AllocationTableListDestructor(
        Legacy_AllocationTableList *allocationTableList) {
    if (allocationTableList == NULL) { return; }

    DestructLegacy_AllocationTableListNonGeneric(
            allocationTableList->allocationTableList);

    free(allocationTableList->thisObjectBase);

    free(allocationTableList);
}

Legacy_AllocationTable *
findLegacy_AllocationTableByClassName(const char *allocationTableClassName) {
    Legacy_Node *foundNode =
            GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList
                    ->findNodeByPredicateOfConstString(
                            GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList,
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
    allocationTableList->thisObjectBase = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(
                    &Legacy_AllocationTableListConstructor)};
    allocationTableList->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(
                    &Legacy_AllocationTableListDestructor)};
    allocationTableList->thisObjectBase->destructable = &destructable;

    allocationTableList->allocationTableList = Legacy_ListConstructor();

    allocationTableList->findLegacy_AllocationTableByClassName =
            &findLegacy_AllocationTableByClassName;
}


Legacy_AllocationTableList *Legacy_AllocationTableListConstructor() {
    Legacy_AllocationTableList *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Legacy_AllocationTableList_fields(obj);

    return obj;
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
void runBeforeMain(void) {
    GLOBAL_ALLOCATION_TABLE_LIST = getLegacy_AllocationTableList();
}

/* implementation of runAfterMain */
void runAfterMain(void) {
    Legacy_AllocationTableListDestructor(GLOBAL_ALLOCATION_TABLE_LIST);
}