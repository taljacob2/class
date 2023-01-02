#include "Random.r"

void initRand() { srand(time(NULL)); }

unsigned char getIndexByChar(unsigned char charToCalculate,
                             unsigned char baseChar) {
    return charToCalculate - baseChar;
}

unsigned char getCharByIndex(unsigned char index, unsigned char baseChar) {
    return baseChar + index;
}

unsigned char getRandomChar(unsigned char range, unsigned char baseChar) {
    return getCharByIndex(rand() % range, baseChar);
}

unsigned char getRandomLowercaseLetter() {
    unsigned char baseChar = 'a';
    unsigned char range    = 'z' - baseChar + 1;
    return getRandomChar(range, baseChar);
}

unsigned char getRandomUppercaseLetter() {
    return getRandomLowercaseLetter() - ('a' - 'A');
}

unsigned char getRandomNumberLetter() {
    unsigned char baseChar = '0';
    unsigned char range    = '9' - baseChar + 1;
    return getRandomChar(range, baseChar);
}

/**
 * @attention Remember to `free` the returned value.
 */
unsigned char *getRandomString(size_t stringLenToGenerate) {
    unsigned char *string =
            malloc(sizeof(unsigned char) * (stringLenToGenerate + 1));
    string[stringLenToGenerate] = 0;

    for (size_t i = 0; i < stringLenToGenerate; i++) {
        unsigned char valueToSet = 'a';
        switch (rand() % 3) {
            case 0:
                valueToSet = getRandomLowercaseLetter();
                break;
            case 1:
                valueToSet = getRandomUppercaseLetter();
                break;
            case 2:
                valueToSet = getRandomNumberLetter();
                break;
        }
        string[i] = valueToSet;
    }

    return string;
}

// -----------------------------------------------------------------------------

/*
 * See more here: https://www.geeksforgeeks.org/functions-that-are-executed-before-and-after-main-in-c/
 */

/*
 * Apply the constructor attribute to runBeforeMain_Random() so that it is
 * executed before main()
 */
void runBeforeMain_Random(void) __attribute__((constructor));

/* implementation of runBeforeMain_Random */
void runBeforeMain_Random(void) { initRand(); }
