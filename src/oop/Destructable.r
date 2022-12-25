#ifndef DESTRUCTABLE_H
#define DESTRUCTABLE_H

/// Interface.
typedef struct {
    void *(*const destructor)(void *self);
} Destructable;

#endif //DESTRUCTABLE_H
