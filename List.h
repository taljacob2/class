#ifndef CLASS_LIST_H
#define CLASS_LIST_H

#include "Node.h"
#include <limits.h>
#include <stdlib.h>


// Forward declaration of incomplete type
typedef struct list List;

struct list {
    Node *head;
    Node *tail;
};

size_t getSize(List *list) {
    return (list->head == NULL) && (list->tail == NULL)
                   ? 0
                   : ((list->tail - list->head) / sizeof(Node)) + 1;
}

static void constructor_List_fields(List *list) {
    list->head = NULL;
    list->tail = NULL;
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
