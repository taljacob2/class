#ifndef ALLOCATIONTABLE_H
#define ALLOCATIONTABLE_H

#include "List.h"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct allocationTable AllocationTable;

struct allocationTable {

    /// `AllocationTable` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    const char *className;

    List *allocationAddressList;
};

AllocationTable *AllocationTableConstructor();

AllocationTable *AllocationTableConstructorWithClassName(const char *className);

#endif //ALLOCATIONTABLE_H
