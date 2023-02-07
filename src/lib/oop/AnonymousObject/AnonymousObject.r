#ifndef ANONYMOUSOBJECT_H
#define ANONYMOUSOBJECT_H

#include "../Object/Object.h"
#include "../Atomic/Random.r"

/**
 * @brief Create an inline struct of type `Object`, with an
 *        "anonymous-inline-generated" "className".
 *
 * @return Anonymous-inline-object of type `Object`.
 */
Object *AnonymousObjectConstructor();

#endif /* ANONYMOUSOBJECT_H */
