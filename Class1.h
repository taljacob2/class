#ifndef CLASS1_H
#define CLASS1_H

#include <stdio.h>
#include <stdlib.h>

typedef struct class1 Class1; // Forward declaration of incomplete type

struct class1 {
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

    return obj;
}

#endif //CLASS1_H
