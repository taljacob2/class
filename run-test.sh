#!/bin/bash

## Run test program.
#./src/test/a.out

# Run test program with Valgrind.
valgrind --leak-check=full --show-leak-kinds=all ./src/test/a.out
