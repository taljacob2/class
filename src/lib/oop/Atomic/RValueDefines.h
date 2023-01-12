#ifndef RVALUEDEFINES_H
#define RVALUEDEFINES_H

#include "../Object/AnonymousPointer.r"

// `RValue` acts the same as the `&&` "move" operator in cpp.
typedef TYPEOF_ANONYMOUS_POINTER RValue;
typedef RValue                   IntegerRValue;
typedef double                   DoubleRValue;

#endif //RVALUEDEFINES_H
