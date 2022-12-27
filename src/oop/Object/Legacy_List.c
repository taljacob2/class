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
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
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
            deletedNodeData = iterationNode->legacyObjectComponent->destructable->destructor(
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
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
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

            deletedNodeData = iterationNode->legacyObjectComponent->destructable->destructor(
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
        const char *stringToSearch) {
    if (list == NULL) { return NULL; }

    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (predicate(iterationNode, stringToSearch)) { return iterationNode; }
    }

    return NULL;
}

void addAsUnique(Legacy_List *list, Legacy_Node *node,
                 BOOLEAN (*predicate)(const Legacy_Node *, const char *const),
                 const char *stringToSearch) {
    if (list == NULL) { return; }

    if (findNodeByPredicateOfConstString(list, predicate, stringToSearch) ==
        NULL) {
        add(list, node);
    }
}

void *Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData(
        Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev != NULL) {
            Legacy_Object *objectContainer =
                    iterationNodePrev->legacyObjectComponent->destructable->destructor(
                            iterationNodePrev);
            objectContainer->legacyObjectComponent
                    ->deleteFromAllocationTableInvocationStatus =
                    WAS_INVOKED_ONCE;
            objectContainer->legacyObjectComponent->destructable->destructor(objectContainer);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        Legacy_Object *objectContainer =
                iterationNodePrev->legacyObjectComponent->destructable->destructor(
                        iterationNodePrev);
        objectContainer->legacyObjectComponent
                ->deleteFromAllocationTableInvocationStatus =
                WAS_INVOKED_ONCE;
        objectContainer->legacyObjectComponent->destructable->destructor(objectContainer);
    }

    free(list->legacyObjectComponent);

    free(list);

    return NULL;
}

void *Legacy_ListDestructor(Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev != NULL) {
            iterationNodePrev->legacyObjectComponent->destructable->destructor(
                    iterationNodePrev);
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        iterationNodePrev->legacyObjectComponent->destructable->destructor(iterationNodePrev);
    }

    free(list->legacyObjectComponent);

    free(list);

    return NULL;
}

void constructor_Legacy_List_fields(Legacy_List *list) {
    list->legacyObjectComponent = Legacy_ObjectComponentConstructorClassName("Legacy_List");

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&Legacy_ListConstructor)};
    list->legacyObjectComponent->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&Legacy_ListDestructor)};
    list->legacyObjectComponent->destructable = &destructable;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    list->add                              = &add;
    list->delete                           = &delete;
    list->deleteNodeThatHasTheGivenData    = &deleteNodeThatHasTheGivenData;
    list->findNodeByPredicateOfConstString = &findNodeByPredicateOfConstString;
    list->addAsUnique                      = &addAsUnique;
    list->Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData =
            &Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData;
}

Legacy_List *Legacy_ListConstructor() {
    Legacy_List *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_Legacy_List_fields(instance);

    return instance;
}
