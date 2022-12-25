#include "Legacy_AllocationTable.r"
#include "AutoDestructableV2.r"

/// @attention This is **not** generic.
void *Legacy_ListDestructorWhileFreeAllNodeDataV2(Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev != NULL) {

            // TODO: The problem is it must be ObjectContainer and not Object so you could use the polymorphism of the destructor!!!
            Object *object =
                    iterationNodePrev->object->destructable->destructor(
                            iterationNodePrev);
            object->deleteFromAllocationTableInvocationStatus =
                    WAS_INVOKED_ONCE;
            object->destructable->destructor(object);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {

        // TODO: The problem is it must be ObjectContainer and not Object so you could use the polymorphism of the destructor!!!
        Object *object = iterationNodePrev->object->destructable->destructor(
                iterationNodePrev);
        object->deleteFromAllocationTableInvocationStatus = WAS_INVOKED_ONCE;
        object->destructable->destructor(object);
    }

    free(list->object);

    free(list);

    return NULL;
}

/// @attention This is **not** generic.
void *Legacy_ListDestructorWhileFreeAllNodeData(Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev != NULL) {
            ObjectContainer *objectContainer =
                    iterationNodePrev->object->destructable->destructor(
                            iterationNodePrev);
            objectContainer->object->deleteFromAllocationTableInvocationStatus =
                    WAS_INVOKED_ONCE;
            objectContainer->object->destructable->destructor(objectContainer);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        ObjectContainer *objectContainer =
                iterationNodePrev->object->destructable->destructor(
                        iterationNodePrev);
        objectContainer->object->deleteFromAllocationTableInvocationStatus =
                WAS_INVOKED_ONCE;
        objectContainer->object->destructable->destructor(objectContainer);
    }

    free(list->object);

    free(list);

    return NULL;
}

/// @attention This is **not** generic.
void *
Legacy_AllocationTableDestructor(Legacy_AllocationTable *allocationTable) {
    if (allocationTable == NULL) { return NULL; }

    Legacy_ListDestructorWhileFreeAllNodeDataV2(
            allocationTable->allocationAddressList);

    free(allocationTable->object);

    free(allocationTable);

    return NULL;
}

void constructor_Legacy_AllocationTable_fields(
        Legacy_AllocationTable *allocationTable) {
    allocationTable->object = ObjectConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(
                    &Legacy_AllocationTableConstructor)};
    allocationTable->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(
                    &Legacy_AllocationTableDestructor)};
    allocationTable->object->destructable = &destructable;

    allocationTable->className             = "";
    allocationTable->allocationAddressList = Legacy_ListConstructor();
}

Legacy_AllocationTable *Legacy_AllocationTableConstructor() {
    Legacy_AllocationTable *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_Legacy_AllocationTable_fields(instance);

    return instance;
}

Legacy_AllocationTable *
Legacy_AllocationTableConstructorWithClassName(const char *className) {
    Legacy_AllocationTable *obj = Legacy_AllocationTableConstructor();

    obj->className = className;

    return obj;
}
