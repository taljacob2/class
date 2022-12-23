#include "Legacy_AllocationTable.h"
#include "Class1.h"

/// @attention This is **not** generic.
void *Legacy_ListDestructorWhileFreeAllNodeData(Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev != NULL) {
            Class1 *class1 =
                    iterationNodePrev->thisObjectBase->destructable->destructor(
                            iterationNodePrev);
            free(class1->thisObjectBase);
            free(class1);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        Class1 *class1 =
                iterationNodePrev->thisObjectBase->destructable->destructor(
                        iterationNodePrev);
        free(class1->thisObjectBase);
        free(class1);
    }

    free(list->thisObjectBase);

    free(list);

    return NULL;
}

/// @attention This is **not** generic.
void *
Legacy_AllocationTableDestructor(Legacy_AllocationTable *allocationTable) {
    if (allocationTable == NULL) { return NULL; }

    Legacy_ListDestructorWhileFreeAllNodeData(
            allocationTable->allocationAddressList);

    free(allocationTable->thisObjectBase);

    free(allocationTable);

    return NULL;
}

void constructor_Legacy_AllocationTable_fields(
        Legacy_AllocationTable *allocationTable) {
    allocationTable->thisObjectBase = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(
                    &Legacy_AllocationTableConstructor)};
    allocationTable->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(
                    &Legacy_AllocationTableDestructor)};
    allocationTable->thisObjectBase->destructable = &destructable;

    allocationTable->className             = "";
    allocationTable->allocationAddressList = Legacy_ListConstructor();
}

Legacy_AllocationTable *Legacy_AllocationTableConstructor() {
    Legacy_AllocationTable *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Legacy_AllocationTable_fields(obj);

    return obj;
}

Legacy_AllocationTable *
Legacy_AllocationTableConstructorWithClassName(const char *className) {
    Legacy_AllocationTable *obj = Legacy_AllocationTableConstructor();

    obj->className = className;

    return obj;
}
