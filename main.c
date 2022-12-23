#include "Class1.h"

#include "ObjectBase.h"

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
int main() {
//    Class1 *class1 = Class1Constructor();

//    (*class1->print)(class1);
//    (*class1->addOneToX)(class1);
//    (*class1->print)(class1);
//
//    Class1 *class1_2 = Class1Constructor();
//    (*class1_2->print)();
//    (*class1_2->addOneToX)();
//    (*class1_2->print)();



//    class1->destructable->destructor(class1);


//    free(class1_2);


    ObjectBase *objectBase = ObjectBaseConstructor();
    objectBase->destructable->destructor(objectBase);

    Class1 *class1 = Class1Constructor();
//    class1->thisObjectBase->destructable->destructor(class1);


    return 0;
}
