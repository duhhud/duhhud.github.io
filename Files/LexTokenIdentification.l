kw int|float|char|void|if|else|main|while|do|break|continue
symbol[\:|\;|\(|\)|\=|\{|\}]
id [_]*[a-zA-Z_]+[0-9]*[a-zA-Z0-9_]*
digit[0-9]*
%{
#include<stdio.h>
%}
%%
{kw} printf("\nIts a keyword:%s",yytext);
{symbol} printf("\nits a symbol:%s",yytext);
{id} printf("\nIts a identifiers:%s",yytext);
{digit} printf("\nIts a digit:%s",yytext);
%%
int yywrap()
{
return 1;
}
int main()
{
char fn[30];
printf("enter a file name");
gets(fn);
yyin=fopen(fn,"r");
yylex();
getch();
}
