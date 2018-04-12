%{
int t=-1;
%}
%token TA TD
%right '-' '+'
%right '*' '/'
%%
list : list expr '\n'
     |
     ;
expr:expr expr '+' {t++;
	if(isalpha($1)&&isalpha($2)){printf("\n%d%c%c%c",t,$2,$1,'+');$$=t;}
	else {printf("\n%d%c%d%c",t,$1,t-1,'+');$$=t;}
}
|expr expr '-'{t++;
	if(isalpha($1)&&isalpha($2)){printf("\n%d%c%c%c",t,$2,$1,'-');$$=t;}
	else{printf("\n%d%c%d%c",t,$1,t-1,'-');$$=t;}
}
|expr expr '*'{t++;
	if(isalpha($1)&&isalpha($2)){printf("\n%d%c%c%c",t,$2,$1,'*');$$=t;}
	else{printf("\nboth digit%d%d%d%c",t,$2,$1,'*');$$=t;}
	if(isdigit($1)|isdigit($2)){printf("\n none digit%d%c%d%c",t,$1,t-1,'*');$$=t;}
}
|expr expr '='{t++;
	if(isalpha($1)&&isalpha($2)){printf("\nxx%d%c%c%c",t,$2,$1,'=');$$=t;}
	else{printf("\n%d%c%d%c",t,$1,t-1,'=');$$=t;}
}
|TA
|TD
;
%%
int main()
{
yyparse();
return 0;
}
yyerror()
{
printf("\n error on line no");
}
int yylex()
{
int c;
extern int yylval;
c=getchar();
if(isalpha(c)){yylval=c; return TA;}
if(isdigit(c)){yylval=c-'0';return TD;}
return c;
}
int yywrap()
{
return 1;
}