#!/bin/bash

source ./config.sh "$1"

cd "$OUTPUT_LIB_PATH"
./build-lib.sh "$1"
cd "$ROOT_PATH"
