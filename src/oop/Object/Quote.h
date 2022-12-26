#ifndef QUOTE_H
#define QUOTE_H

#define __QUOTE_NOT_EXPANDED__(text) #text
#define QUOTE(text)                  __QUOTE_NOT_EXPANDED__(text)

#endif //QUOTE_H