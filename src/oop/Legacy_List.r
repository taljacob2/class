#ifndef CLASS_LEGACY_LIST_R
#define CLASS_LEGACY_LIST_R

#include "Bool.h"
#include "Legacy_Node.r"
#include <limits.h>
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_list Legacy_List;

struct legacy_list {

    /// `Legacy_List` implements `Object`.
    Object *object;

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
            const char *stringToSearchFor);
    void (*addAsUnique)(Legacy_List *list, Legacy_Node *node,
                        BOOLEAN (*predicate)(const Legacy_Node *,
                                             const char *const),
                        const char *stringToSearch);
};

Legacy_List *Legacy_ListConstructor();

#endif //CLASS_LEGACY_LIST_R
