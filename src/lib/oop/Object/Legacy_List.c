#include "Legacy_List.r"

void add(Legacy_List *list, Legacy_Node *node) {
    if (list == NULL) { return; }

    if (list->tail != NULL) {
        list->tail->next = node;
        node->prev       = list->tail;
    } else {
        list->head = node;
    }
    list->tail = node;
    list->size++;
}

/**
 * "private" function for internal logic of `delete` and
 * `deleteNodeThatHasTheGivenData`.
 */
void *deleteNodeAndReturnNodeDataPRIVATE(Legacy_List *list,
                                         Legacy_Node *iterationNodePrev,
                                         Legacy_Node *iterationNode) {
    if (iterationNodePrev) {

        // `iterationNode` is a "middle-legacy_node" or `legacy_list->tail`.
        iterationNodePrev->next = iterationNode->next;
    } else {

        // `iterationNode` is `legacy_list->head`.
        list->head = iterationNode->next;
    }
    if (iterationNode->next) {
        iterationNode->next->prev = iterationNodePrev;
    } else {

        // `iterationNode` is `legacy_list->tail`.
        list->tail = iterationNodePrev;
    }
    list->size--;

    return iterationNode->legacyObjectComponent->destructable->destructor(
            iterationNode);
}

void *delete (Legacy_List *list, Legacy_Node *node) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    void *       deletedNodeData   = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNode == node) {
            deletedNodeData = deleteNodeAndReturnNodeDataPRIVATE(
                    list, iterationNodePrev, iterationNode);
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
            deletedNodeData = deleteNodeAndReturnNodeDataPRIVATE(
                    list, iterationNodePrev, iterationNode);
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

void *setByStringToSearch(Legacy_List *list, void *dataToSet,
                          BOOLEAN (*predicate)(const Legacy_Node *,
                                               const char *const),
                          const char *stringToSearch) {
    if (list == NULL) { return NULL; }

    Legacy_Node *foundNode =
            findNodeByPredicateOfConstString(list, predicate, stringToSearch);
    if (foundNode == NULL) {
        // TODO:
        // throw message with status: ENTRY_NOT_FOUND.
        return NULL;
    }

    // set logic.
    return foundNode->setNodeData(foundNode, dataToSet);
}

/// @deprecated Unused. Keep this "private".
void *Legacy_ListDestructorWithInvokingDestructorOfEachNodeDataInStraightOrder(
        Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev != NULL) {
            Legacy_Object *legacyObject =
                    iterationNodePrev->legacyObjectComponent->destructable
                            ->destructor(iterationNodePrev);
            if (legacyObject->legacyObjectComponent
                        ->destructorInvocationStatus == WAS_NOT_INVOKED) {
                legacyObject->legacyObjectComponent
                        ->destructorInvocationStatus = WAS_INVOKED_ONCE;
                legacyObject->legacyObjectComponent->destructable->destructor(
                        legacyObject);
            }
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev != NULL) {
        Legacy_Object *legacyObject =
                iterationNodePrev->legacyObjectComponent->destructable
                        ->destructor(iterationNodePrev);
        if (legacyObject->legacyObjectComponent->destructorInvocationStatus ==
            WAS_NOT_INVOKED) {
            legacyObject->legacyObjectComponent->destructorInvocationStatus =
                    WAS_INVOKED_ONCE;
            legacyObject->legacyObjectComponent->destructable->destructor(
                    legacyObject);
        }
    }

    free(list->legacyObjectComponent);

    free(list);

    return NULL;
}

void *Legacy_ListDestructorWithInvokingDestructorOfEachNodeDataInReversedOrder(
        Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->tail; iterationNode != NULL;
         iterationNode              = iterationNode->prev) {
        if (iterationNodePrev != NULL) {
            Legacy_Object *legacyObject =
                    iterationNodePrev->legacyObjectComponent->destructable
                            ->destructor(iterationNodePrev);
            if (legacyObject->legacyObjectComponent
                        ->destructorInvocationStatus == WAS_NOT_INVOKED) {
                legacyObject->legacyObjectComponent
                        ->destructorInvocationStatus = WAS_INVOKED_ONCE;
                legacyObject->legacyObjectComponent->destructable->destructor(
                        legacyObject);
            }
        }

        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->head`.
    if (iterationNodePrev != NULL) {
        Legacy_Object *legacyObject =
                iterationNodePrev->legacyObjectComponent->destructable
                        ->destructor(iterationNodePrev);
        if (legacyObject->legacyObjectComponent->destructorInvocationStatus ==
            WAS_NOT_INVOKED) {
            legacyObject->legacyObjectComponent->destructorInvocationStatus =
                    WAS_INVOKED_ONCE;
            legacyObject->legacyObjectComponent->destructable->destructor(
                    legacyObject);
        }
    }

    free(list->legacyObjectComponent);

    free(list);

    return NULL;
}

void *Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData(
        Legacy_List *list) {
    return Legacy_ListDestructorWithInvokingDestructorOfEachNodeDataInReversedOrder(
            list);
}

void *Legacy_ListDestructor(Legacy_List *list) {
    if (list == NULL) { return NULL; }

    Legacy_Node *iterationNodePrev = NULL;
    for (Legacy_Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode              = iterationNode->next) {
        if (iterationNodePrev) {
            iterationNodePrev->legacyObjectComponent->destructable->destructor(
                    iterationNodePrev);
        }
        iterationNodePrev = iterationNode;
    }

    // `iterationNodePrev` is `legacy_list->tail`.
    if (iterationNodePrev) {
        iterationNodePrev->legacyObjectComponent->destructable->destructor(
                iterationNodePrev);
    }

    free(list->legacyObjectComponent);

    free(list);

    return NULL;
}

void constructor_Legacy_List_fields(Legacy_List *list) {
    list->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("Legacy_List");

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
    list->setByStringToSearch = &setByStringToSearch;
}

Legacy_List *Legacy_ListConstructor() {
    Legacy_List *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_Legacy_List_fields(instance);

    return instance;
}
