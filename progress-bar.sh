#!/bin/bash

# See https://stackoverflow.com/a/68298090/14427765

progressBar()  {
    local prct totlen=$((8*$2)) lastchar barstring blankstring;
    printf -v prct %.2f "$1"
    ((prct=10#${prct/.}*totlen/10000, prct%8)) &&
        printf -v lastchar '\\U258%X' $(( 16 - prct%8 )) ||
            lastchar=''
    printf -v barstring '%*s' $((prct/8)) ''
    printf -v barstring '%b' "${barstring// /\\U2588}$lastchar"
    printf -v blankstring '%*s' $(((totlen-prct)/8)) ''
    printf -v "$3" '%s%s' "$barstring" "$blankstring"
}

: '
Description:
Prints a progress bar to the screen, with the specific percent you wish to
print.

Parameters:
$1: title:          Title message for the progress bar.
$2: percentToPrint: A string that represents a number (could be in float). The
                    percent you wish the bar to print.

Example of use:
```
printProgressBarOnce "Progress: " "0"
printProgressBarOnce "Progress: " "1.12"
printProgressBarOnce "Progress: " "13.34423"
printProgressBarOnce "Progress: " "23.323"
printProgressBarOnce "Progress: " "39"
printProgressBarOnce "Progress: " "40.12"
printProgressBarOnce "Progress: " "43.1"
printProgressBarOnce "Progress: " "55.12345"
# ...
printProgressBarOnce "100"
printf '\nCompleted Successfully!\n'
```
'
printProgressBarOnce() {
  title="$1"
  percentToPrint="$2"

  barWidth=40
  printf '\n\n\n\n\n\n\n\n\e[8A\e7'
  progressBar "$percentToPrint" $barWidth bar;
  printf '%s\e[48;5;23;38;5;41m%s\e[0m%6.2f%%%b' \
  "$title" "$bar" "$percentToPrint" " "
}

: '
Description:
Prints a progress bar to the screen, that calculates for you the percent
(with float representation) of the progress made.

Parameters:
$1: title: Title message for the progress bar.
$2: index: The iterating index over an array.
$3: size:  The size of the array that we are iterating over.

Requirements:
Install `bc`. (It calculates the progress as a float number).

Example of use:
```
size=10
for ((i=0; i < $size; i+=1)); do
    printProgressBarOnceWithCalculatedPercentToPrint "Progress: " $i $size
done
printProgressBarOnceWithCalculatedPercentToPrint "Progress: " $i $size
printf '\nCompleted Successfully!\n'
```
'
printProgressBarOnceWithCalculatedPercentToPrint() {
  title="$1"
  index="$2"
  size="$3"

  percentToPrint=$(bc -l <<< "100 * $index/$size")
  printProgressBarOnce "$title" "$percentToPrint" > /dev/tty
}
