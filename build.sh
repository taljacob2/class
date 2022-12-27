#!/bin/bash

# Build program.
gcc -g -Wall \
src/main.c \
src/Circle.c \
src/CircleV2.c \
src/CircleV4.c \
src/CircleV5.c \
-L. src/oop/oop.a
