#include <stdio.h>

int main(void)
{
	int len=0,i=0;
	char p[100];
	scanf("%s",p);
	while(p[len]!='\0')
	{
		if((int)p[len]<0)i++;
		len++;
	}
	return 0;
}
