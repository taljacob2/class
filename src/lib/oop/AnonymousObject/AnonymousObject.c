#include "AnonymousObject.r"

/**
 * @brief Create an inline struct of type `Object`, with an
 *        "anonymous-inline-generated" "className".
 *
 * @return Anonymous-inline-object of type `Object`.
 */
Object *AnonymousObjectConstructor() {
    unsigned char * randomString = getRandomString(20);
    Object *object = construct((char *)randomString);
    free(randomString);

    return object;

}