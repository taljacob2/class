#include "Legacy_Node.r"

/**
 * @brief `Destructs`s the given legacy_node, and returns its `legacy_node->data`.
 *
 * @param node
 * @return
 */
void *Legacy_NodeDestructor(Legacy_Node *node) {
    if (node == NULL) { return NULL; }

    void *nodeData = node->data;

    free(node->object);

    free(node);

    return nodeData;
}

void constructor_Legacy_Node_fields(Legacy_Node *node) {
    node->object = ObjectConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&Legacy_NodeConstructor)};
    node->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&Legacy_NodeDestructor)};
    node->object->destructable = &destructable;

    node->data     = NULL;
    node->dataSize = 0;
    node->next     = NULL;
}

Legacy_Node *Legacy_NodeConstructor() {
    Legacy_Node *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    constructor_Legacy_Node_fields(instance);

    return instance;
}

Legacy_Node *Legacy_NodeConstructorWithDataAndDataSize(void * data,
                                                       size_t dataSize) {
    Legacy_Node *obj = Legacy_NodeConstructor();

    obj->data     = data;
    obj->dataSize = dataSize;

    return obj;
}
