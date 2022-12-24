#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

/// Interface.
typedef struct {
    void* (*const constructor)();
} Constructable;

#endif //CONSTRUCTOR_H
