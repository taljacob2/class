#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H

/// Interface.
typedef struct {
    void (*const destructor)(void *self);
} Destructable;

#endif //DESTRUCTOR_H
