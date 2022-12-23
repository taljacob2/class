#ifndef CLASS_LEGACY_LIST_H
#define CLASS_LEGACY_LIST_H

#include "Bool.h"
#include "Legacy_Node.h"
#include <limits.h>
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_list Legacy_List;

struct legacy_list {

    /// `Legacy_List` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    Legacy_Node *head;
    Legacy_Node *tail;
    size_t       size;

    void (*add)(Legacy_List *list, Legacy_Node *node);
    void *(*delete)(Legacy_List *list, Legacy_Node *node);
    void *(*deleteNodeThatHasTheGivenData)(Legacy_List *list,
                                           void *       dataOfTheNodeToDelete);
    Legacy_Node *(*findNodeByPredicateOfConstString)(
            Legacy_List *list,
            BOOLEAN (*predicate)(const Legacy_Node *, const char *const),
            const char *allocationTableClassName);
};

Legacy_List *Legacy_ListConstructor();

#endif //CLASS_LEGACY_LIST_H
