#!/bin/bash

source ./config.sh

source ./progress-bar.sh

# --------------------------- Edit to you liking: ------------------------------

# Relative to `$ROOT_PATH`.
EXCLUDED_WILDCARDS=(".git" ".github")

# ---------------------------------- Code --------------------------------------

contains () {
    sourceList="$1"
    valueToSearch="$2"

    for i in "${sourceList[@]}" ; do
        if [ "$i" == "$valueToSearch" ] ; then
            echo true
            return
        fi
    done

    echo false
    return
}

deleteSmallListFromLargeList () {
    largeList="$1"
    smallList="$2"

    index=0
    for element in "${largeList[@]}" ; do
        if [ $(contains "${smallList[@]}" "$element") == true ] ; then
            unset largeList[$index]
        fi
        ((index++))
    done

    echo "${largeList[@]}"
}


EXCLUDED_WILDCARDS=(".git" ".github" "*.bash")


# find `pwd` -type f -print

ROOT_PATH=`pwd`

# find `pwd` -type f -print -not -name "$EXCLUDED_WILDCARDS"
# find `pwd` -type f -not -wholename "*.zip"

# Set excludedFiles
excludedFiles=()
for wildCard in "${EXCLUDED_WILDCARDS[@]}" ; do
    excludedFiles+=($(find "$ROOT_PATH" -type f -wholename "$ROOT_PATH/$wildCard"))
done

# Add all files.
allFiles=$(find "$ROOT_PATH" -type f)

# Set includedFiles
includedFiles=$(deleteSmallListFromLargeList "${allFiles[@]}" "${excludedFiles[@]}")

unset allFiles
unset excludedFiles

# For debugs
# printf 'includedFiles = %s\n' ${includedFiles[@]}

exit 0

# --------------------------------------------------------------------------

cd "$ROOT_PATH"


allFilesAndDirectoriesRecursivelySinceRootPathAsOneLongString=$(find "$ROOT_PATH" -type f -print)

# Convert long string to string list.
allFilesAndDirectoriesRecursivelySinceRootPathAsListOfStrings=($allFilesAndDirectoriesRecursivelySinceRootPathAsOneLongString)
allFilesAndDirectoriesRecursivelySinceRootPathSize=${#allFilesAndDirectoriesRecursivelySinceRootPathAsListOfStrings[@]}

progressIndex=0
for f in "${allFilesAndDirectoriesRecursivelySinceRootPathAsListOfStrings[@]}"; do

  # Print progress bar.
  printProgressBarOnceWithCalculatedPercentToPrint "$progressIndex" "$allFilesAndDirectoriesRecursivelySinceRootPathSize"
  ((progressIndex++))

  # "$f" without first 2 chars. (They are `./`).
  file=`echo "$f" | awk '{print substr($0,3)}'`
  fullPathOfFile="$ROOT_PATH/$file"

  # if "$f" is contained within "${EXCLUDED_WILDCARDS[@]}"
  for excludedFileOrDirectory in "${EXCLUDED_WILDCARDS[@]}"; do
      if echo "$file" | grep "^$excludedFileOrDirectory$" ; then
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