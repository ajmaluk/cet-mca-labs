#!/bin/bash
read -p "Enter name of database file: " db
[ ! -f "$db" ] && touch "$db"
while true; do
    echo -e "\n1. View Database\n2. View Specific Record\n3. Add Record\n4. Delete Record\n5. Exit"
    read -p "Choice: " ch
    case $ch in
        1) cat "$db" ;;
        2) read -p "Enter ID: " id; grep -i "$id" "$db" ;;
        3) read -p "ID: " tid; read -p "Name: " nm; read -p "Desig: " des; read -p "College: " col; echo "$tid $nm $des $col" >> "$db" ;;
        4) read -p "Enter ID to delete: " id; grep -v "$id" "$db" > dbs1; mv dbs1 "$db"; echo "Record deleted" ;;
        5) exit 0 ;;
        *) echo "Invalid" ;;
    esac
    read -p "Continue? (y/n): " i
    [ "$i" != "y" ] && exit 0
done
