#ifndef CLASS_LEGACY_LIST_R
#define CLASS_LEGACY_LIST_R

#include "Bool.h"
#include "Legacy_Node.r"
#include "Legacy_ObjectContainer.r"
#include <limits.h>
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_list Legacy_List;

struct legacy_list {

    /// `Legacy_List` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *legacyObjectComponent;

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

    /**
     * @attention This is generic for all **Legacy_ObjectComponent** implementors
     *            ( = Legacy_Object). Can work only if the `Legacy_Node->data`
     *            is implements **Legacy_ObjectComponent** ( = Legacy_Object).
     */
    void *(*Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData)(
            Legacy_List *list);
};

Legacy_List *Legacy_ListConstructor();

#endif //CLASS_LEGACY_LIST_R
