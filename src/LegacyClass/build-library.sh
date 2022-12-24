#!/bin/bash

LIBRARY_NAME="LegacyClass"

# Compile *.c to *.o.
for file in *.c; do

  # Continue if file was not found.
  [ -f "$file" ] || continue

  # Compile .c to .o.
  gcc -c "$file" -o "$file.o"
done

# Collect all *.o to a library file.
ar rcs "$LIBRARY_NAME.a" *.o

# Remove *.o
rm *.o