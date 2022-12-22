#include "AllocationTable.h"

void *ListDestructorWhileFreeAllNodeData(List *list) {
    if (list == NULL) { return NULL; }

    Node *iterationNodePrev = NULL;
    for (Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode          = iterationNode->next,
              iterationNodePrev = iterationNode) {
        free(iterationNodePrev->thisObjectBase->destructable->destructor(
                iterationNodePrev));
    }

    // `iterationNodePrev` is `list->tail`.
    free(iterationNodePrev->thisObjectBase->destructable->destructor(
            iterationNodePrev));

    free(list);

    return NULL;
}

void *AllocationTableDestructor(AllocationTable *allocationTable) {
    if (allocationTable == NULL) { return NULL; }

    ListDestructorWhileFreeAllNodeData(allocationTable->allocationAddressList);

    free(allocationTable->thisObjectBase);

    free(allocationTable);

    return NULL;
}

// TODO REMOVE:
//void AllocationTableDestructorWithFreeAllNodeDataInList(
//        AllocationTable *allocationTable) {
//    if (allocationTable == NULL) { return; }
//
//    ListDestructorAndFreeAllNodeData(allocationTable->allocationAddressList);
//    free(allocationTable);
//}

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
AllocationTableConstructorWithClassName(const char *className) {
    AllocationTable *obj = AllocationTableConstructor();

    obj->className = className;

    return obj;
}
