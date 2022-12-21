#include "AllocationTableList.h"
#include "Class1.h"

int main() {
    Class1 *class1 = Class1Constructor();

//    (*class1->print)(class1);
//    (*class1->addOneToX)(class1);
//    (*class1->print)(class1);
//
//    Class1 *class1_2 = Class1Constructor();
//    (*class1_2->print)();
//    (*class1_2->addOneToX)();
//    (*class1_2->print)();


//    Class1Destructor(class1);
    class1->destructable->destructor(class1);

//    free(class1_2);




    return 0;
}
