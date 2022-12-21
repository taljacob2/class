#ifndef CLASS_LIST_H
#define CLASS_LIST_H

#include "Bool.h"
#include "Node.h"
#include <limits.h>
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct list List;

struct list {
    Node * head;
    Node * tail;
    size_t size;
};

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
        deletedNodeData = NodeDestructor(iterationNode);
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
        deletedNodeData = NodeDestructor(iterationNode);
        list->size--;
        break;
    }

    return deletedNodeData;
}

Node *findNodeByPredicateOfConstString(
        List *list, BOOLEAN (*predicate)(const Node *, const char *const),
        const char *const allocationTableClassName) {
    if (list == NULL) { return NULL; }

    for (Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode       = iterationNode->next) {
        if (predicate(iterationNode, allocationTableClassName)) {
            return iterationNode;
        }
    }

    return NULL;
}

static void constructor_List_fields(List *list) {
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

void ListDestructor(List *list) {
    if (list == NULL) { return; }

    Node *iterationNodePrev = NULL;
    for (Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode          = iterationNode->next,
              iterationNodePrev = iterationNode) {
        NodeDestructor(iterationNodePrev);
    }

    // `iterationNodePrev` is `list->tail`.
    NodeDestructor(iterationNodePrev);

    free(list);
}

void ListDestructorAndFreeAllNodeData(List *list) {
    if (list == NULL) { return; }

    Node *iterationNodePrev = NULL;
    for (Node *iterationNode    = list->head; iterationNode != NULL;
         iterationNode          = iterationNode->next,
              iterationNodePrev = iterationNode) {
        free(NodeDestructor(iterationNodePrev));
    }

    // `iterationNodePrev` is `list->tail`.
    free(NodeDestructor(iterationNodePrev));

    free(list);
}

#endif //CLASS_LIST_H
