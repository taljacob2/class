#ifndef CLASS_LIST_H
#define CLASS_LIST_H

#include "Bool.h"
#include "Node.h"
#include <limits.h>
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct list List;

struct list {
    Node * head;
    Node * tail;
    size_t size;

    Constructable const *constructable;

    Destructable const *destructable;
};

void add(List *list, Node *node);

void *delete (List *list, Node *node);

void *deleteNodeThatHasTheGivenData(List *list, void *dataOfTheNodeToDelete);

Node *findNodeByPredicateOfConstString(List *list,
                                       BOOLEAN (*predicate)(const Node *,
                                                            const char *const),
                                       const char *allocationTableClassName);

List *ListConstructor();

#endif //CLASS_LIST_H
