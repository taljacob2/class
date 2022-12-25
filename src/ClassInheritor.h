#ifndef CLASSINHERITOR_H
#define CLASSINHERITOR_H

#include "Class/Class.h"


// Forward declaration of incomplete type
typedef struct classInheritor ClassInheritor;

struct classInheritor {
    Class *class;
};

ClassInheritor *ClassInheritorConstructor();

#endif //CLASSINHERITOR_H
