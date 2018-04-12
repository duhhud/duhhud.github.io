%
{
#include<stdio.h>
%
}
%token TA TB
%start E
%%
E :
   |ES '\n'{printf("Accepted....\n");}
   ;
S  :TA S
   | TB
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
}
int yylex()
{
int c;
while((c=getchar())=='')
;
if(c='a')return(TA);
if(c=='b')return(TB);
return(c);
}
yywrap()
{
return(1);
}
