#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct st
{
char op[4];
}t[100];
int main()
{
int i,j,n,l,k=-1,m=0;
clrscr();
printf("\nEnter no of code:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf(" %c %c %c %c",&t[i].op[0],&t[i].op[1],&t[i].op[2],&t[i].op[3]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if((t[i].op[3]==t[j].op[3])&&(t[i].op[2]==t[j].op[2])&&(t[i].op[1]==t[j].op[1]))
{
m++;
for(l=0;l<4;l++)
{
if(l==0)
printf(" %c ",(t[j].op[l]+m));
else
printf(" %c ",t[j].op[l]);
}
printf(" -->State optimized\n");
--n;
for(k=j;k<n;k++)
{
for(l=0;l<4;l++)
{
t[k].op[l]=t[k+1].op[l];
if((l==1)||(l==2))
{
if(t[k].op[l]==j+48)
{
t[k].op[l]=t[i].op[0];
}
}
if(l!=3)
{
if(((t[k].op[l])<65)&&((t[k].op[l])>j+48))
{
--t[k].op[l];
}
}
}
}
}
}
}
printf("\nOptimized Code:");
for(i=0;i<n;i++)
{
printf("\n %c %c %c %c",t[i].op[0],t[i].op[1],t[i].op[2],t[i].op[3]);
}
getch();
return 0;
}
