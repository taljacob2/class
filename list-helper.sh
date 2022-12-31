#!/bin/bash

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
