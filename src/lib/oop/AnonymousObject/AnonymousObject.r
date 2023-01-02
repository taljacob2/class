#ifndef ANONYMOUSOBJECT_H
#define ANONYMOUSOBJECT_H

#include "../Object/Object.h"
#include "BitDefines.h"
#include "Random.h"

#define ANONYMOUS_OBJECT_NAME __ANONYMOUS_OBJECT__

#define ANONYMOUS_OBJECT___GENERATED_CLASS_NAME \
    CONCAT(__ANONYMOUS_OBJECT__, __COUNTER__)


Object *createAnonymousObject();

#endif //ANONYMOUSOBJECT_H
