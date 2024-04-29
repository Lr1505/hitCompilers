cmake_minimum_required(VERSION 3.28)
project(C__complier)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__complier
        lab1/lex.yy.c
        lab1/lexical.l
        lab1/main.c
        lab1/tree.c
        lab2/hash.c
        lab2/symtab.c
        lab2/tree.h
        lab2/semantic.c)
