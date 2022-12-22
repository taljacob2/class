#ifndef ALLOCATIONTABLE_H
#define ALLOCATIONTABLE_H

#include "List.h"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct allocationTable AllocationTable;

struct allocationTable {
    char *className;
    List *allocationAddressList;

    Constructable const *constructable;

    Destructable const *destructable;
};

AllocationTable *AllocationTableConstructor();

AllocationTable *AllocationTableConstructorWithClassName(const char *className);

#endif //ALLOCATIONTABLE_H
