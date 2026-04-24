#!/bin/bash

read -p "Enter directory name you want to search : " dir
x=0
for filename in /Users/uk/Development/cet-mca-labs/sem2/"$dir"/*
do 
    x=$((x + 1))
done
echo $x




direct="/Users/uk/Development/cet-mca-labs/sem2/$dir"
if [ -d "$direct" ]
then 
    num=$(find "$direct" -maxdepth 1 -type f | wc -l)
    echo $num
else    
    echo "NO"
fi