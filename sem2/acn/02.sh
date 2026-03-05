#!/bin/bash
while true
do
    read -p "Enter 2 numbers: " a b
    read -p "Enter the operator (+, -, *, /) or 'exit' to quit: " op
    if [ "$op" == "exit" ]; then
        exit 0
    fi
    case $op in
        "+")
            ans=$(echo "$a + $b" | bc);;
        "-")
            ans=$(echo "$a - $b" | bc);;
        "*")
            ans=$(echo "$a * $b" | bc);;
        "/")
            ans=$(echo "scale=2; $a / $b" | bc);;
        *)
            echo "Invalid operator"; continue;;
    esac
    echo "$a $op $b = $ans"
done