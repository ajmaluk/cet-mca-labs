#!/bin/bash

read -p "Enter directory name you want to search : " dir
for filename in "/Users/uk/Development/cet-mca-labs/sem2/$dir"
do 
 if [ -d "$filename" ]
 then 
    echo "$filename in Directory"
else
    echo "No"
fi
done