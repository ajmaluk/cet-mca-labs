#!/bin/bash
# 1. Create myfile with table
echo "1001 RAM 97" > myfile
echo "1002 NEHA 89" >> myfile
echo "1010 DIVYA 77" >> myfile
echo "1025 RAHUL 65" >> myfile
echo "1012 ARUN 99" >> myfile
echo "1013 NISHA 76" >> myfile

echo "2. First 2 rows:"
head -n 2 myfile

echo -e "\n3. Last 2 rows:"
tail -n 2 myfile

echo -e "\n4. Copying to mycopyfile..."
cp myfile mycopyfile

echo -e "\n5. Counts (lines words chars):"
wc myfile

echo -e "\n6. 3rd row only:"
sed -n '3p' myfile

echo -e "\n7. Appending to myappendfile..."
cat myfile >> myappendfile
echo "Done."
