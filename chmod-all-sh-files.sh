#!/bin/bash

source ./config.sh

source ./progress-bar.sh

source ./list-helper.sh

# --------------------------- Edit to you liking: ------------------------------

# Relative to `$ROOT_PATH`.
EXCLUDED_WILDCARDS=(".git" ".github")

# ---------------------------------- Code --------------------------------------

cd "$ROOT_PATH"

# Set `excludedFiles`.
excludedFiles=()
for wildCard in "${EXCLUDED_WILDCARDS[@]}" ; do
    excludedFiles+=($(find "$wildCard" -type f))
done

# Add all files.
allFiles=($(find -type f))

index=0
for f in "${allFiles[@]}"; do

  # Print progress bar.
  printProgressBarOnceWithCalculatedPercentToPrint \
  "(1/3): Scanning all files... " "$index" "${#allFiles[@]}"

  # "$f" without first 2 chars. (They are `./`).
  file=`echo "$f" | awk '{print substr($0,3)}'`
  allFiles[$index]="$file"
  ((index++))
done

# Print progress bar.
printProgressBarOnceWithCalculatedPercentToPrint \
"(1/3): Scanning all files... " "$index" "${#allFiles[@]}"
unset index

# Set `includedFiles`.
includedFiles=($(deleteSmallListFromLargeList \
"(2/3): Removing excluded files... " \
"${#allFiles[@]}" "${allFiles[@]}" \
"${#excludedFiles[@]}" "${excludedFiles[@]}"))

unset allFiles
unset excludedFiles

# For debugs
printf 'includedFiles = %s\n' "${includedFiles[@]}"

# ------------------------------------------------------------------------------

index=0
for file in "${includedFiles[@]}"; do

  # TODO: debug
#  echo "$file"

  # Print progress bar.
  printProgressBarOnceWithCalculatedPercentToPrint \
  "(3/3): Iterating over .sh files... " "$index" ${#includedFiles[@]}

  # If "$file" is a file.
  if [ -f "$file" ]; then
    currentFileExtension="${file##*\.}"
    if [ "$currentFileExtension" == "sh" ]; then

      # TODO: debug
      echo "$file"
#      echo
#      git update-index --chmod=+x "$f"
    fi

  fi

  ((index++))
done

# Print progress bar.
printProgressBarOnceWithCalculatedPercentToPrint \
"(3/3): Iterating over .sh files... " "$index" ${#includedFiles[@]}
unset index
printf '\nCompleted Successfully!\n'

exit 0