#include<stdio.h>
#include<conio.h>
struct st
{
char op,op1,op2,op3;
}t[10];
void main()
{
int i,n,r,r1;
clrscr();
printf("Enter no code:");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf(" %c %c %c %c",&t[i].op3,&t[i].op1,&t[i].op2,&t[i].op);
for(i=0;i<n;i++)
printf("\n%c %c %c %c",t[i].op3,t[i].op1,t[i].op2,t[i].op);
r=-1;
for(i=0;i<n;i++)
{
if(t[i].op!='=')
{
printf("\n mov r%d,%c",++r,t[i].op1);
printf("\n mov r%d,%c",++r,t[i].op2);
r1=r;
switch(t[i].op)
{
case '+':
	printf("\nadd r%d,r%d,r%d",++r,--r,r1);
	break;
case '-':
	printf("\n sub r%d,r%d,r%d",++r,--r,r1);
	break;
case '*':
	printf("\n mul r%d,r%d,r%d",++r,--r,r1);
	break;
case '/':
	 printf("\n div r%d,r%d,r%d",++r,--r,r1);
	 break;
}
printf("\n mov %c,r%d",t[i].op3,r);
}
else
{
printf("\n mov %c,%c",t[i].op1,t[i].op2);
}
}
getch();
}


