#include "AnonymousObject.r"

Object *AnonymousObjectConstructor() {
    unsigned char * randomString = getRandomString(20);
    Object *object = ObjectConstructor((char *) randomString);
    free(randomString);

    return object;
}