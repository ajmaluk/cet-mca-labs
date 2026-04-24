read -p "Enter Number to Reverse" num
r=0
while [ $num -gt 0 ]
do
    ld=$((num%10))
    r=$(((r*10)+ld))
    num=$(($num / 10))
done
echo $r