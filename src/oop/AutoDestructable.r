#ifndef AUTODESTRUCTABLE_H
#define AUTODESTRUCTABLE_H

#include "Constructable.r"
#include "Destructable.r"
#include "InvocationStatus.r"
#include "Legacy_AllocationTable.r"
#include "Legacy_AllocationTableList.r"
#include "Object.r"
#include "ObjectContainer.r"
#include <stdio.h>
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct autoDestructable AutoDestructable;

struct autoDestructable {

    /// `AutoDestructable` implements `Object`.
    Object *object;

    /// Singleton for the whole autoDestructable. Sensitive data. DO NOT TOUCH!
    Legacy_AllocationTable *OBJECT_ALLOCATION_TABLE;

    /// Sensitive data. DO NOT TOUCH!
    ObjectContainer *allocatedAddress;

    int x;

    /// Printing method.
    void (*print)();

    /// A logic method.
    void (*addOneToX)();
};

AutoDestructable *AutoDestructableConstructorWithClassName(
        ObjectContainer *objectContainerToSaveItsAddressToAllocationTable,
        const char *     className);

/**
 * @brief Creates a `new` "heap-allocated" instance of `AutoDestructable` and initializes
 *        it.
 *
 * @attention Remember to `free` the returned value of this function.
 *
 * For example:
 * @code
 *
 * // Construct.
 * AutoDestructable *autoDestructable = AutoDestructableConstructor();
 *
 * // Do something...
 * (*autoDestructable->print)(autoDestructable);
 * (*autoDestructable->addOneToX)(autoDestructable);
 * (*autoDestructable->print)(autoDestructable);
 *
 * // Remember to `free`.
 * free(autoDestructable);
 * @endcode
 *
 * @return A pointer to a `new` "heap-allocated" instance of `AutoDestructable`.
 */
AutoDestructable *AutoDestructableConstructor();

ObjectContainer *AutoDestructableDestructor(AutoDestructable *autoDestructable);

#endif //AUTODESTRUCTABLE_H
