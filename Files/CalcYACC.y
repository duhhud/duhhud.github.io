%{
#include<stdio.h>
int regs[26];
int base;
%}
%token DIGIT LETTER
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS
%%
list:
|list S'\n'
;
S: expr {printf("%d\n",$1);}
  |LETTER '=' expr {printf("%d\n",$3);}
   ;
expr : '(' expr ')' {$$ = $2;}
        |expr '*' expr {$$ = $1*$3;}
        |expr '/' expr {$$ = $1/$3;}
        |expr '%' expr {$$ = $1%$3;}
        |expr '+' expr {$$ = $1+$3;}
        |expr '-' expr {$$ = $1-$3;}
        |expr '&' expr {$$ = $1&$3;}
        |expr '|' expr {$$ = $1|$3;}
        |'-' expr%prec UMINUS {$$ = -$2;}
        |NUMBER
        ;
NUMBER : DIGIT{$$=$1;base=($1==0)?8:10;}
    |NUMBER DIGIT {$$ = base*$1+$2;}
;
%%
yylex(){
int c;
extern int yylval;
c = getchar();
if(isdigit(c)){yylval=c-'0';
return DIGIT;}
if(isalpha(c)){yylval=c-'a';
return LETTER;}
return c;
}
main(){
return(yyparse());
}
yyerror(s)
char *s;{
printf("%s\n",s);}
yywrap(){
return 1;
}