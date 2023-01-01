#!/bin/bash

contains () {
    sourceList="$1"
    valueToSearch="$2"

    for element in "${sourceList[@]}" ; do

        # TODO: DEBUG
        echo "$element"

      if [ "$element" == "$valueToSearch" ] ; then

        # TODO: DEBUG
        echo "$element"

        echo true
        return
      fi
    done

    echo false
    return
}

deleteSmallListFromLargeList () {
#  # TODO: debug
#    printf '%s\n' "$1"
#
    declare -a largeList=("${@:2:$1}"); shift "$(($1 + 1))"
    declare -a smallList=("${@:2:$1}"); shift "$(($1 + 1))"

    # TODO: debug
    printf '$s\n' "${largeList[@]}"
#
#    index=0
#    for element in "${largeList[@]}" ; do
#
#        # TODO: DEBUG
#        echo "$element"
#
#      if [ "$(contains ${smallList[@]} $element)" == "true" ] ; then
##        # TODO: DEBUG
##        echo "$element"
#        unset largeList[$index]
#      fi
#
#    ((index++))
#    done
#
#    echo "${largeList[@]}"
}
