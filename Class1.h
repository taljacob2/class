#ifndef CLASS1_H
#define CLASS1_H

#include "AllocationTable.h"
#include "Quote.h"
#include <stdio.h>
#include <stdlib.h>

#define CLASS1_CLASSNAME           Class1
#define CLASS1_CLASSNAME_AS_STRING EXPAND_AND_QUOTE(CLASS1_CLASSNAME)

typedef struct class1
        CLASS1_CLASSNAME; // Forward declaration of incomplete type

struct class1 {

    /// Singleton for the whole class. Sensitive data. DO NOT TOUCH!
    AllocationTable *CLASS_ALLOCATION_TABLE;

    /// Sensitive data. DO NOT TOUCH!
    void *ALLOCATION_ADDRESS;

    /// Sensitive data. DO NOT TOUCH!
    char *CLASS_NAME;

    int x;

    /// Printing method.
    void (*print)();

    /// A logic method.
    void (*addOneToX)();
};

static void print(Class1 *class1) { printf("x = %d\n", class1->x); }

static void addOneToX(Class1 *class1) { class1->x += 1; }

static void constructor_Class1_fields(Class1 *class1) {
    class1->x         = 1;
    class1->print     = &print;
    class1->addOneToX = &addOneToX;
}

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
Class1 *Class1Constructor() {
    Class1 *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Class1_fields(obj);
    obj->CLASS_NAME         = CLASS1_CLASSNAME_AS_STRING;
    obj->ALLOCATION_ADDRESS = obj;
    obj->CLASS_ALLOCATION_TABLE =
            findAllocationTableByClassName(obj->CLASS_NAME);
    if (obj->CLASS_ALLOCATION_TABLE == NULL) {
        obj->CLASS_ALLOCATION_TABLE =
                AllocationTableConstructorWithClassName(obj->CLASS_NAME);

        // Create a node that its data points to `obj->CLASS_ALLOCATION_TABLE`.
        Node *nodeThatItsDataPointsClassAllocationTable =
                NodeConstructorWithDataAndDataSize(obj->CLASS_ALLOCATION_TABLE,
                                                   sizeof(void *));

        // Add this node to `GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList`.
        add(GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList,
            nodeThatItsDataPointsClassAllocationTable);
    }

    // Create a node that its data points to the "pointer of `obj`".
    Node *nodeThatItsDataPointsToThePointerOfObj =
            NodeConstructorWithDataAndDataSize(obj->ALLOCATION_ADDRESS,
                                               sizeof(void *));

    // Add this node to `getClass1AllocationTable()->allocationAddressList`.
    add(getClass1AllocationTable()->allocationAddressList,
        nodeThatItsDataPointsToThePointerOfObj);

    return obj;
}

void Class1Destructor(Class1 *class1) {
    if (class1 == NULL) { return; }

    deleteNodeThatHasTheGivenData(
            getClass1AllocationTable()->allocationAddressList,
            class1->ALLOCATION_ADDRESS);

    free(class1);
}

#endif //CLASS1_H
