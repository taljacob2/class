#ifndef ANONYMOUSOBJECT_H
#define ANONYMOUSOBJECT_H

#include "../Object/Object.h"

#define ANONYMOUS_OBJECT_NAME __ANONYMOUS_OBJECT__

#define ANONYMOUS_OBJECT___GENERATED_CLASS_NAME \
    CONCAT(__ANONYMOUS_OBJECT__, __COUNTER__)

#define ANONYMOUS_OBJECT___CONST_CLASS_NAME \
    ANONYMOUS_OBJECT___GENERATED_CLASS_NAME


/* ---------- */



/**
 * Usage for example:
 * @code
 * printf("%d\n", LINE_AFTER_INCLUDES);
 * @endcode
 */
#ifdef LINE_BIT_0
#undef LINE_BIT_0
#endif
#ifdef LINE_BIT_1
#undef LINE_BIT_1
#endif
#ifdef LINE_BIT_2
#undef LINE_BIT_2
#endif
#ifdef LINE_BIT_3
#undef LINE_BIT_3
#endif
#ifdef LINE_BIT_4
#undef LINE_BIT_4
#endif
#ifdef LINE_BIT_5
#undef LINE_BIT_5
#endif
// <- This line is the one we generate the number for
#define LINE_BIT_0 0
#define LINE_BIT_1 0
#define LINE_BIT_2 0
#define LINE_BIT_3 0
#define LINE_BIT_4 0
#define LINE_BIT_5 0
#if (__LINE__ - 7) & 1
#  undef LINE_BIT_0
#  define LINE_BIT_0 1
#endif
#if (__LINE__ - 11) >> 1 & 1
#  undef LINE_BIT_1
#  define LINE_BIT_1 (1 << 1)
#endif
#if (__LINE__ - 15) >> 2 & 1
#  undef LINE_BIT_2
#  define LINE_BIT_2 (1 << 2)
#endif
#if (__LINE__ - 19) >> 3 & 1
#  undef LINE_BIT_3
#  define LINE_BIT_3 (1 << 3)
#endif
#if (__LINE__ - 23) >> 4 & 1
#  undef LINE_BIT_4
#  define LINE_BIT_4 (1 << 4)
#endif
#if (__LINE__ - 27) >> 5 & 1
#  undef LINE_BIT_5
#  define LINE_BIT_5 (1 << 5)
#endif
#define LINE_AFTER_INCLUDES (LINE_BIT_0 | LINE_BIT_1 | LINE_BIT_2 | LINE_BIT_3 | LINE_BIT_4 | LINE_BIT_5)




//
//
//// TODO: check if redundant.
//#define CREATE_LOCAL_STRUCT_FROM_MACRO_TEXT(macroTextToSetAsStructName) \
//    typedef char macroTextToSetAsStructName[__LINE__];
//
///**
// * This is the return value.
// *
// * Usage for example:
// * @code
// * printf("%ld\n", SIZEOF_LINE_AFTER_INCLUDES);
// * @endcode
// */
//#define SIZEOF_LINE_AFTER_INCLUDES NOT_INITIALIZED
//
//#ifndef LINE_AFTER_INCLUDES_IS_DEFINED
//#define LINE_AFTER_INCLUDES_IS_DEFINED
//typedef char LINE_AFTER_INCLUDES[__LINE__];
//#undef SIZEOF_LINE_AFTER_INCLUDES
//#define SIZEOF_LINE_AFTER_INCLUDES sizeof(LINE_AFTER_INCLUDES)
//#undef LINE_AFTER_INCLUDES_IS_DEFINED
//#endif

/* ---------- */


Object *createAnonymousObject();

#endif //ANONYMOUSOBJECT_H
