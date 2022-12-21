#ifndef ALLOCATIONTABLELIST_H
#define ALLOCATIONTABLELIST_H

#include "AllocationTable.h"
#include "List.h"

#include <stdio.h>
#include <string.h>

// Forward declaration of incomplete type
typedef struct allocationTableList AllocationTableList;

struct allocationTableList {
    List *allocationTableList;
};

AllocationTableList *GLOBAL_ALLOCATION_TABLE_LIST = NULL;

static void constructor_AllocationTableList_fields(
        AllocationTableList *allocationTableList) {
    allocationTableList->allocationTableList = ListConstructor();
}

AllocationTableList *AllocationTableListConstructor() {
    AllocationTableList *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_AllocationTableList_fields(obj);

    return obj;
}

void AllocationTableListDestructor(AllocationTableList *allocationTableList) {
    if (allocationTableList == NULL) { return; }

    ListDestructor(allocationTableList->allocationTableList);
    free(allocationTableList);
}

void AllocationTableListDestructorWithFreeAllNodeDataInList(
        AllocationTableList *allocationTableList) {
    if (allocationTableList == NULL) { return; }

    ListDestructorAndFreeAllNodeData(allocationTableList->allocationTableList);



    free(allocationTableList);
}

/**
 * Singleton implementation.
 *
 * // TODO:
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

static BOOLEAN predicateFindAllocationTableByClassName(
        const Node *      nodeThatPointsToAllocationTable,
        const char *const allocationTableClassName) {
    return strcmp(((AllocationTable *) (nodeThatPointsToAllocationTable->data))
                          ->className,
                  allocationTableClassName) == 0;
}

AllocationTable *
findAllocationTableByClassName(const char *const allocationTableClassName) {
    Node *foundNode = findNodeByPredicateOfConstString(
            GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList,
            predicateFindAllocationTableByClassName, allocationTableClassName);

    if (foundNode != NULL) {
        return ((AllocationTable *) (foundNode->data));
    } else {
        return NULL;
    }
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
    AllocationTableListDestructorWithFreeAllNodeDataInList(
            GLOBAL_ALLOCATION_TABLE_LIST);
}

#endif //ALLOCATIONTABLELIST_H
