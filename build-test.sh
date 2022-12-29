#!/bin/bash

# Build test program.
gcc -g -Wall \
src/test/main.c \
-L. src/lib/oop/oop.a \
-o src/test/a.out
