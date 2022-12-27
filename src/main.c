#include "Circle.h"
#include "CircleV2.h"
#include "CircleV4.h"
#include "CircleV5.h"
#include "oop/oop.h"

int main() {
    Circle *circle = CircleConstructor();

    CircleV2 *circleV2 = CircleV2Constructor();

    MemberList *memberList = MemberListConstructor("MemberList");

    //    memberList->memberList->destructable->destructor(memberList);

    //    AtomicInteger *atomicInteger = AtomicIntegerConstructor();

    //    atomicInteger->memberList->memberList->destructable->destructor(atomicInteger);

    CircleV4 *circleV4 = CircleV4Constructor();

    //    CircleV5 *circleV5 = CircleV5Constructor();


    return 0;
}
