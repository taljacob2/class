#!/bin/bash

source ./../../../config.sh $1

: '
Read more about creating a static library here:
https://youtu.be/P2vaRhWNilw
https://medium.com/@valentina.rua123/static-and-dynamic-library-in-c-fc4f168ae71d
https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html

Linking static libraries to other static libraries:
https://stackoverflow.com/a/27676016/14427765
'

LIBRARY_NAME="$OUTPUT_LIB_FILE_NAME"

staticLibraryList=()

for f in *; do
    if [ -d "$f" ]; then

        # "$f" is a directory. Will not run if no directories are available.
        cd "$f"
        ./build-lib.sh $1 # Build the static library.

        # Add paths of all static libraries to the list.
        for staticLibraryName in *.a; do
          if [ -f "$staticLibraryName" ]; then
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

# free
unset staticLibraryList
