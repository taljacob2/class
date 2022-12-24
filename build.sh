#!/bin/bash

# Build "LegacyClass.a".
#PWD=$(pwd)
#cd src/LegacyClass
#./build-library.sh
#cd "$PWD"

# Build program.
gcc -g -Wall -Wpedantic src/main.c -L. src/LegacyClass/LegacyClass.a


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