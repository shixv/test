#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int rn=0;
	char ch;
	int j;
	FILE *fp=fopen("a.txt","r");
	if(!fp)while((ch=getc(fp))!=EOF)if(ch=='\n')rn++;
	char **s=(char **)malloc(sizeof(char *)*rn);
	for(int i=0;i<rn;i++)
	{
		s[i]=(char *)malloc(sizeof(char)*40);
		j=0;
		while((ch=getc(fp))!='\n'){s[i][j]=ch;j++;}
		s[i][j]='\0';
	}
	
}
