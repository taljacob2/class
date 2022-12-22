#ifndef CLASS_NODE_H
#define CLASS_NODE_H

#include "Constructable.h"
#include "Destructable.h"
#include "ObjectBase.h"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct node Node;

struct node {

    /// `Node` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    void * data;
    size_t dataSize;
    Node * next;
};

Node *NodeConstructor();

Node *NodeConstructorWithDataAndDataSize(void *data, size_t dataSize);

#endif //CLASS_NODE_H
