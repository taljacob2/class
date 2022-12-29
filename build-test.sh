#!/bin/bash

source ./config.sh

# Build test program.
gcc -g -Wall \
src/test/main.c \
-L. src/lib/oop/"$LIB_FILE_NAME.a" \
-o src/test/a.out
