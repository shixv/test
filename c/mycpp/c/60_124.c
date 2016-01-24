#include <stdio.h>

int wordar(char *p,int n);
int main(void)
{
	int i,j;
	char ar[40];
	j=wordar(ar,40);
	for(i=0;i<j;i++)putchar(ar[i]);
	return 0;
}

int wordar(char *p,int n)
{
	int i=0;char c='a';
	while(c!=' '&&c!='\t'&&c!='\n'&&i<n)
	{
		c=getchar();
		p[i]=c;
		i++;
	}
	return i;
}		
