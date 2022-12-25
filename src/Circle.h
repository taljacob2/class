#ifndef CIRCLE_H
#define CIRCLE_H

#include "oop/oop.h"


// Forward declaration of incomplete type
typedef struct circle Circle;

struct circle {

    /// `Circle` implements `Object`.
    Object *object;

    /// `Circle` implements `AutoDestructable`.
    AutoDestructable *autoDestructable;

    int radius;
};

Circle *CircleConstructor();

#endif //CIRCLE_H
