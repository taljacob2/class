#ifndef CLASS1_H
#define CLASS1_H

#include "AllocationTable.h"
#include "AllocationTableList.h"
#include "Constructable.h"
#include "Destructable.h"
#include "Quote.h"
#include <stdio.h>
#include <stdlib.h>

#define CLASS1_CLASSNAME           Class1
#define CLASS1_CLASSNAME_AS_STRING EXPAND_AND_QUOTE(CLASS1_CLASSNAME)

// Forward declaration of incomplete type
typedef struct class1 CLASS1_CLASSNAME;

struct class1 {

    /// Singleton for the whole class. Sensitive data. DO NOT TOUCH!
    AllocationTable *CLASS_ALLOCATION_TABLE;

    /// Sensitive data. DO NOT TOUCH!
    void *ALLOCATION_ADDRESS;

    /// Sensitive data. DO NOT TOUCH!
    char *CLASS_NAME;

    Constructable const *constructable;

    Destructable const *destructable;

    int x;

    /// Printing method.
    void (*print)();

    /// A logic method.
    void (*addOneToX)();
};

/**
 * @brief Creates a `new` "heap-allocated" instance of `Class1` and initializes
 *        it.
 *
 * @attention Remember to `free` the returned value of this function.
 *
 * For example:
 * @code
 *
 * // Construct.
 * Class1 *class1 = Class1Constructor();
 *
 * // Do something...
 * (*class1->print)(class1);
 * (*class1->addOneToX)(class1);
 * (*class1->print)(class1);
 *
 * // Remember to `free`.
 * free(class1);
 * @endcode
 *
 * @return A pointer to a `new` "heap-allocated" instance of `Class1`.
 */
Class1 *Class1Constructor();

#endif //CLASS1_H
