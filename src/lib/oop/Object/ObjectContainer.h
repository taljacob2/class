#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "Object.r"

// Forward declaration of incomplete type
typedef struct objectContainer ObjectContainer;

struct objectContainer {

    /// Implements `Legacy_ObjectComponent` privately.
    Legacy_ObjectComponent *legacyObjectComponent;

    /// Implements `AutoDestructable` privately.
    AutoDestructable *autoDestructable;

    /// Implements `Object` privately.
    Object *object;
};

/* --------------------------------- */

Legacy_ObjectComponent *getLegacy_ObjectComponent_ObjectContainer(void *self);
void                    setLegacy_ObjectComponent_ObjectContainer(
                           void *self, Legacy_ObjectComponent *legacyObjectComponent);
AutoDestructable *getAutoDestructable_ObjectContainer(void *self);
void              setAutoDestructable_ObjectContainer(void *            self,
                                                      AutoDestructable *autoDestructable);
Object *          getObject_ObjectContainer(void *self);
void              setObject_ObjectContainer(void *self, Object *object);

/* --------------------------------- */

void ObjectContainerConstructor(ObjectContainer *self, char *className);

#endif //OBJECTCONTAINER_H
