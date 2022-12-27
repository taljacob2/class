#ifndef CIRCLEV2_H
#define CIRCLEV2_H

#include "oop/Object/Object.h"

// Forward declaration of incomplete type
typedef struct circlev2 CircleV2;

struct circlev2 {

    /// `Circle` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *object;

    Legacy_MemberList *legacy_memberList;
};

CircleV2 *CircleV2Constructor();

#endif //CIRCLEV2_H
