%{
    #include <stdio.h>
    #include "parser.tab.h"
%}

%option noyywrap

alpha [a-zA-Z]
digit [0-9]
nonzerodigit [1-9]

%%

"Methods:" 				{return FUNCS;}
"Constructs:" 				{return CONSTRUCTS;}
"Vars:" 				{return VARS;}
"TypeOf" 				{return TYPEOF;}
"Eval" 					{return EVAL;}
"int"|"float"|"char"|"string"|"bool" 	{yylval.string=strdup(yytext);return TYPE;}
"class" 				{yylval.string=strdup(yytext); return CLASS;}
"ENTRY" 				{return ENTRY;}
"EXIT" 					{return EXIT;}
"USRDEF" 				{return USRDEF;}
"GLOBALVAR" 				{return GLOBALVAR;}
"GLOBALFUNC" 				{return GLOBALFUNC;}
"main" 					{return MAIN;}
"fn" 					{return FNENTRY;}
"return" 				{return RETURN;}
"if" 					{return IF;}
"else" 					{return ELSE;}
"while" 				{return WHILE;}
"for" 					{return FOR;}
"switch" 				{return SWITCH;}
"case" 					{return CASE;}
"default" 				{return DEFAULT;}
"and" 					{return AND;}
"or" 					{return OR;}
"not" 					{return NOT;}
"true" 					{yylval.boolean=1; return BOOL;}
"false" 				{yylval.boolean=0; return BOOL;}
"<" 					{return LT;}
">" 					{return GT;}
">=" 					{return GEQ;}
"<=" 					{return LEQ;}
"==" 					{return EQ;}
"!=" 					{return NEQ;}
"break" 				{return BREAK;}
"print" 				{return PRINT;}
"const" 				{return CONST;}
{alpha}({alpha}|{digit})*  		{yylval.string=strdup(yytext); return ID;}
{nonzerodigit}{digit}*|0		{yylval.integer=atoi(yytext); return INT;}
({nonzerodigit}{digit}*|0)\.{digit}+ 	{yylval.floatnum=atof(yytext); return FLOAT;}
\"[^"]*\" 				{yytext=yytext+1; yytext[strlen(yytext)-1]='\0'; yylval.string=strdup(yytext); return STRING;}
\'[^']\' 				{yylval.character=yytext[1]; return CHAR;}
[ \t] 					;
(\r|\n|\r\n) 				{yylineno++;}
. 					{return yytext[0];}

%%
