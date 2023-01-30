#include "String.h"

/* --------------------------------- Extern --------------------------------- */

extern IntegerRValue
getIntegerRValueMember(Object *                  self,
                       enum MemberAccessModifier memberAccessModifier,
                       enum MemberType memberType, const char *memberName);

extern BOOLEAN
setIntegerRValueMember(Object *                  self,
                       enum MemberAccessModifier memberAccessModifier,
                       enum MemberType memberType, const char *memberName,
                       IntegerRValue integerRValueValueToSet);

extern void
addIntegerRValueMember(Object *                  self,
                       enum MemberAccessModifier memberAccessModifier,
                       enum MemberType memberType, const char *memberName,
                       IntegerRValue integerRValue);

/* ----------------------------- Implementation ----------------------------- */

char *get_String(String *atomicImpl) {
    return (char *) getIntegerRValueMember((Object *) atomicImpl, PRIVATE,
                                           FIELD, __ATOMIC_DATA__);
}

BOOLEAN set_String(String *atomicImpl, IntegerRValue integerRValueToSet) {
    return setIntegerRValueMember((Object *) atomicImpl, PRIVATE, FIELD,
                                  __ATOMIC_DATA__, integerRValueToSet);
}

String *StringConstructor() {
    Object *instance = ObjectConstructor("String");

    addIntegerRValueMember(instance, PRIVATE, FIELD, __ATOMIC_DATA__,
                           (IntegerRValue) "");

    return (String *) instance;
}