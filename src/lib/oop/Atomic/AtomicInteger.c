#include "AtomicInteger.h"

// TODO:
//// TODO: "private".
//Legacy_AtomicFreer *getLegacy_AtomicFreer(AtomicInteger *atomicInteger) {
//    return ((Legacy_AtomicFreer *) atomicInteger->methodsLegacy_MemberList->getMemberByName(
//            atomicInteger->methodsLegacy_MemberList, __ATOMIC_MEMBER_NAME__));
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
//    atomicInteger->methodsLegacy_MemberList->addMemberWhichIsPrimitive(
//            atomicInteger->methodsLegacy_MemberList, __ATOMIC_MEMBER_NAME__, valuePointer);
//}
//
//void *AtomicIntegerDestructor(AtomicInteger *atomicInteger) {
//    Legacy_AtomicFreer *legacyAtomicFreer =
//            getLegacy_AtomicFreer(atomicInteger);
//    legacyAtomicFreer->methodsLegacy_MemberList->destructable->destructor(legacyAtomicFreer);
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
//    instance->methodsLegacy_MemberList = ObjectConstructor("AtomicInteger");
//
//    initValue(instance, 0);
//
//    storeLegacyObjectConstructorAndDestructor((Object *) instance);
//
//    static Destructable const destructable = {
//            .destructor = (void *(*const)(void *) )(&AtomicIntegerDestructor)};
//    instance->methodsLegacy_MemberList->methodsLegacy_MemberList->destructable = &destructable;
//
//    return instance;
//}