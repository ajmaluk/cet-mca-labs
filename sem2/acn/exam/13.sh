str="Ajmal"
rev=""
for((i=${#str}-1; i>=0; i--))
do
    rev+="${str:i:1}"
done
echo "$rev"

