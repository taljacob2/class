#include "ObjectContainer.h"

// "public" function.
Legacy_ObjectComponent *getLegacy_ObjectComponent_ObjectContainer(void *self) {
    return (Legacy_ObjectComponent *) getAnonymousPointerValueByIndex(self, 0);
}

// "public" function.
void setLegacy_ObjectComponent_ObjectContainer(
        void *self, Legacy_ObjectComponent *legacyObjectComponent) {
    setAnonymousPointerValueByIndex(self, 0, legacyObjectComponent);
}

// "public" function.
AutoDestructable *getAutoDestructable_ObjectContainer(void *self) {
    return (AutoDestructable *) getAnonymousPointerValueByIndex(self, 1);
}

// "public" function.
void setAutoDestructable_ObjectContainer(void *            self,
                                         AutoDestructable *autoDestructable) {
    setAnonymousPointerValueByIndex(self, 1, autoDestructable);
}

// "public" function.
Object *getObject_ObjectContainer(void *self) {
    return (Object *) getAnonymousPointerValueByIndex(self, 2);
}

// "public" function.
void setObject_ObjectContainer(void *self, Object *object) {
    setAnonymousPointerValueByIndex(self, 2, object);
}

// "private" function.
static void *ObjectContainerDestructor(ObjectContainer *self) {

//    ObjectDestructor(getObject_ObjectContainer(self));

    AutoDestructableDestructor(getAutoDestructable_ObjectContainer(self));

    free(getLegacy_ObjectComponent_ObjectContainer(self));

    free(self);

    return NULL;
}

// "public" function.
void ObjectContainerConstructor(ObjectContainer *self, char *className) {

    // Assign `Legacy_ObjectComponent` to its anonymous field.
    setLegacy_ObjectComponent_ObjectContainer(
            self, Legacy_ObjectComponentConstructorClassName(className));

    // Assign `AutoDestructable` to its anonymous field.
    setAutoDestructable_ObjectContainer(
            self, AutoDestructableConstructorWithLegacy_Object(
                          (Legacy_Object *) self));

    // Assign `Object` to its anonymous field.
    setObject_ObjectContainer(self, ObjectConstructor(className));

    // Set `Destructable`.
    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&ObjectContainerDestructor)};
    getLegacy_ObjectComponent_ObjectContainer(self)->destructable =
            &destructable;
}