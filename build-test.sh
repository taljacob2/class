#!/bin/bash

source ./config.sh

# Build test program.
gcc -g -Wall -Wpedantic \
"$TEST_PATH"/main.c \
-L. "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME.a" \
-o "$TEST_PATH"/a.out
