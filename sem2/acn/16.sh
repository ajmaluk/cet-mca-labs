#!/bin/bash
while true; do
    echo "--- File Handling-1 Menu ---"
    echo "1. Input profile and copy to another file"
    echo "2. Start printing file from certain line"
    echo "3. Print differences between two files"
    echo "4. Print lines matching pattern"
    echo "5. Exit"
    read -p "Select option: " opt
    case $opt in
        1)
            read -p "Enter a file name: " file1
            echo "Enter contents (Ctrl+D to save): "
            cat > "$file1"
            read -p "Enter destination file name: " file2
            cp "$file1" "$file2"
            echo "Contents of $file2:"
            cat "$file2" ;;
        2)
            read -p "Enter file name: " file1
            read -p "Enter line number: " l
            tail -n +"$l" "$file1" ;;
        3)
            read -p "Enter file1: " file1
            read -p "Enter file2: " file2
            read -p "Enter output file: " file3
            diff -a "$file1" "$file2" > "$file3"
            cat "$file3" ;;
        4)
            read -p "Enter file name: " file1
            read -p "Enter pattern: " s
            grep -ni "$s" "$file1" ;;
        5) exit 0 ;;
        *) echo "Invalid option" ;;
    esac
done
