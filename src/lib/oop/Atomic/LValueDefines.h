#ifndef LVALUEDEFINES_H
#define LVALUEDEFINES_H

#include "../Object/AnonymousPointer.r"

/**
 * `LValue` resembles any pointer type.
 * For example:
 * `char *`, `void *`, `int **`.
 */
typedef TYPEOF_ANONYMOUS_POINTER LValue;

#endif //LVALUEDEFINES_H
