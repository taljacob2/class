#include "String.h"

static char *get_String(String *self) {
    Object *object = getObject_ObjectContainer(self);
    return (char *) object->getIntegerRValueMember(object, PRIVATE, FIELD,
                                                   __ATOMIC_DATA__);
}

static BOOLEAN set_String(String *self, IntegerRValue integerRValueToSet) {
    Object *object = getObject_ObjectContainer(self);
    return object->setIntegerRValueMember(object, PRIVATE, FIELD,
                                          __ATOMIC_DATA__, integerRValueToSet);
}

static Object *initObject_String(Object *object) {
    object->addIntegerRValueMember(object, PRIVATE, FIELD, __ATOMIC_DATA__,
                                   (IntegerRValue) "");

    return object;
}

String *StringConstructor() {
    String *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    initObjectContainer((ObjectContainer *) instance, "String");

    initObject_String(getObject_ObjectContainer(instance));

    // Assign values at the additional block.
    instance->get = &get_String;
    instance->set = &set_String;

    return instance;
}
