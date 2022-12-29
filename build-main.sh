#!/bin/bash

source ./config.sh

# Build main program.
gcc -g -Wall \
src/main/main.c \
src/main/Circle.c \
src/main/CircleV2.c \
src/main/CircleV4.c \
src/main/CircleV5.c \
-L. src/lib/oop/"$LIB_FILE_NAME.a" \
-o src/main/a.out
