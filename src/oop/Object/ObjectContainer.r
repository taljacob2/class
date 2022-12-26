#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "Object.r"

// Forward declaration of incomplete type
typedef struct objectContainer ObjectContainer;

/// @see how to polymorph https://stackoverflow.com/a/8194632/14427765
struct objectContainer {
    Object *object;
};

#endif //OBJECTCONTAINER_H
