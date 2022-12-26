#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "Legacy_Object.r"

// Forward declaration of incomplete type
typedef struct objectContainer ObjectContainer;

struct objectContainer {
    Legacy_Object *object;
};


#endif //OBJECTCONTAINER_H
