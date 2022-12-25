#ifndef CLASSINHERITOR_H
#define CLASSINHERITOR_H

#include "Class/Class.h"


// Forward declaration of incomplete type
typedef struct classInheritor ClassInheritor;

struct classInheritor {

    Class *class;
};

ClassInheritor *ClassInheritorConstructor() {
    ClassInheritor *obj = calloc(1, sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    obj->class = ClassConstructorWithClassName(obj, "ClassInheritor");

    return obj;
}

void *ClassInheritorDestructor(ClassInheritor *classInheritor) {
    ClassDestructor(classInheritor->class);

    // ... Continue destructing `ClassInheritor` here...

    return NULL;
}

#endif //CLASSINHERITOR_H
