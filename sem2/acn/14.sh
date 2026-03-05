#!/bin/bash
read -p "Enter no:of terms: " n
a=0
b=1
for i in $(seq 1 $n)
do
    echo $a
    c=$((a + b))
    a=$b
    b=$c
done
