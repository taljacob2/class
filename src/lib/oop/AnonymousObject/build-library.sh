#!/bin/bash

: '
Read more about creating a static library here:
https://youtu.be/P2vaRhWNilw
https://medium.com/@valentina.rua123/static-and-dynamic-library-in-c-fc4f168ae71d
https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html

Linking static libraries to other static libraries:
https://stackoverflow.com/a/27676016/14427765
'

LIBRARY_NAME="AnonymousObject"

# Compile *.c to *.o.
for file in *.c; do

  # Continue if file was not found.
  [ -f "$file" ] || continue

  # Compile .c to .o.
  gcc -c "$file" -o "$file.o"
done

# Collect all *.o to a library file.
ar rcs "$LIBRARY_NAME.a" *.o > /dev/null 2>&1

# Remove *.o
rm -f *.o  > /dev/null 2>&1
