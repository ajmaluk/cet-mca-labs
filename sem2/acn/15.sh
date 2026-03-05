#!/bin/bash
read -p "Enter a string: " s
l=${#s}
ns=""
for i in $(seq $l -1 1)
do
    # Using substring expansion instead of expr for better compatibility and efficiency
    a=${s:i-1:1}
    ns="$ns$a"
done
echo "Reversed string: $ns"
