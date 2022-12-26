#include "Circle.h"
#include "CircleV2.h"
#include "oop/oop.h"

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
int main() {
    //    AutoDestructable *autoDestructable = AutoDestructableConstructor();

    //    (*autoDestructable->print)(autoDestructable);
    //    (*autoDestructable->addOneToX)(autoDestructable);
    //    (*autoDestructable->print)(autoDestructable);
    //
    //    AutoDestructable *class_2 = AutoDestructableConstructor();
    //    (*class_2->print)();
    //    (*class_2->addOneToX)();
    //    (*class_2->print)();


    //    autoDestructable->destructable->destructor(autoDestructable);


    //    free(class_2);


    //    Object *object = ObjectConstructor();
    //    object->destructable->destructor(object);

    //    AutoDestructable *autoDestructable = AutoDestructableConstructor();
    //    autoDestructable->object->destructable->destructor(autoDestructable);


    Circle *circle = CircleConstructor();

    MemberList *memberList = MemberListConstructor();

//    CircleV2 *circleV2 = CircleV2Constructor();


    return 0;
}
