#!/bin/bash

## Run main program.
#./src/main/a.out

# Run main program with Valgrind.
valgrind --leak-check=full --show-leak-kinds=all ./src/main/a.out
