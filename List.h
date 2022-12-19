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
    for (Node *iterationNode = list->head; iterationNode != NULL;
         iterationNode       = iterationNode->next) {
        NodeDestructor(iterationNodePrev);
        iterationNodePrev = iterationNode;
    }
    NodeDestructor(iterationNodePrev); // `iterationNodePrev` is `list->tail`.

    free(list);
}

#endif //CLASS_LIST_H
