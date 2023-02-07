#!/bin/bash

ROOT_PATH=`pwd`

SRC_PATH="$ROOT_PATH"/src
MAIN_PATH="$SRC_PATH"/main
TEST_PATH="$SRC_PATH"/test
LIB_PATH="$SRC_PATH"/lib
OUTPUT_LIB_PATH="$LIB_PATH"/oop

OUTPUT_LIB_FILE_NAME_64_BIT_CONST=oop
OUTPUT_LIB_FILE_NAME_32_BIT_CONST=oop32
GCC_OPTIONS_64_BIT_CONST="-m64"
GCC_OPTIONS_32_BIT_CONST="-m32"

# Default is 64 bit. Thus, set `$BITS` value to `64` by default.
BITS=${1:-64}

OUTPUT_LIB_FILE_NAME="$OUTPUT_LIB_FILE_NAME_64_BIT_CONST"
GCC_OPTIONS="$GCC_OPTIONS_64_BIT_CONST"

if [ "$BITS" == 32 ]; then

  OUTPUT_LIB_FILE_NAME="$OUTPUT_LIB_FILE_NAME_32_BIT_CONST"
  GCC_OPTIONS="$GCC_OPTIONS_32_BIT_CONST"

fi

GCC_DIRECTORY=release/gcc
GCC_RELEASE_NAME="$OUTPUT_LIB_FILE_NAME-gcc.tar.gz"
GCC_RELEASE_PATH="$GCC_DIRECTORY"/"$GCC_RELEASE_NAME"

# --------- START: Edit to you liking ---------

RUN_WITH_VALGRIND=true
VALGRIND_OPTIONS="--leak-check=full --show-leak-kinds=all"

# --------- END: Edit to you liking -----------
