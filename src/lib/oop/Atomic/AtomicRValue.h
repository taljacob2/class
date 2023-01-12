#ifndef ATOMICRVALUE_H
#define ATOMICRVALUE_H

#include "AtomicLValue.h"

DEFINE_CLASS_H(AtomicRValue)

AtomicRValue *AtomicRValueConstructor(RValue rValue);

#define INTEGER_RVALUE_AS_OBJECT(rValue) \
    ((Object *) AtomicRValueConstructor((RValue) rValue))

#define __DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__ \
    "__DOUBLE_RVALUE_WHOLE_NUMBER_MEMBER_NAME__"

#define __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__ \
    "__DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__"

#endif //ATOMICRVALUE_H
