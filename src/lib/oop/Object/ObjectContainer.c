#include "ObjectContainer.h"

// "public" function.
Object *getObject_ObjectContainer(void *self) {
    return (Object *) getAnonymousPointerValueByIndex(self, 0);
}

// "public" function.
void setObject_ObjectContainer(void *self, Object *object) {
    setAnonymousPointerValueByIndex(self, 0, object);
}
