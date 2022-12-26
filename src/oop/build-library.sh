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

staticLibraryList=()

for f in *; do
    if [ -d "$f" ]; then

        # "$f" is a directory. Will not run if no directories are available.
        cd "$f"
        ./build-library.sh  # Build the static library.

        # Add paths of all static libraries to the list.
        for staticLibraryName in *.a; do
          if [ -f "$staticLibraryName" ]; then

            ## TODO: DEBUG
            echo "$staticLibraryName"
            staticLibraryList+=("$f/$staticLibraryName")
          fi
        done

        cd ..
    fi
done

# Remove last "$LIBRARY_NAME.a" if exists.
rm -f "$LIBRARY_NAME.a" > /dev/null 2>&1

## Collect all *.a to a library file.
ar crsT "$LIBRARY_NAME.a" "${staticLibraryList[@]}"

## TODO: DEBUG
printf '%s\0' "${staticLibraryList[@]}"

#
## Remove *.o
#rm *.o

# free
unset staticLibraryList
