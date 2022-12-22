#ifndef CLASS_NODE_H
#define CLASS_NODE_H

#include "Constructable.h"
#include "Destructable.h"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct node Node;

struct node {
    void * data;
    size_t dataSize;
    Node * next;

    Constructable const *constructable;

    Destructable const *destructable;
};

Node *NodeConstructor();

Node *NodeConstructorWithDataAndDataSize(void *data, size_t dataSize);

#endif //CLASS_NODE_H
