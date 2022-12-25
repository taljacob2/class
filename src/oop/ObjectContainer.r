#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "Object.r"

// Forward declaration of incomplete type
typedef struct objectContainer ObjectContainer;

struct objectContainer {
    Object *object;
};


#endif //OBJECTCONTAINER_H
