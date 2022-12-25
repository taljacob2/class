#ifndef ALLOCATIONTABLE_H
#define ALLOCATIONTABLE_H

#include "Legacy_List.r"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_allocationTable Legacy_AllocationTable;

struct legacy_allocationTable {

    /// `Legacy_AllocationTable` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    const char *className;

    Legacy_List *allocationAddressList;
};

Legacy_AllocationTable *Legacy_AllocationTableConstructor();

Legacy_AllocationTable *
Legacy_AllocationTableConstructorWithClassName(const char *className);

#endif //ALLOCATIONTABLE_H
