#include <stdio.h>

int main(void)
{
	int n=1;
	int ch;
	int c;
	FILE *p=fopen("a.out","r");
	while(n!=0)
	{
		c=ch;
		n=fread(&ch,sizeof(int),1,p);
	}
	printf("%d\n",c);
	return 0;
}
