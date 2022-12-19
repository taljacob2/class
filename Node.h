#ifndef CLASS_NODE_H
#define CLASS_NODE_H

#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct node Node;

struct node {
    void *data;
    Node *next;
};

static void constructor_Node_fields(Node *node) {
    node->data = NULL;
    node->next = NULL;
}

Node *NodeConstructor() {
    Node *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Node_fields(obj);

    return obj;
}

void NodeDestructor(Node *node) { free(node); }

#endif //CLASS_NODE_H
