#!/bin/bash

source ./config.sh

source ./progress-bar.sh

# --------------------------- Edit to you liking: ------------------------------

# Relative to `$ROOT_PATH`.
EXCLUDED_DIRECTORIES=(".git" ".github")

# ---------------------------------- Code --------------------------------------

cd "$ROOT_PATH"


allFilesAndDirectoriesRecursivelySinceRootPathAsOneLongString=$(find . -type f -print)

# Convert long string to string list.
allFilesAndDirectoriesRecursivelySinceRootPathAsListOfStrings=($allFilesAndDirectoriesRecursivelySinceRootPathAsOneLongString)
allFilesAndDirectoriesRecursivelySinceRootPathSize=${#allFilesAndDirectoriesRecursivelySinceRootPathAsListOfStrings[@]}

progressIndex=0
for f in "${allFilesAndDirectoriesRecursivelySinceRootPathAsListOfStrings[@]}"; do

  # Print progress bar.
  printProgressBarOnceWithCalculatedPercentToPrint "$progressIndex" "$allFilesAndDirectoriesRecursivelySinceRootPathSize"
  progressIndex=$((progressIndex + 1))

  fWithoutFirst2Chars=`echo "$f" | awk '{print substr($0,3)}'`
  fullPathOfFile="$ROOT_PATH/$fWithoutFirst2Chars"

  if [ -d "$f" ]; then

    # "$f" is a directory.

    # if "$f" is contained within "${EXCLUDED_DIRECTORIES[@]}"
    if printf '%s\0' "${EXCLUDED_DIRECTORIES[@]}" | grep -Fxqz -- "$f" ; then
      # TODO: debug
      echo "$f"
      continue
    fi

  elif [ -f "$fWithoutFirst2Chars" ]; then

    # "$f" is a file.

    currentFileExtension="${fWithoutFirst2Chars##*\.}"

    if [ "$currentFileExtension" == "sh" ]; then

      # TODO: debug
      echo "$fWithoutFirst2Chars"
#      git update-index --chmod=+x "$f"
    fi

  fi
done

# Print progress bar.
printProgressBarOnceWithCalculatedPercentToPrint "$progressIndex" "$allFilesAndDirectoriesRecursivelySinceRootPathSize"
printf '\nCompleted Successfully!\n'

exit 0