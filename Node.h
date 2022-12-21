#ifndef CLASS_NODE_H
#define CLASS_NODE_H

#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct node Node;

struct node {
    void *data;
    size_t dataSize;
    Node *next;
};

static void constructor_Node_fields(Node *node) {
    node->data = NULL;
    node->dataSize = 0;
    node->next = NULL;
}

Node *NodeConstructor() {
    Node *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Node_fields(obj);

    return obj;
}

Node *NodeConstructorWithDataAndDataSize(void *data, size_t dataSize) {
    Node *obj = NodeConstructor();

    obj->data = data;
    obj->dataSize = dataSize;

    return obj;
}

/**
 * @brief `free`s the given node, and returns its `node->data`.
 *
 * @param node
 * @return
 */
void *NodeDestructor(Node *node) {
    void * nodeData = node->data;
    free(node);
    return nodeData;
}

#endif //CLASS_NODE_H
