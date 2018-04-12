%{
#include<stdio.h>
int regs[26];
int base;
%}
%token DIGIT LETTER
%left '+''-'
%%
list:
|list s '\n'
;
s:
expr {printf("string accepted");}
|
LETTER'='expr{printf("Assignment Statement accepted");}
;
expr:'('expr')'{$$=$2;}
|expr'+'expr{$$=$1+$2;}
|expr'-'expr{$$=$1-$2;}
|NUMBER
|LETTER
;
NUMBER:DIGIT{$$=$1;base=10;}
|NUMBER DIGIT{$$=10*$1+$2;}
;
%%
yylex()
{
int c;
extern int yylval;
c=getchar();
if(isdigit(c))
{
yylval=c-'0';
return DIGIT;
}
if(isalpha(c))
{
yylval=c-'a';
return LETTER;
}
return c;
}
main()
{
return(yyparse());
}

yyerror(s)
char *s;
{
printf("\n%s",s);
getch();
}
yywrap()
{
return 1;
}