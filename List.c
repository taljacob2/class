#include "List.h"

void add(List *list, Node *node) {
    if (list == NULL) { return; }

    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    list->size++;
}

void *delete (List *list, Node *node) {
    if (list == NULL) { return NULL; }

    Node *iterationNodePrev = NULL;
    void *deletedNodeData   = NULL;
    for (Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode          = iterationNode->next,
              iterationNodePrev = iterationNode) {
        if (iterationNode != node) { continue; }

        if (iterationNodePrev != NULL) {

            // `iterationNode` is a "middle-node" or `list->tail`.
            iterationNodePrev->next = iterationNode->next;
        } else {

            // `iterationNode` is `list->head`.
            list->head = iterationNode->next;
        }
        if (iterationNode->next == NULL) {

            // `iterationNode` is `list->tail`.
            list->tail = iterationNodePrev;
        }
        deletedNodeData =
                iterationNode->thisObjectBase->destructable->destructor(
                        iterationNode);
        list->size--;
        break;
    }

    return deletedNodeData;
}

void *deleteNodeThatHasTheGivenData(List *list, void *dataOfTheNodeToDelete) {
    if (list == NULL) { return NULL; }

    Node *iterationNodePrev = NULL;
    void *deletedNodeData   = NULL;
    for (Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode          = iterationNode->next,
              iterationNodePrev = iterationNode) {
        if (iterationNode->data != dataOfTheNodeToDelete) { continue; }

        if (iterationNodePrev != NULL) {

            // `iterationNode` is a "middle-node" or `list->tail`.
            iterationNodePrev->next = iterationNode->next;
        } else {

            // `iterationNode` is `list->head`.
            list->head = iterationNode->next;
        }
        if (iterationNode->next == NULL) {

            // `iterationNode` is `list->tail`.
            list->tail = iterationNodePrev;
        }

        deletedNodeData =
                iterationNode->thisObjectBase->destructable->destructor(
                        iterationNode);
        list->size--;
        break;
    }

    return deletedNodeData;
}

Node *findNodeByPredicateOfConstString(List *list,
                                       BOOLEAN (*predicate)(const Node *,
                                                            const char *const),
                                       const char *allocationTableClassName) {
    if (list == NULL) { return NULL; }

    for (Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode       = iterationNode->next) {
        if (predicate(iterationNode, allocationTableClassName)) {
            return iterationNode;
        }
    }

    return NULL;
}

void *ListDestructor(List *list) {
    if (list == NULL) { return NULL; }

    Node *iterationNodePrev = NULL;
    for (Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode          = iterationNode->next,
              iterationNodePrev = iterationNode) {
        iterationNodePrev->thisObjectBase->destructable->destructor(
                iterationNodePrev);
    }

    // `iterationNodePrev` is `list->tail`.
    if (iterationNodePrev != NULL) {
        iterationNodePrev->thisObjectBase->destructable->destructor(
                iterationNodePrev);
    }

    free(list->thisObjectBase);

    free(list);

    return NULL;
}

// TODO: REMOVE
//void *ListDestructorAndFreeAllNodeData(List *list) {
//    if (list == NULL) { return NULL; }
//
//    Node *iterationNodePrev = NULL;
//    for (Node *iterationNode    = list->head; iterationNode != NULL;
//         iterationNode          = iterationNode->next,
//              iterationNodePrev = iterationNode) {
//        free(iterationNodePrev->destructable->destructor(iterationNodePrev));
//    }
//
//    // `iterationNodePrev` is `list->tail`.
//    free(iterationNodePrev->destructable->destructor(iterationNodePrev));
//
//    free(list);
//
//    return NULL;
//}

void constructor_List_fields(List *list) {
    list->thisObjectBase = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&ListConstructor)};
    list->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&ListDestructor)};
    list->thisObjectBase->destructable = &destructable;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

List *ListConstructor() {
    List *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_List_fields(obj);

    return obj;
}
