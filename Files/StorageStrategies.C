#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define base 1000
void main()
{
char stmt[20][50];
char *tok,*tok1,*tok2;
int i,n,width=0,address=0,length=1;
clrscr();
printf("Enter no lines: ");
scanf("%d ",&n);
for(i=0;i<n;i++)
gets(stmt[i]);
address=base;
printf("\nADDRESS FOR CODE :%d ",address);
//address=address+n*50;
for(i=0;i<n;i++)
{
 tok=strtok(stmt[i]," ");
 if(strcmp(tok,"int")==0) width=2;
 else if(strcmp(tok,"char")==0) width=1;
 else if(strcmp(tok,"float")==0) width=4;
 while(tok!=NULL)
 {
 tok=strtok(NULL,",;");
 length=1;
 if(strstr(tok,"["))
  {
   strcpy(tok1,tok);
   tok=strtok(tok1,"[");
   tok2=strtok(NULL,"]");
   xx:length=length*atoi(tok2);
   tok2=strtok(NULL,"[");
   if(tok2){tok2=strtok(NULL,"]");goto xx;}
  }
 if(tok)
  {printf("\nThe address for %s : %d",tok,address);
   address=address+width*length;
  }
 }
}
getch();
}


