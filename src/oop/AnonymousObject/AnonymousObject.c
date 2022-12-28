#include "AnonymousObject.r"

/**
 * @brief Create an inline struct of type `Object`, with an "anonymous-generated"
 *        "className".
 *
 * Prove of concept:
 *
 * @code
 * #include <stdio.h>
 *
 * int main() {
 *     typedef struct test Test;
 *     struct test {
 *       int x;
 *     };
 *
 *     Test testStruct = { .x = 123 };
 *
 *     printf("Hello World\n");
 *     printf("%d\n", testStruct.x);
 *
 *     return 0;
 * }
 * @endcode
 *
 * @return
 *
 * @see https://stackoverflow.com/questions/24850392/is-there-a-way-to-get-the-value-of-line-on-one-line-and-use-that-value-on-ot
 * @see More About Preventing A Macro-Expanding With This Trick:
 *      https://stackoverflow.com/a/11694231/14427765
 */
Object *createAnonymousObject() {
    //    const char* thisAnonymousObjectClassName = QUOTE(ANONYMOUS_OBJECT___CONST_CLASS_NAME);
    //    DEFINE_CLASS_H(thisAnonymousObjectClassName)
    //

//    CREATE_LOCAL_CONST_STRING_VAR_FROM_MACRO_TEXT(
//            thisAnonymousObjectClassName, ANONYMOUS_OBJECT___CONST_CLASS_NAME)


    DEFINE_CLASS_H(ANONYMOUS_OBJECT___CONST_CLASS_NAME)
}