#!/bin/bash
path="./test/"
files=$(ls $path)
if [ -f test.txt ]; then
    rm test.txt
fi
for filename in $files
do
   ./parser $path$filename $filename.ir
done