#include <stdio.h>

int main(void)
{
	char a[100];
	char b[100];
	int i=0,j;
	scanf("%s",a);
	while(a[i]!='\0')i++;
	for(j=0;j<i;j++)
	{
		b[j]=a[j];
	}
	for(j=0;j<i;j++)
		printf("%c",b[j]);
	putchar('\n');
	return 0;
}
