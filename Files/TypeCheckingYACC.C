#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fcntl.h>
struct sm
{
char sym[10],type[10];
int size;
}st[10];
void main()
{
//FILE *fd;
int fd,i=-1,index=-1,j=0,k,size;
char stmt[10][80],str[80],type[10],buf1[500],c,*tok;
char file[10];
clrscr();
//scanf("%s",file);
fd=open("test1.txt","r");
read(fd,buf1,500);
printf("%s",buf1);
tok=strtok(buf1,"\n");
while(tok!=NULL)
{
if(tok)
 strcpy(stmt[++i],tok);
tok=strtok(NULL,"\n");
}

for(j=0;j<i;j++)
{
 strcpy(str,stmt[j]);
 tok=strtok(str," ");

 if(strcmp(tok,"int")==0 || strcmp(tok,"float")==0)
 {
  strcpy(type,tok);
  if(strcmp(type,"int")==0) size=2;
  if(strcmp(type,"float")==0) size=4;
  while(tok!=NULL)
  {
   tok=strtok(NULL," ,;");
   if(tok)
   {
    strcpy(st[++index].sym,tok);
    strcpy(st[index].type,type);
    st[index].size=size;
   }
  }
 }
}
//strcpy(stmt[i-1],"}");
//for(j=0;j<i;j++)
// printf("\n%s",stmt[j]);

printf("\nThe Symbol Table:\n");
for(j=0;j<index+1;j++)
{
 printf("\n%s %s %d",st[j].sym,st[j].type,st[j].size);
}
for(j=0;j<i;j++)
{
 strcpy(str,stmt[j]);
 printf("%s",stmt[j]);
 tok=strtok(str,"=");
 //printf("%s\n",tok);
 if(tok)
 {
  for(k=0;k<index+1;k++)
  {
   if(strcmp(tok,st[k].sym)==0)
   {
    strcpy(type,st[k].type);
    printf("%s",type);
    break;
   }
  }

  while(tok!=NULL)
  {
  tok=strtok(NULL,"+;");
  // printf("\n%s",tok);getch();
    // printf("\n%s",tok);
   if(tok)
   {
    for(k=0;k<index+1;k++)
    {  if(strcmp(tok,st[k].sym)==0)
break;
	}
if(strcmp(type,st[k].type)!=0)
{
printf("\nType error in line %d\n",j+1);
break;
}}}}}
getch();
}