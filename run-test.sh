#!/bin/bash

source ./config.sh

## Run test program.
#"$TEST_PATH"/a.out

# Run test program with Valgrind.
valgrind --leak-check=full --show-leak-kinds=all "$TEST_PATH"/a.out
