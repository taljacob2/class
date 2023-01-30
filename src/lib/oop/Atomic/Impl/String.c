#include "String.h"

char *get_String(String *self) {
    return (char *) ((Object *) self)
            ->getIntegerRValueMember((Object *) self, PRIVATE, FIELD,
                                     __ATOMIC_DATA__);
}

BOOLEAN set_String(String *self, IntegerRValue integerRValueToSet) {
    return ((Object *) self)
            ->setIntegerRValueMember((Object *) self, PRIVATE, FIELD,
                                     __ATOMIC_DATA__, integerRValueToSet);
}

String *StringConstructor() {
    Object *instance = ObjectConstructor("String");

    ((Object *) instance)
            ->addIntegerRValueMember(instance, PRIVATE, FIELD, __ATOMIC_DATA__,
                                     (IntegerRValue) "");

    String *instanceAsAtomicImpl = ((String *) instance);
    instanceAsAtomicImpl->get    = &get_String;
    instanceAsAtomicImpl->set    = &set_String;

    return (String *) instance;
}