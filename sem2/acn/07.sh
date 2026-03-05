#!/bin/bash
read -p "Enter directory name you want to search: " dir
direct="$dir"
if [ -d "$direct" ]
then
    num_files=$(find "$direct" -maxdepth 1 -type f | wc -l)
    echo "There are $num_files files in $direct"
else
    echo "$direct is not a directory"
fi