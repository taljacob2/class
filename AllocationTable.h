#ifndef ALLOCATIONTABLE_H
#define ALLOCATIONTABLE_H

#include "List.h"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct allocationTable AllocationTable;

struct allocationTable {
    char *className;
    List *allocationAddressList;
};

static void
constructor_AllocationTable_fields(AllocationTable *allocationTable) {
    allocationTable->className             = "";
    allocationTable->allocationAddressList = ListConstructor();
}

AllocationTable *AllocationTableConstructor() {
    AllocationTable *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_AllocationTable_fields(obj);

    return obj;
}

AllocationTable *
AllocationTableConstructorWithClassName(char *const className) {
    AllocationTable *obj = AllocationTableConstructor();

    obj->className = className;

    return obj;
}

void AllocationTableDestructor(AllocationTable *allocationTable) {
    ListDestructor(allocationTable->allocationAddressList);
    free(allocationTable);
}

#endif //ALLOCATIONTABLE_H
