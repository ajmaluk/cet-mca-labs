read -p "Enter a String : " str
read -p "Enter the Staring Index and num of char " a b
sub=${str:$a:$b}
echo "$sub"