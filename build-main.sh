#!/bin/bash

source ./config.sh

# Build main program.
gcc -g -Wall \
"$MAIN_PATH"/main.c \
"$MAIN_PATH"/Circle.c \
"$MAIN_PATH"/CircleV2.c \
"$MAIN_PATH"/CircleV4.c \
"$MAIN_PATH"/CircleV5.c \
-L. "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME.a" \
-o "$MAIN_PATH"/a.out
