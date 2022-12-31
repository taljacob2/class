#!/bin/bash

source ./config.sh

source ./progress-bar.sh

source ./list-helper.sh

# --------------------------- Edit to you liking: ------------------------------

# Relative to `$ROOT_PATH`.
EXCLUDED_WILDCARDS=(".git" ".github")

# ---------------------------------- Code --------------------------------------

# Set `excludedFiles`.
excludedFiles=()
for wildCard in "${EXCLUDED_WILDCARDS[@]}" ; do
    excludedFiles+=($(find "$ROOT_PATH" -type f -wholename "$ROOT_PATH/$wildCard"))
done

# Add all files.
allFiles=$(find "$ROOT_PATH" -type f)

# Set `includedFiles`.
includedFiles=$(deleteSmallListFromLargeList "${allFiles[@]}" "${excludedFiles[@]}")

unset allFiles
unset excludedFiles

# For debugs
# printf 'includedFiles = %s\n' ${includedFiles[@]}

# ------------------------------------------------------------------------------

includedFilesSize=${#includedFiles[@]}

index=0
for file in "${includedFiles[@]}"; do

  # Print progress bar.
  printProgressBarOnceWithCalculatedPercentToPrint "$index" "$includedFilesSize"

  # If "$file" is a file.
  if [ -f "$file" ]; then
    currentFileExtension="${file##*\.}"
    if [ "$currentFileExtension" == "sh" ]; then

      # TODO: debug
      echo "$file"
#      git update-index --chmod=+x "$f"
    fi

  fi

  ((index++))
done

# Print progress bar.
printProgressBarOnceWithCalculatedPercentToPrint "$index" "$includedFilesSize"
printf '\nCompleted Successfully!\n'

exit 0