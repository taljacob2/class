#ifndef BITDEFINES_H
#define BITDEFINES_H


#if ((UINT_MAX) == 0xffffffffu)

#define INT_IS32BIT

#else

#define INT_IS64BIT

#endif





#if ((ULONG_MAX) == 0xfffffffful)

#define LONG_IS32BIT
#define IS_SYSTEM_32BIT 1
#define IS_SYSTEM_64BIT 0

#else

#define LONG_IS64BIT
#define IS_SYSTEM_32BIT 0
#define IS_SYSTEM_64BIT 1

#endif


#endif //BITDEFINES_H
