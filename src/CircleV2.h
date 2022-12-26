#ifndef CIRCLEV2_H
#define CIRCLEV2_H

#include "oop/oop.h"

// Forward declaration of incomplete type
typedef struct circlev2 CircleV2;

struct circlev2 {

    /// `Circle` implements `Object`.
    Object *object;

    MemberList *memberList;
};

CircleV2 *CircleV2Constructor();

#endif //CIRCLEV2_H
