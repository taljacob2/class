#include "../lib/oop/oop.h"
#include "Circle.h"
#include "CircleV2.h"
#include "CircleV4.h"
#include "CircleV5.h"
#include "CircleV7.h"

//static int addFunc(int x, int y) { return x + y; }

int main() {

    //    int (*function)(int, int) = malloc(sizeof(TYPEOF_ANONYMOUS_POINTER));
    //
    //    static int addFunc2(int x, int y) { return x + y; }
    //
    //    //    *function = int f(int x, int y) {
    //    //        // a nested function!
    //    //        return x + y;
    //    //    };
    //
    //    function = &addFunc;
    //
    //
    //    //    static int(*func)(int,int) = int f(int x, int y) {
    //    //        // a nested function!
    //    //        return x + y;
    //    //    };


    //    LAMBDA(int addFunc2(int x, int y) { return x + y; })

    //    AtomicLValueConstructor(
    //            LAMBDA(int addFunc2(int x, int y) { return x + y; }), FALSE);


    AtomicLValueConstructor(LAMBDA_START(int addFunc(int x, int y) {
                                return x + y;
                            }) LAMBDA_END,
                            FALSE);


    return 0;
}