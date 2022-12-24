#ifndef CLASS_LEGACY_NODE_H
#define CLASS_LEGACY_NODE_H

#include "Constructable.h"
#include "Destructable.h"
#include "ObjectBase.h"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_node Legacy_Node;

struct legacy_node {

    /// `Legacy_Node` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    void *       data;
    size_t       dataSize;
    Legacy_Node *next;
};

Legacy_Node *Legacy_NodeConstructor();

Legacy_Node *Legacy_NodeConstructorWithDataAndDataSize(void * data,
                                                       size_t dataSize);

#endif //CLASS_LEGACY_NODE_H
