#ifndef CLASS_LEGACY_NODE_R
#define CLASS_LEGACY_NODE_R

#include "Destructable.r"
#include "Legacy_ObjectComponent.r"
#include <stdlib.h>

/* Forward declaration of incomplete type */
typedef struct legacy_node Legacy_Node;

struct legacy_node {

    /** `Legacy_Node` implements `Legacy_ObjectComponent`. */
    Legacy_ObjectComponent *legacyObjectComponent;

    void *       data;
    Legacy_Node *next;
    Legacy_Node *prev;

    void *(*setNodeData)(Legacy_Node *node, void *data);
};

Legacy_Node *Legacy_NodeConstructor();

Legacy_Node *Legacy_NodeConstructorWithData(void *data);

#endif /* CLASS_LEGACY_NODE_R */
