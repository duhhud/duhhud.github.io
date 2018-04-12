#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
FILE *fp;
int i=0,j=0;
int k;
char *tok,arr[50][50],arr1[10][10],buf1[100];
char input[500];
clrscr();
fp=fopen("pgm.txt","r");
fread(input,500,1,fp);
strcpy(buf1,input);
tok=strtok(input," ,;+-=/*{}\n");
while(tok!=NULL)
{
if(strcmp(tok,"int")==0||strcmp(tok,"void")==0||strcmp(tok,"char")==0||strcmp(tok,"float")==0)
strcpy(arr[i++],tok);
else{
strcpy(arr1[j++],tok);
}
tok=strtok(NULL," ,;+-=*/{}\n");
}
printf("the keyword tokens are");
for(k=0;k<i;k++)
printf("\n%s",arr[k]);
printf("\nthe identifier tokens are");
for(k=0;k<j;k++)
printf("\n%s",arr1[k]);
printf("\nthe symbol tokens");
for(k=0;k<35;k++)
if(!isalpha(buf1[k]))
printf("%c",buf1[k]);
getch();
}
