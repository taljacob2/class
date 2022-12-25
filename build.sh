#!/bin/bash

# Build "Class.a".
#PWD=$(pwd)
#cd src/Class
#./build-library.sh
#cd "$PWD"

# Build program.
gcc -g -Wall -Wpedantic src/main.c src/ClassInheritor.c -L. src/Class/Class.a


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