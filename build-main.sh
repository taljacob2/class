#!/bin/bash

source ./config.sh

# Build main program.
gcc -g -Wall -Wextra -Wpedantic -std=c99 \
"$MAIN_PATH"/main.c \
"$MAIN_PATH"/Circle.c \
"$MAIN_PATH"/CircleV2.c \
"$MAIN_PATH"/CircleV4.c \
"$MAIN_PATH"/CircleV5.c \
"$MAIN_PATH"/CircleV6.c \
"$MAIN_PATH"/CircleV7.c \
"$MAIN_PATH"/CircleV8.c \
-L. "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME.a" \
-o "$MAIN_PATH"/a.out
