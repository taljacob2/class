#ifndef ALLOCATIONTABLELIST_H
#define ALLOCATIONTABLELIST_H

#include "Legacy_AllocationTable.r"
#include "Legacy_List.r"

#include <stdio.h>
#include <string.h>

#define __GENERIC_ALLOCATION_TABLE_NAME__ "__GENERIC_ALLOCATION_TABLE_NAME__"

// Forward declaration of incomplete type
typedef struct legacy_allocationTableList Legacy_AllocationTableList;

struct legacy_allocationTableList {

    /// `Legacy_AllocationTableList` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *object;

    Legacy_List *allocationTableList;

    Legacy_AllocationTable *(*findLegacy_AllocationTableByClassName)(
            const char *allocationTableClassName);
    BOOLEAN(*predicateFindLegacy_AllocationTableByClassName)
    (const Legacy_Node *nodeThatPointsToAllocationTable,
     const char *const  allocationTableClassName);
};

/**
 * Singleton implementation.
 *
 * @attention Remember to `free` this singleton on the program's exit.
 *
 * @return
 * @see https://stackoverflow.com/a/803699/14427765
 */
Legacy_AllocationTableList *getLegacy_AllocationTableList();

Legacy_AllocationTable *getGenericLegacy_AllocationTable();

Legacy_AllocationTableList *Legacy_AllocationTableListConstructor();

#endif //ALLOCATIONTABLELIST_H
