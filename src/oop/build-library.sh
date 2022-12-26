#!/bin/bash

: '
Read more about creating a static library here:
https://youtu.be/P2vaRhWNilw
https://medium.com/@valentina.rua123/static-and-dynamic-library-in-c-fc4f168ae71d
https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html

Linking static libraries to other static libraries:
https://stackoverflow.com/a/27676016/14427765
'

LIBRARY_NAME="oop"

## Compile *.c to *.o.
#for file in *.c; do
#
#  # Continue if file was not found.
#  [ -f "$file" ] || continue
#
#  # Compile .c to .o.
#  gcc -c "$file" -o "$file.o"
#done

for f in *; do
    if [ -d "$f" ]; then

        # "$f" is a directory. Will not run if no directories are available.
        echo "$f"
        cd "$f"
        ./build-library.sh
        cd ..
    fi
done

# Remove last "$LIBRARY_NAME.a" if exists.
rm -f "$LIBRARY_NAME.a" > /dev/null 2>&1

## Collect all *.a to a library file.
ar crsT "$LIBRARY_NAME.a" Object/Object.a

#
## Remove *.o
#rm *.o