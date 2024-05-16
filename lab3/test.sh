#!/bin/bash
path="./test/"
files=$(ls $path)

for filename in $files
do
   ./parser $path$filename $filename.ir
done