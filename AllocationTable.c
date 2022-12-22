#include "AllocationTable.h"

void AllocationTableDestructor(AllocationTable *allocationTable) {
    if (allocationTable == NULL) { return; }

    allocationTable->allocationAddressList->destructable->destructor(
            allocationTable->allocationAddressList);

    free(allocationTable);
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
    static Constructable const constructable = {
            .constructor =
                    (void *(*const)(void) )(&AllocationTableConstructor)};
    allocationTable->constructable = &constructable;

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&AllocationTableDestructor)};
    allocationTable->destructable = &destructable;

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
