#!/bin/bash
path="./test/"
files=$(ls $path)
if [ -f test.txt ]; then
    rm test.txt
fi
for filename in $files
do
   echo -e "\n"$filename >> test.txt
   ./parser $path$filename >> test.txt
done