#ifndef RVALUEDEFINES_H
#define RVALUEDEFINES_H

#include "../Object/AnonymousPointer.r"

/**
 * `IntegerRValue` is an `RValue` for any pointer type, or any integer.
 * For example:
 * `char`, `unsigned char`, `int`, `long`, `char *`, `void *`, `int **`
 */
typedef TYPEOF_ANONYMOUS_POINTER IntegerRValue;

/**
 * `DoubleRValue` is an `RValue` for any floating point type.
 * For example:
 * `float`, `double`.
 */
typedef double DoubleRValue;

#endif /* RVALUEDEFINES_H */
