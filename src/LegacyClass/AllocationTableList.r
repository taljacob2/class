#ifndef ALLOCATIONTABLELIST_H
#define ALLOCATIONTABLELIST_H

#include "Legacy_AllocationTable.r"
#include "Legacy_List.r"

#include <stdio.h>
#include <string.h>

// Forward declaration of incomplete type
typedef struct allocationTableList AllocationTableList;

struct allocationTableList {

    /// `AllocationTableList` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    Legacy_List *allocationTableList;
};

static AllocationTableList *GLOBAL_ALLOCATION_TABLE_LIST = NULL;

AllocationTableList *AllocationTableListConstructor();

Legacy_AllocationTable *
findAllocationTableByClassName(const char *allocationTableClassName);

#endif //ALLOCATIONTABLELIST_H
