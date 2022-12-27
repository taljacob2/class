#ifndef CLASS_LEGACY_NODE_R
#define CLASS_LEGACY_NODE_R

#include "Constructable.r"
#include "Destructable.r"
#include "Legacy_Object.r"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_node Legacy_Node;

struct legacy_node {

    /// `Legacy_Node` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *legacyObjectComponent;

    void *       data;
    Legacy_Node *next;
};

Legacy_Node *Legacy_NodeConstructor();

Legacy_Node *Legacy_NodeConstructorWithData(void *data);

#endif //CLASS_LEGACY_NODE_R
