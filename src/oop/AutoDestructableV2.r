#ifndef AUTODESTRUCTABLEV2_H
#define AUTODESTRUCTABLEV2_H

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
typedef struct autoDestructableV2 AutoDestructableV2;

struct autoDestructableV2 {

    /// `AutoDestructableV2` implements `Object`.
    Object *object;

    /// Singleton for the whole autoDestructableV2. Sensitive data. DO NOT TOUCH!
    Legacy_AllocationTable *OBJECT_ALLOCATION_TABLE;

    /// Sensitive data. DO NOT TOUCH!
    Object *allocatedAddress;
};

AutoDestructableV2 *AutoDestructableV2ConstructorWithClassName(
        Object *objectToSaveItsAddressToAllocationTable, const char *className);

/**
 * @brief Creates a `new` "heap-allocated" instance of `AutoDestructableV2` and
 *        initializes it.
 *
 * @attention Remember to `free` the returned value of this function.
 *
 * For example:
 * @code
 *
 * // Construct.
 * AutoDestructableV2 *autoDestructableV2 = AutoDestructableV2Constructor();
 *
 * // Do something...
 * (*autoDestructableV2->print)(autoDestructableV2);
 * (*autoDestructableV2->addOneToX)(autoDestructableV2);
 * (*autoDestructableV2->print)(autoDestructableV2);
 *
 * // Remember to `free`.
 * free(autoDestructableV2);
 * @endcode
 *
 * @return A pointer to a `new` "heap-allocated" instance of `AutoDestructableV2`.
 */
AutoDestructableV2 *AutoDestructableV2Constructor();

Object *AutoDestructableV2Destructor(AutoDestructableV2 *autoDestructableV2);

#endif //AUTODESTRUCTABLEV2_H
