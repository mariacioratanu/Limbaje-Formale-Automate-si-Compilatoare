#!/bin/bash
rm -f lex.yy.c parser.tab.c $1 
bison -d -Wcounterexamples parser.y 
lex tokenizer.l
g++ parser.h parser.tab.c lex.yy.c -std=c++11 -o $1 

