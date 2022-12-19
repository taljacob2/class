#ifndef ALLOCATIONTABLE_H
#define ALLOCATIONTABLE_H

#include <stdlib.h>
#include "List.h"

// Forward declaration of incomplete type
typedef struct allocationTable AllocationTable;

struct allocationTable {
    char * className;
    const List * allocationAddressList;
};

static void constructor_AllocationTable_fields(AllocationTable *allocationTable) {
    allocationTable->className         = "";
    allocationTable->allocationAddressList = ListConstructor();
}

AllocationTable *AllocationTableConstructor() {
    AllocationTable *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_AllocationTable_fields(obj);

    return obj;
}

#endif //ALLOCATIONTABLE_H
