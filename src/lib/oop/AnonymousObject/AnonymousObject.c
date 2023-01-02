#include "AnonymousObject.r"

/**
 * @brief Create an inline struct of type `Object`, with an
 *        "anonymous-inline-generated" "className".
 *
 * -----------------------------------------------------------------------------
 *
 * Proof of concept: "inline-object":
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
 * -----------------------------------------------------------------------------
 *
 * Proof of concept: "generate object name":
 *
 * @code
 * #include <stdio.h>
 *
 * typedef char LINE_AFTER_INCLUDES[__LINE__];
 * typedef char LINE_AFTER_INCLUDES2[__LINE__];
 * typedef char LINE_AFTER_INCLUDES3[__LINE__];
 *
 * int main() {
 *     printf("Hello World\n");
 *
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES));
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES));
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES));
 *
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES2));
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES2));
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES2));
 *
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES));
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES));
 *     printf("%ld\n", sizeof(LINE_AFTER_INCLUDES));
 *
 *     return 0;
 * }
 * @endcode
 *
 * @return Anonymous-inline-object of type `Object`.
 * @see https://stackoverflow.com/questions/24850392/is-there-a-way-to-get-the-value-of-line-on-one-line-and-use-that-value-on-ot
 * @see https://stackoverflow.com/a/24941973/14427765
 */
Object *createAnonymousObject() {

//    DEFINE_CLASS_H(ANONYMOUS_OBJECT___GENERATED_CLASS_NAME)

//    const char *thisAnonymousObjectClassName =

    unsigned char * randomString = getRandomString(20);
    Object *object = construct((char *)randomString);
    free(randomString);

    return object;

}