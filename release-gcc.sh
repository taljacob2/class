#!/bin/bash

source ./config.sh

OOP_DIRECTORY="$GCC_DIRECTORY"/"$OUTPUT_LIB_FILE_NAME"

cleanupAndPrepareDirectory() {

    # Cleaup last release.
    rm -f -r "$OOP_DIRECTORY" > /dev/null 2>&1

    # Make sure there is an empty directory for the relaese.
    mkdir -p "$OOP_DIRECTORY"
}

copyHeaderFilesAndStaticLibrary() {
    cp "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME_64_BIT_CONST.a" "$OOP_DIRECTORY"
    cp "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME_32_BIT_CONST.a" "$OOP_DIRECTORY"
    cp "$OUTPUT_LIB_PATH"/"$OUTPUT_LIB_FILE_NAME.h" "$OOP_DIRECTORY"

    for f in "$OUTPUT_LIB_PATH"/* ; do
        if [ -d "$f" ]; then

            # "$f" is a directory. Will not run if no directories are available.

            directoryName=$(basename "$f")

            # Create that directory in "$OOP_DIRECTORY".
            mkdir -p "$OOP_DIRECTORY/$directoryName"

            # Copy all header files from the directory.
            cp "$f"/*.h "$OOP_DIRECTORY"/"$directoryName"
            cp "$f"/*.r "$OOP_DIRECTORY"/"$directoryName"
        fi
    done
}

archiveStaticLibrary() {
    local THIS_PATH=`pwd`

    cd "$GCC_DIRECTORY"
    tar -cf "$GCC_RELEASE_NAME" "$OUTPUT_LIB_FILE_NAME"
    cd "$THIS_PATH"
}

# ---------------------------------- Code --------------------------------------

echo releasing gcc...

cleanupAndPrepareDirectory

# Build the static library.
./build-lib.sh
./build-lib.sh 32

copyHeaderFilesAndStaticLibrary

# # Cleanup the static library build.
# ./cleanup.sh

archiveStaticLibrary

echo done.

exit