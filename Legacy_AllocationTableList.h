#ifndef ALLOCATIONTABLELIST_H
#define ALLOCATIONTABLELIST_H

#include "Legacy_AllocationTable.h"
#include "Legacy_List.h"

#include <stdio.h>
#include <string.h>

// Forward declaration of incomplete type
typedef struct legacy_allocationTableList Legacy_AllocationTableList;

struct legacy_allocationTableList {

    /// `Legacy_AllocationTableList` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    Legacy_List *allocationTableList;

    Legacy_AllocationTable *(*findLegacy_AllocationTableByClassName)(
            const char *allocationTableClassName);
};

static Legacy_AllocationTableList *GLOBAL_ALLOCATION_TABLE_LIST = NULL;

Legacy_AllocationTableList *Legacy_AllocationTableListConstructor();

#endif //ALLOCATIONTABLELIST_H
