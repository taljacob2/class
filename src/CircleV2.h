#ifndef CIRCLEV2_H
#define CIRCLEV2_H

#include "oop/Object/oop.h"

// Forward declaration of incomplete type
typedef struct circlev2 CircleV2;

struct circlev2 {

    /// `Circle` implements `Legacy_Object`.
    Legacy_Object *object;

    MemberList *memberList;
};

CircleV2 *CircleV2Constructor();

#endif //CIRCLEV2_H
