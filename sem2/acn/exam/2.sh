while true
do
    read -p "Enter a number : " a
    read -p "Enter a number : " b
    read -p "Enter operation : " op
    case $op in
        "+")
            ans=$(echo "$a+$b" | bc)
            ;;
        "-")
            ans=$(echo "$a-$b" | bc)
            ;;
        "*")
            ans=$(echo "$a*$b" | bc)
            ;;
        "/")
            if [ $b -eq 0 ]
            then 
                echo "Division 0 error"
                continue
            fi
            ans=$(echo "$a/$b" | bc)
            ;;
        "exit")
            echo "Exited"
            break
            ;;
        *)
            echo "Invalid Ops"
            continue
            ;;
        esac
        echo "$a $op $b = $ans"
done



