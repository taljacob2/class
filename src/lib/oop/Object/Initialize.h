#ifndef INITIALIZE_H
#define INITIALIZE_H

/* See https://stackoverflow.com/a/2390626/14427765 */

/*
 * Example of use:
 *
 * ```
 * #include <stdio.h>
 * #include "Initialize.h"
 *
 * static void finalize(void)
 * {
 *     printf("finalize\n");
 * }
 *
 * static void finalize9(void)
 * {
 *     printf("finalize9\n");
 * }
 *
 * static void finalize5(void)
 * {
 *     printf("finalize5\n");
 * }
 *
 * static void finalize7(void)
 * {
 *     printf("finalize7\n");
 * }
 *
 * INITIALIZER(initialize)
 * {
 *     printf("initialize\n");
 *     atexit(finalize);
 *     atexit(finalize9);
 * }
 *
 * INITIALIZER(initialize2)
 * {
 *     printf("initialize2\n");
 *     atexit(finalize5);
 *     atexit(finalize7);
 * }
 *
 * int main(int argc, char** argv)
 * {
 *     printf("main\n");
 *     return 0;
 * }
 * ```
 */


#include <stdlib.h>

#ifdef __cplusplus
#define INITIALIZER(f) \
        static void f(void); \
        struct f##_t_ { f##_t_(void) { f(); } }; static f##_t_ f##_; \
        static void f(void)
#elif defined(_MSC_VER)
#pragma section(".CRT$XCU",read)
#define INITIALIZER2_(f,p) \
        static void f(void); \
        __declspec(allocate(".CRT$XCU")) void (*f##_)(void) = f; \
        __pragma(comment(linker,"/include:" p #f "_")) \
        static void f(void)
#ifdef _WIN64
#define INITIALIZER(f) INITIALIZER2_(f,"")
#else
#define INITIALIZER(f) INITIALIZER2_(f,"_")
#endif
#else
#define INITIALIZER(f) \
        static void f(void) __attribute__((constructor)); \
        static void f(void)
#endif


#endif /* INITIALIZE_H */
