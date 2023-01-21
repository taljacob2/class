#!/bin/bash

source ./config.sh

echo releasing gcc...

OOP_DIRECTORY=release/gcc/"$OUTPUT_LIB_FILE_NAME"

rm -f -r "$OOP_DIRECTORY"

mkdir -p "$OOP_DIRECTORY"

./build-lib.sh

cp "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME.a" "$OOP_DIRECTORY"
cp "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME.h" "$OOP_DIRECTORY"

cp "$OUTPUT_LIB_PATH"/**/*.c "$OOP_DIRECTORY"
cp "$OUTPUT_LIB_PATH"/**/*.h "$OOP_DIRECTORY"
cp "$OUTPUT_LIB_PATH"/**/*.r "$OOP_DIRECTORY"


exit  # This line is mandatory for executing this file as a thread.
