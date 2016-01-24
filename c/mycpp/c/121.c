#include <stdio.h>

int main(void)
{
	char a[100]="afsfdsfsac";
	char b[100]="1sadfaaedaf23";
	char c[200];
	int al=0,bl=0,i,j;
	while(a[al]!='\0')al++;
	while(b[bl]!='\0')bl++;
	for(i=0;i<al;i++)c[i]=a[i];
	for(j=al;j<al+bl;j++)c[j]=b[j-al];
	c[al+bl]='\0';
	printf("%s\n",c);
	return 0;
}
