#ifndef AUTODESTRUCTABLE_H
#define AUTODESTRUCTABLE_H

#include "Destructable.r"
#include "InvocationStatus.r"
#include "Legacy_AllocationTable.r"
#include "Legacy_AllocationTableList.r"
#include "Legacy_Object.r"
#include "Legacy_ObjectComponent.r"
#include <stdio.h>
#include <stdlib.h>

/* Forward declaration of incomplete type */
typedef struct autoDestructable AutoDestructable;

struct autoDestructable {

    /** `AutoDestructable` implements `Legacy_ObjectComponent`. */
    Legacy_ObjectComponent *legacyObjectComponent;

    /** Sensitive data. DO NOT TOUCH! */
    Legacy_Object *allocatedAddress;
};

AutoDestructable *AutoDestructableConstructorWithLegacy_Object(
        Legacy_Object *legacyObjectToSaveItsAddressToAllocationTable);

/* TODO: deprecated. remove this. */
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

Legacy_Object *AutoDestructableDestructor(AutoDestructable *autoDestructable);

#endif /* AUTODESTRUCTABLE_H */
