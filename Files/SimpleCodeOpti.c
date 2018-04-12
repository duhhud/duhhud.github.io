#include<stdio.h>
#include<conio.h>
struct st
{
char op,op1[3],op2[3],op3;
}t[10];
void  main()
{
int i,j,d,k=0,n,l;
char cc;
clrscr();
printf("Enter the number of coded Lines");
scanf("%d",&n);
for(i=0;i<=n;i++)
scanf("%c %s %s %c",&t[i].op3,&t[i].op1,&t[i].op2,&t[i].op);
for(i=0;i<=n;i++)
{
if(t[i].op1[0]=='#'&&t[i].op2[0]=='#')
{
cc=t[i].op3;
if(t[i].op=='+')
d=(t[i].op1[i]-48)+(t[i].op2[i]-48);
if(t[i].op=='-')
d=(t[i].op1[i]-48)-(t[i].op2[i]-48);
for(k=i+1;k<n;k++)
{
if(t[k].op1[0]==cc)
{
t[k].op1[0]='#';
t[k].op1[i]=d+48;
}
if(t[k].op2[0]==cc)
{
t[k].op2[0]='#';
t[k].op2[1]=d+48;
}
}
--n;
for(k=i;k<n;k++)
{
t[k].op3=t[k+1].op3;
strcpy(t[k].op2,t[k+1].op2);
strcpy(t[k].op1,t[k+1].op1);
t[k].op=t[k+1].op;
if(isdigit(t[k].op3));
--t[k].op3;
if(isdigit(t[k].op2[0]))
--t[k].op2[0];
if(isdigit(t[k].op1[0]))
--t[k].op1[0];
}
 }
if(t[i].op1[0]=='#'&& t[i].op2[0]=='#')
i--;

}

for(i=0;i<n;i++)
printf("\n %c%s%s%c",t[i].op3,t[i].op1,t[i].op2,t[i].op);
getch();
}