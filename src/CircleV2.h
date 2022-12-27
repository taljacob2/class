#ifndef CIRCLEV2_H
#define CIRCLEV2_H

#include "oop/Object/Object.h"

// Forward declaration of incomplete type
typedef struct circlev2 CircleV2;

struct circlev2 {

    /// `Circle` implements `Legacy_ObjectComponent`.
    Legacy_ObjectComponent *legacyObjectComponent;

    Legacy_MemberList *legacyMemberList;
};

CircleV2 *CircleV2Constructor();

#endif //CIRCLEV2_H
