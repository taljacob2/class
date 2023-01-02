#ifndef QUOTE_H
#define QUOTE_H

#define __QUOTE_NOT_EXPANDED__(text) #text
#define QUOTE(text)                  __QUOTE_NOT_EXPANDED__(text)


#define CREATE_LOCAL_CONST_STRING_VAR_FROM_MACRO_TEXT(           \
        _stringVarName_,                                         \
        macroTextToSetAsConstCharValueInTheGiven_stringVarName_) \
    const char *_stringVarName_ =                                \
            QUOTE(macroTextToSetAsConstCharValueInTheGiven_stringVarName_);

#endif //QUOTE_H