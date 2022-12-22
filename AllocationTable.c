#include "AllocationTable.h"

/// @attention This is **not** generic.
void *ListDestructorWhileFreeAllNodeData(Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode          = iterationNode->next,
              iterationNodePrev = iterationNode) {
        free(iterationNodePrev->thisObjectBase->destructable->destructor(
                iterationNodePrev));
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        free(iterationNodePrev->thisObjectBase->destructable->destructor(
                iterationNodePrev));
    }

    free(list);

    return NULL;
}

/// @attention This is **not** generic.
void *AllocationTableDestructor(AllocationTable *allocationTable) {
    if (allocationTable == NULL) { return NULL; }

    ListDestructorWhileFreeAllNodeData(allocationTable->allocationAddressList);

    free(allocationTable->thisObjectBase);

    free(allocationTable);

    return NULL;
}

void constructor_AllocationTable_fields(AllocationTable *allocationTable) {
    allocationTable->thisObjectBase = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor =
                    (void *(*const)(void) )(&AllocationTableConstructor)};
    allocationTable->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AllocationTableDestructor)};
    allocationTable->thisObjectBase->destructable = &destructable;

    allocationTable->className             = "";
    allocationTable->allocationAddressList = Legacy_ListConstructor();
}

AllocationTable *AllocationTableConstructor() {
    AllocationTable *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_AllocationTable_fields(obj);

    return obj;
}

AllocationTable *
AllocationTableConstructorWithClassName(const char *className) {
    AllocationTable *obj = AllocationTableConstructor();

    obj->className = className;

    return obj;
}
