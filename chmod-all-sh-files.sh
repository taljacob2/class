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

  # "$f" without first 2 chars. (They are `./`).
  file=`echo "$f" | awk '{print substr($0,3)}'`
  fullPathOfFile="$ROOT_PATH/$file"

  # if "$f" is contained within "${EXCLUDED_DIRECTORIES[@]}"
  for excludedFileOrDirectory in "${EXCLUDED_DIRECTORIES[@]}"; do
      if echo "$file" | grep "^$excludedFileOrDirectory" ; then
          # TODO: debug
          echo "excluded file found: $file"
          continue
      fi
  done

  if [ -f "$file" ]; then

    # "$f" is a file.

    currentFileExtension="${file##*\.}"
    if [ "$currentFileExtension" == "sh" ]; then

      # TODO: debug
      echo "$file"
#      git update-index --chmod=+x "$f"
    fi

  fi
done

# Print progress bar.
printProgressBarOnceWithCalculatedPercentToPrint "$progressIndex" "$allFilesAndDirectoriesRecursivelySinceRootPathSize"
printf '\nCompleted Successfully!\n'

exit 0