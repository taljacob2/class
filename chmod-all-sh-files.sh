#!/bin/bash

source ./config.sh

cd "$ROOT_PATH"

# Relative to `$ROOT_PATH`.
EXCLUDED_DIRECTORIES=(".git" ".github")

for f in $(find . -type f -print); do
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
