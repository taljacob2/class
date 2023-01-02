#!/bin/bash

source ./config.sh

cd "$OUTPUT_LIB_PATH"
./build-lib.sh
cd "$ROOT_PATH"
