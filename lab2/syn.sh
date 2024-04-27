#! /bin/bash
flex lexical.l
bison -d -v syntax.y
gcc -o parser syntax.tab.c  main.c tree.c -lfl