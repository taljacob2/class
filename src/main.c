#include "Class/Class.h"
#include "ClassInheritor.h"

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
int main() {
    //    Class *class = ClassConstructor();

    //    (*class->print)(class);
    //    (*class->addOneToX)(class);
    //    (*class->print)(class);
    //
    //    Class *class_2 = ClassConstructor();
    //    (*class_2->print)();
    //    (*class_2->addOneToX)();
    //    (*class_2->print)();


    //    class->destructable->destructor(class);


    //    free(class_2);


    ObjectBase *objectBase = ObjectBaseConstructor();
    objectBase->destructable->destructor(objectBase);

    Class *class = ClassConstructor();
    //    class->thisObjectBase->destructable->destructor(class);


    ClassInheritor *classInheritor = ClassInheritorConstructor();


    return 0;
}
