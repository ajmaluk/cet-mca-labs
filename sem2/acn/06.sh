#!/bin/bash
read -p "Enter directory name you want to search: " dir
# Adjusted to be relative or absolute based on user input, removing hardcoded Windows paths
for filename in "$dir"
do
    if [ -d "$filename" ]
    then
        echo "$filename is a directory"
    else
        echo "$filename is not directory"
    fi
done
