%{
#include<stdio.h>
%}
%token TL
%token TD
%%
list:
|list s '\n'{printf("\nAccepted....\n");}
;
s:TL
 |s TL
 |s TD
 ;
%%
main()
{
return(yyparse());
}
yyerror(s)
char *s;
{
printf("%s\n",s);
getch();
}
int yylex()
{
int c;
while((c=getchar())==' ')
;
if(isalpha(c))return(TL);
if(isdigit(c))return(TD);
return(c);
}
yywrap()
{
return(1);
}