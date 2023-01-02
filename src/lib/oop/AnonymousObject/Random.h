#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>
#include <time.h>

unsigned char getRandomLowercaseLetter();

unsigned char getRandomUppercaseLetter();

unsigned char getRandomNumberLetter();

unsigned char *getRandomString(size_t stringLenToGenerate);

#endif //RANDOM_H
