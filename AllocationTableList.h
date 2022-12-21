#ifndef ALLOCATIONTABLELIST_H
#define ALLOCATIONTABLELIST_H

#include "List.h"

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

static void runAtExit() {
    AllocationTableListDestructorWithFreeAllNodeDataInList(
            GLOBAL_ALLOCATION_TABLE_LIST);
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
        instance = AllocationTableListConstructor();
        atexit(runAtExit);
    }
    // Do unlock.

    return instance;
}


#endif //ALLOCATIONTABLELIST_H
