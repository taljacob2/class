#include "String.h"

// TODO: DEBUG
extern Legacy_ObjectComponent *getLegacyObjectComponent(Object *object);

extern Legacy_MemberList *getAutoDestructable(Object *object);

extern void setAutoDestructable(Object *          object,
                                AutoDestructable *autoDestructable);

extern Legacy_MemberList *getDestructorMemberList(Object *object);

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

void *StringDestructor(String *self) {
    const char *thisDestructorName = "void *StringDestructor(String *self)";

    /*
     * Re-set `AutoDestructable` to update the address to destruct.
     *
     * 1. Mute the `StringDestructor` in the DESTRUCTOR member list.
     * 2. Remove the old `AutoDestructable`.
     * 3. Set the new `AutoDestructable` to be updated with the new block.
     * 4. Re-enable the `StringDestructor` in the DESTRUCTOR member list.
     */

    // 1. Mute the `StringDestructor` in the DESTRUCTOR member list.

    Legacy_MemberList *destructorsLegacyMemberList =
            getDestructorMemberList((Object *) self);
    destructorsLegacyMemberList->getMemberByName(destructorsLegacyMemberList,
                                                 (char *) thisDestructorName);

    // 1. Remove the old `AutoDestructable`.
    AutoDestructableDestructor(
            (AutoDestructable *) getAutoDestructable((Object *) self));

    /*
     * Concise the entire `String` block to be at the size of `Object`.
     * This will `free` the additional block.
     * Assign self to the reallocated memory block.
     */
    self = realloc(self, sizeof(Object));

    // 2. Set the new `AutoDestructable` to be updated with the new block.
    setAutoDestructable((Object *) self,
                        AutoDestructableConstructorWithLegacy_Object(
                                (Legacy_Object *) self));

    return NULL;
}

String *StringConstructor() {
    String *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    Object *object = ObjectConstructor("String");

    object->addIntegerRValueMember(object, PRIVATE, FIELD, __ATOMIC_DATA__,
                                   (IntegerRValue) "");

    object->addLValueMember(object, PUBLIC, DESTRUCTOR,
                            "void *StringDestructor(String *self)",
                            (LValue) &StringDestructor, FALSE);

    // Assign `Object` at the start of the block.
    memcpy(instance, object, sizeof(Object));

    // Assign values at the additional block.
    instance->get = &get_String;
    instance->set = &set_String;

    return instance;
}