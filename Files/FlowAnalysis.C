#include<stdio.h>
#include<conio.h>
struct stmt
{
int no;
char st[20];
}
s[20];
struct smt
{
char id[10];
int d[10];
int u[10];
int symd;
int symu;
}sym[10];
void main()
{
int i,j=0,jj=0,bj=0,sj=-1,n,k=0,b[20];
char *tok;
printf("enter the number of statements");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&s[i].no);
gets(s[i].st);
}
for(i=0;i<20;i++)
b[i]=0;
b[0]=1;
for(i=0;i<n;i++)
{
tok=strtok(s[i].st,"=(");
if(strcmp(tok,"if")==0)
{
b[i+1]=1;
tok=strtok(NULL,")");
tok=tok+6;
b[atoi(tok)-1]=1;
}
else
if(strcmp(tok,"goto")==0)
{
b[i+1]=1;
tok=tok+5;
b[atoi(tok)-1]=1;
}
else
{
if(sj==-1)
{
sj++;
strcpy(sym[sj].id,tok);
sym[sj].symd=-1;
sym[sj].symu=-1;
}
for(j=0;j<=sj;j++)
{
if(strcmp(sym[j].id,tok)==0)
{
sym[j].symd++;
sym[j].d[sym[j].symd]=i;
break;
}
}
if(j>sj)
{
sj++;
strcpy(sym[sj].id,tok);
sym[sj].symd=0;
sym[j].d[sym[j].symd]=i;
sym[sj].symu=-1;
}
tok=strtok(NULL,"+-*/");
for(j=0;j<sj;j++)
{
if(strcmp(sym[j].id,tok)==0)
{
sym[j].symu++;
sym[j].u[sym[j].symu]=i;
break;
}
}
tok=strtok(NULL,";");
for(j=0;j<=sj;j++)
{
if(strcmp(sym[j].id,tok)==0)
{
sym[j].symu++;
sym[j].u[sym[j].symu]=i;
break;
}
}
}
}
for(j=0;j<n;j++)
{
if(b[j]==1)
printf("\n block%d stmt %d",++bj,j+1);
else
printf("%d",j+1);
}
for(j=0;j<=sj;j++)
{
printf("\n symbol:%s",sym[j].id);
printf("\n definition");
for(jj=0;jj<=sym[j].symd;jj++)
printf("%d",sym[j].d[jj]+1);
printf("\n usage");
for(jj=0;jj<=sym[j].symu;jj++)
printf("%d",sym[j].u[jj]+1);
}
getch();
}