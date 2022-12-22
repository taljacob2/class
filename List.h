#ifndef CLASS_LIST_H
#define CLASS_LIST_H

#include "Bool.h"
#include "Legacy_Node.h"
#include <limits.h>
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct list List;

struct list {

    /// `List` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    Legacy_Node *head;
    Legacy_Node *tail;
    size_t       size;

    void (*add)(List *list, Legacy_Node *node);
    void *(*delete)(List *list, Legacy_Node *node);
    void *(*deleteNodeThatHasTheGivenData)(List *list,
                                           void *dataOfTheNodeToDelete);
    Legacy_Node *(*findNodeByPredicateOfConstString)(
            List *list,
            BOOLEAN (*predicate)(const Legacy_Node *, const char *const),
            const char *allocationTableClassName);
};

List *ListConstructor();

#endif //CLASS_LIST_H
