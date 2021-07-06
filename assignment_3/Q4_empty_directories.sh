#!/bin/sh

#command to list empty directories
empty_dir=$(find . -type d -empty)
echo $empty_dir
count=`wc -l <<< $empty_dir`
echo "No of empty directories: $count"

#stat -f "%N%B" prints the epoch time the directory was created
find . -type d -empty | xargs stat -f "%N %B"
