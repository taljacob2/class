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

static void *StringDestructor(String *self) {
    free(self);
    return NULL;
}

static Object *initObject_String() {
    Object *object = ObjectConstructor("String");

    object->addIntegerRValueMember(object, PRIVATE, FIELD, __ATOMIC_DATA__,
                                   (IntegerRValue) "");

    object->addLValueMember(object, PUBLIC, DESTRUCTOR,
                            "void *StringDestructor(String *self)",
                            (LValue) &StringDestructor, FALSE);

    return object;
}

String *StringConstructor() {
    String *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    // Assign `Object` to its anonymous field.
    setObject_ObjectContainer(instance, initObject_String());

    // Assign values at the additional block.
    instance->get = &get_String;
    instance->set = &set_String;

    return instance;
}
