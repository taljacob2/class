#!/bin/bash

source ./config.sh

rm -f -r "$OUTPUT_LIB_PATH"/*.o
rm -f -r "$OUTPUT_LIB_PATH"/*.a
rm -f -r "$OUTPUT_LIB_PATH"/*/*.o
rm -f -r "$OUTPUT_LIB_PATH"/*/*.a

rm -f "$MAIN_PATH"/a.out
rm -f "$TEST_PATH"/a.out
