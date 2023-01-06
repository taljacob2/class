#include "../lib/oop/oop.h"
#include "Circle.h"
#include "CircleV2.h"
#include "CircleV4.h"
#include "CircleV5.h"

int main() {
    //    Circle *circle = CircleConstructor();
    //
    //    CircleV2 *circleV2 = CircleV2Constructor();
    //

    //    Legacy_MemberListConstructor();
    //    MemberList *memberList = MemberListConstructor("MemberList");
    //    memberList->legacyObjectComponent->destructable->destructor(memberList);

    //    methodsLegacy_MemberList->methodsLegacy_MemberList->destructable->destructor(methodsLegacy_MemberList);

    //    AtomicInteger *atomicInteger = AtomicIntegerConstructor();

    //    atomicInteger->methodsLegacy_MemberList->methodsLegacy_MemberList->destructable->destructor(atomicInteger);

    //    CircleV4 *circleV4 = CircleV4Constructor();

    //    AnonymousObjectConstructor();

    //        CircleV5 *circleV5 = CircleV5Constructor();


    //        Legacy_MemberList *legacyMemberList =
    //                Legacy_MemberListConstructorWithLegacy_Object(
    //                        (Legacy_Object *) MemberListConstructor());

    //    Legacy_MemberList *legacyMemberList =
    //            Legacy_MemberListConstructorWithLegacy_Object(
    //                    (Legacy_Object *) Legacy_ListConstructor());
    //    legacyMemberList->legacyObjectComponent->destructable->destructor(legacyMemberList);


    //    MemberList * memberList1 = MemberListConstructor();
    //
    //    memberList1->addMemberWhichIsLegacy_Object(memberList1, "legacyList",
    //            (Legacy_Object *) Legacy_ListConstructor());

    //    memberList1->legacyObjectComponent->destructable->destructor(memberList1);

    //    Legacy_List *legacyList = Legacy_ListConstructor();
    //    legacyList->legacyObjectComponent->destructable->destructor(legacyList);


    //
    //        Object *object= construct("Object");
    //
    //        destruct(object);


    //    // TODO: FIXME:
    //    //  Conclusion: allocationTableList doesn't receive the correct address!!!
    //    destruct(object);

    Object *object = construct("Object");

    object->addPublicField(object, "legacyList",
                           (Legacy_Object *) Legacy_ListConstructor());
//
//    Legacy_List *legacyList =
//            (Legacy_List *) object->getPublicField(object, "legacyList");
//    legacyList->legacyObjectComponent->destructable->destructor(legacyList);

//    destruct(object);


    return 0;
}
