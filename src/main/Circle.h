#ifndef CIRCLE_H
#define CIRCLE_H

#include "../lib/oop/Object/Object.h"


/* Forward declaration of incomplete type */
typedef struct circle Circle;

struct circle {

    /** `Circle` implements `Legacy_ObjectComponent`. */
    Legacy_ObjectComponent *legacyObjectComponent;

    /** `Circle` implements `AutoDestructable`. */
    AutoDestructable *autoDestructable;

    int radius;
};

Circle *CircleConstructor();

#endif /* CIRCLE_H */
