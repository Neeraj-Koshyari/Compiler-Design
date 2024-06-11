//Problem Statement: Write a lex program to identify:- Keyword, Identifier, space, whitespace and characters from the given token

/*
  Steps to execute a lex program in terminal
  flex filename.l    //it will generate a .c with name lex.yy.c. Then compile this file
  gcc lex.yy.c      //an executable file will be generated
  ./a.out      //for linux,macOS
  a.exe    //for windows
*/

//Definations
%{
	#include<stdio.h>
%}

//RULES
%%
	[\t]	{printf("Tab pressed\n");}
	[ ]		{printf("Space pressed\n");}
	[\n]	{printf("New Line\n");}
	"int" | "float" | "char"	{printf("%s is a Keyword\n",yytext);}
	[a-zA-Z_#]+[a-zA-Z0-9_#]*	{printf("%s is a Identifier\n",yytext);}
	. {printf("%s is Character",yytext);}
%%

int main(){
	yylex();
}

int yywrap(){
	return 1;
}
