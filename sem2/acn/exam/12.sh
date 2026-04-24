read -p "Enter a number " num
f=1
for i in $(seq 1 $num)
do 
    f=$(($f * $i))
done
echo $f