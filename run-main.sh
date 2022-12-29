#!/bin/bash

source ./config.sh

if [ "$RUN_WITH_VALGRIND" == true ]; then

  # Run program with Valgrind.
  valgrind "$VALGRIND_OPTIONS" "$MAIN_PATH"/a.out

  else

  # Run program normally.
  "$MAIN_PATH"/a.out

fi
