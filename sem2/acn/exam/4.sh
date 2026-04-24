#!/bin/bash

if [ $# -eq 1 ]
then 
    if [ -f $1 ]
    then 
        echo "Reverse of $1"
        cat $1
        echo "-----"
        tail -r "$1"
    else    
        echo "Does Not Exists!"
    fi
else    
    echo "Enter Correct Path"
fi