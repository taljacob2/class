#include "AllocationTableList.h"

/**
 * Singleton implementation.
 *
 * @attention Remember to `free` this singleton on the program's exit.
 *
 * @return
 * @see https://stackoverflow.com/a/803699/14427765
 */
AllocationTableList *getAllocationTableList() {
    static AllocationTableList *instance = NULL;

    // Do lock here.
    if (instance == NULL) {
        instance                     = AllocationTableListConstructor();
        GLOBAL_ALLOCATION_TABLE_LIST = instance;
    }
    // Do unlock.

    return instance;
}

BOOLEAN predicateFindAllocationTableByClassName(
        const Node *      nodeThatPointsToAllocationTable,
        const char *const allocationTableClassName) {
    return strcmp(((AllocationTable *) (nodeThatPointsToAllocationTable->data))
                          ->className,
                  allocationTableClassName) == 0;
}

/// @attention This is **not** generic.
void DestructAllocationTableListNonGeneric(List *allocationTableList) {
    if (allocationTableList == NULL) { return; }

    Node *iterationNodePrev = NULL;
    for (Node *iterationNode = allocationTableList->head; iterationNode != NULL;
         iterationNode       = iterationNode->next,
              iterationNodePrev = iterationNode) {
        if (iterationNodePrev != NULL) {
            AllocationTable *prevAllocationTable =
                    ((AllocationTable *) (iterationNodePrev->data));
            prevAllocationTable->thisObjectBase->destructable->destructor(
                    prevAllocationTable);
        }
    }

    // `iterationNodePrev` is `allocationTableList->tail`.
    if (iterationNodePrev != NULL) {
        AllocationTable *prevAllocationTable =
                ((AllocationTable *) (iterationNodePrev->data));
        prevAllocationTable->thisObjectBase->destructable->destructor(
                prevAllocationTable);
    }

    free(allocationTableList->thisObjectBase);

    free(allocationTableList);
}

void AllocationTableListDestructor(AllocationTableList *allocationTableList) {
    if (allocationTableList == NULL) { return; }

    DestructAllocationTableListNonGeneric(
            allocationTableList->allocationTableList);

    free(allocationTableList->thisObjectBase);

    free(allocationTableList);
}

AllocationTable *
findAllocationTableByClassName(const char *allocationTableClassName) {
    Node *foundNode =
            GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList
                    ->findNodeByPredicateOfConstString(
                            GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList,
                            predicateFindAllocationTableByClassName,
                            allocationTableClassName);

    if (foundNode != NULL) {
        return ((AllocationTable *) (foundNode->data));
    } else {
        return NULL;
    }
}

void constructor_AllocationTableList_fields(
        AllocationTableList *allocationTableList) {
    allocationTableList->thisObjectBase = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor =
                    (void *(*const)(void) )(&AllocationTableListConstructor)};
    allocationTableList->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AllocationTableListDestructor)};
    allocationTableList->thisObjectBase->destructable = &destructable;

    allocationTableList->allocationTableList = ListConstructor();
}


AllocationTableList *AllocationTableListConstructor() {
    AllocationTableList *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_AllocationTableList_fields(obj);

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
    GLOBAL_ALLOCATION_TABLE_LIST = getAllocationTableList();
}

/* implementation of runAfterMain */
void runAfterMain(void) {
    AllocationTableListDestructor(GLOBAL_ALLOCATION_TABLE_LIST);
}