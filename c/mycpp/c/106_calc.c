#include <stdio.h>
#include <stdlib.h>
#define MAX 50

char calc1(char *p);
int main(void)
{
	char p[MAX];
	gets(p);
	printf("%c",calc1(p));
	return 0;
}
char calc1(char *p)
{
	int i;
	while(*p)
	{
		for(i=1;i<MAX-1;i++)
		{
			switch(p[i]){
				case '*':
				{
					p[i+1]=p[i-1]*p[i+1];
					p[i-1]='A';
					continue;
				}
				case '/':
				{
					p[i+1]=p[i-1]/p[i+1];
					p[i-1]='A';
					continue;
				}
				default:continue;}
		}
		for(i=1;i<MAX-1;i++)
		{
			switch(p[i]){
				case '+':
				{
					while(p[i+1]='A')i++;
					p[i+1]=p[i-1]+p[i+1];
					continue;
				}
				case '-':
				{
					while(p[i+1]='A')i++;
					p[i+1]=p[i-1]+p[i+1];
					continue;
				}
				default:continue;}
		}
	}
	i=0;
	while(*p)i++;
	
	return p[i];		
}
