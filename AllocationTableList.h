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

    Constructable const *constructable;

    Destructable const *destructable;
};

AllocationTableList *GLOBAL_ALLOCATION_TABLE_LIST = NULL;

AllocationTableList *AllocationTableListConstructor();

AllocationTable *
findAllocationTableByClassName(const char *allocationTableClassName);

#endif //ALLOCATIONTABLELIST_H
