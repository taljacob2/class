#!/bin/bash

source ./config.sh

echo releasing gcc...

OOP_DIRECTORY=release/gcc/"$OUTPUT_LIB_FILE_NAME"

rm -f -r "$OOP_DIRECTORY"

mkdir -p "$OOP_DIRECTORY"

./build-lib.sh

cp "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME.a" "$OOP_DIRECTORY"
cp "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME.h" "$OOP_DIRECTORY"


for f in "$OUTPUT_LIB_PATH"/* ; do
    if [ -d "$f" ]; then
        directoryName=$(basename "$f")      

        # "$f" is a directory. Will not run if no directories are available.

        # Create that directory in "$OOP_DIRECTORY".
        mkdir -p "$OOP_DIRECTORY/$directoryName"

        # Copy all header files from the directory.
        cp "$f"/*.h "$OOP_DIRECTORY"/"$directoryName"
        cp "$f"/*.r "$OOP_DIRECTORY"/"$directoryName"
    fi
done


exit  # This line is mandatory for executing this file as a thread.
