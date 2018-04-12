#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int f=0,i=0,size=0,j,address=1000;
int fd,k,l=0;
char c,*str,*tok,*ch,stmt[20][20],ch1[10][10],buffer[500];
clrscr();
fd=open("f.txt"," O_RDONLY");
read(fd,buffer,500);
printf("%s",buffer);
tok=strtok(buffer,"\n");
getch();
while(tok!=NULL)
{
strcpy(stmt[l],tok);
tok=strtok(NULL,"\n");
l++;
}
printf("\n *** symbol table ***");
printf("\n type \t name \t size \t address");
for(k=0;k<l;k++)
{
strcpy(str,stmt[k]);
ch=strtok(str," ,;");
i=0;
while(ch!=NULL)
{
strcpy(ch1[i++],ch);
ch=strtok(NULL," ,;");
}
for(j=1;j<l;j++)
{
if(strcmp(ch1[0],"int")==0)
size=2;
else if(strcmp(ch1[0],"float")==0)
size=4;
else if(strcmp(ch1[0],"char")==0)
size=1;
printf("\n %s \t %d \t %d",ch1[0],ch1[j],size,address=address+size);
}
}
getch();
}


