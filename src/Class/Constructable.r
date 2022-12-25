#ifndef CONSTRUCTABLE_H
#define CONSTRUCTABLE_H

/// Interface.
typedef struct {
    void* (*const constructor)();
} Constructable;

#endif //CONSTRUCTABLE_H
