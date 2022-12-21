#ifndef CLASS_LIST_H
#define CLASS_LIST_H

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
    list->tail->next = node;
    list->tail       = node;
    list->size++;
}

void *delete (List *list, Node *node) {
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
