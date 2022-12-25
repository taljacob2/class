#!/bin/bash

# Build "oop.a".
#PWD=$(pwd)
#cd src/oop
#./build-library.sh
#cd "$PWD"

# Build program.
gcc -g -Wall -Wpedantic src/main.c src/Circle.c -L. src/oop/oop.a


## Compile *.c to *.o.
#for file in *.c; do
#
#  # Continue if file was not found.
#  [ -f "$file" ] || continue
#
#  # Do something.
#
#  gcc -c "$file" "$file.o"
#done