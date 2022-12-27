#include "AtomicInteger.h"

// TODO:
//// TODO: "private".
//Legacy_AtomicFreer *getLegacy_AtomicFreer(AtomicInteger *atomicInteger) {
//    return ((Legacy_AtomicFreer *) atomicInteger->memberList->getMemberByName(
//            atomicInteger->memberList, __ATOMIC_MEMBER_NAME__));
//}
//
//// TODO: "private". very dangerous.
//int *getPointerToValue(AtomicInteger *atomicInteger) {
//    return (int *) (getLegacy_AtomicFreer(atomicInteger)->data);
//}
//
//// TODO: "public"
//int getValue(AtomicInteger *atomicInteger) {
//    return *(getPointerToValue(atomicInteger));
//}
//
//// TODO: "public".
//void setValue(AtomicInteger *atomicInteger, int value) {
//    // TODO: implement.
//}
//
///// TODO: private
//void initValue(AtomicInteger *atomicInteger, int value) {
//    int *valuePointer = malloc(sizeof(int));
//    *valuePointer     = value;
//    atomicInteger->memberList->addMemberWhichIsPrimitive(
//            atomicInteger->memberList, __ATOMIC_MEMBER_NAME__, valuePointer);
//}
//
//void *AtomicIntegerDestructor(AtomicInteger *atomicInteger) {
//    Legacy_AtomicFreer *legacyAtomicFreer =
//            getLegacy_AtomicFreer(atomicInteger);
//    legacyAtomicFreer->memberList->destructable->destructor(legacyAtomicFreer);
//
//    invokeStoredLegacyObjectDestructor((Object *) atomicInteger);
//
//    free(atomicInteger);
//
//    return NULL;
//}
//
//AtomicInteger *AtomicIntegerConstructor() {
//    AtomicInteger *instance = calloc(1, sizeof *instance);
//    if (instance == NULL) { /* error handling here */
//    }
//
//    instance->memberList = ObjectConstructor("AtomicInteger");
//
//    initValue(instance, 0);
//
//    storeLegacyObjectConstructorAndDestructor((Object *) instance);
//
//    static Constructable const constructable = {
//            .constructor = (void *(*const)(void) )(&AtomicIntegerConstructor)};
//    instance->memberList->memberList->constructable = &constructable;
//
//    static Destructable const destructable = {
//            .destructor = (void *(*const)(void *) )(&AtomicIntegerDestructor)};
//    instance->memberList->memberList->destructable = &destructable;
//
//    return instance;
//}