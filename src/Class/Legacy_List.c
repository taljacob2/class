#include "Legacy_List.r"

void add(Legacy_List *list, Legacy_Node *node) {
    if (list == NULL) { return; }

    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    list->size++;
}

void *delete (Legacy_List *list, Legacy_Node *node) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    void *       deletedNodeData   = NULL;
    for (Legacy_Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode                 = iterationNode->next) {
        if (iterationNode == node) {
            if (iterationNodePrev != NULL) {

                // `iterationNode` is a "middle-legacy_node" or `legacy_list->tail`.
                iterationNodePrev->next = iterationNode->next;
            } else {

                // `iterationNode` is `legacy_list->head`.
                list->head = iterationNode->next;
            }
            if (iterationNode->next == NULL) {

                // `iterationNode` is `legacy_list->tail`.
                list->tail = iterationNodePrev;
            }
            deletedNodeData =
                    iterationNode->thisObjectBase->destructable->destructor(
                            iterationNode);
            list->size--;
            break;
        }

        iterationNodePrev = iterationNode;
    }

    return deletedNodeData;
}

void *deleteNodeThatHasTheGivenData(Legacy_List *list,
                                    void *       dataOfTheNodeToDelete) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    void *       deletedNodeData   = NULL;
    for (Legacy_Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode                 = iterationNode->next) {
        if (iterationNode->data == dataOfTheNodeToDelete) {
            if (iterationNodePrev != NULL) {

                // `iterationNode` is a "middle-legacy_node" or `legacy_list->tail`.
                iterationNodePrev->next = iterationNode->next;
            } else {

                // `iterationNode` is `legacy_list->head`.
                list->head = iterationNode->next;
            }
            if (iterationNode->next == NULL) {

                // `iterationNode` is `legacy_list->tail`.
                list->tail = iterationNodePrev;
            }

            deletedNodeData =
                    iterationNode->thisObjectBase->destructable->destructor(
                            iterationNode);
            list->size--;
            break;
        }

        iterationNodePrev = iterationNode;
    }

    return deletedNodeData;
}

Legacy_Node *findNodeByPredicateOfConstString(
        Legacy_List *list,
        BOOLEAN (*predicate)(const Legacy_Node *, const char *const),
        const char *allocationTableClassName) {
    if (list == NULL) { return NULL; }

    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (predicate(iterationNode, allocationTableClassName)) {
            return iterationNode;
        }
    }

    return NULL;
}

void *Legacy_ListDestructor(Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode                 = iterationNode->next) {
        if (iterationNodePrev!= NULL) {
            iterationNodePrev->thisObjectBase->destructable->destructor(
                    iterationNodePrev);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        iterationNodePrev->thisObjectBase->destructable->destructor(
                iterationNodePrev);
    }

    free(list->thisObjectBase);

    free(list);

    return NULL;
}

void constructor_Legacy_List_fields(Legacy_List *list) {
    list->thisObjectBase = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&Legacy_ListConstructor)};
    list->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&Legacy_ListDestructor)};
    list->thisObjectBase->destructable = &destructable;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    list->add                              = &add;
    list->delete                           = &delete;
    list->deleteNodeThatHasTheGivenData    = &deleteNodeThatHasTheGivenData;
    list->findNodeByPredicateOfConstString = &findNodeByPredicateOfConstString;
}

Legacy_List *Legacy_ListConstructor() {
    Legacy_List *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Legacy_List_fields(obj);

    return obj;
}
