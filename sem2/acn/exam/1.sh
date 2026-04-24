read -p "Enter 3 Numbers" a b c
if [ $a -gt $b ] && [ $a -gt $c ]
then
    echo $a "is Greater"
elif [ $b -gt $c ]
then 
    echo $b "is Greater"
else
    echo $c "is Greater"
fi