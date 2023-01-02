#include "Circle.h"
#include "CircleV2.h"
#include "CircleV4.h"
#include "CircleV5.h"
#include "../lib/oop/oop.h"

int main() {
    Circle *circle = CircleConstructor();

    CircleV2 *circleV2 = CircleV2Constructor();

    MemberList *memberList = MemberListConstructor("MemberList");

    //    methodsMemberList->methodsMemberList->destructable->destructor(methodsMemberList);

    //    AtomicInteger *atomicInteger = AtomicIntegerConstructor();

    //    atomicInteger->methodsMemberList->methodsMemberList->destructable->destructor(atomicInteger);

    CircleV4 *circleV4 = CircleV4Constructor();

    //    CircleV5 *circleV5 = CircleV5Constructor();


    createAnonymousObject();

    return 0;
}
