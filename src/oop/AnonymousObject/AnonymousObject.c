#include "AnonymousObject.r"

Object *createAnonymousObject(){
    const char* thisAnonymousObjectClassName = QUOTE(ANONYMOUS_OBJECT___CONST_CLASS_NAME);
    DEFINE_CLASS_H(thisAnonymousObjectClassName)

}