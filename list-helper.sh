#!/bin/bash

source ./progress-bar.sh

contains () {
  declare -a sourceList=("${@:2:$1}"); shift "$(($1 + 1))"
  declare -a valueToSearch="$1"

  for element in "${sourceList[@]}" ; do
    if [ "$element" == "$valueToSearch" ] ; then
      true
      return
    fi
  done

  false
  return
}

deleteSmallListFromLargeList () {
  declare -a progressBarMessage="$1"; shift
  declare -a largeList=("${@:2:$1}"); shift "$(($1 + 1))"
  declare -a smallList=("${@:2:$1}"); shift "$(($1 + 1))"

  declare -a index=0
  for element in "${largeList[@]}" ; do

    # Print progress bar.
    printProgressBarOnceWithCalculatedPercentToPrint \
    "$progressBarMessage" "$index" "${#largeList[@]}" >&2

    if contains "${#smallList[@]}" "${smallList[@]}" "$element" ; then
      unset largeList[$index]
    fi

    ((index++))
  done

  # Print progress bar.
  printProgressBarOnceWithCalculatedPercentToPrint \
  "$progressBarMessage" "$index" "${#largeList[@]}" >&2
  unset index

  echo "${largeList[@]}"
}
