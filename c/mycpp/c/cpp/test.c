#include <stdio.h>
int main(void)
{
	FILE *a=fopen("a","r");
	FILE *b=fopen("b","r");
	char cha,chb;
	while((cha=fgetc(a))!=EOF)
	{
		chb=fgetc(b);
		if(cha!=chb)
		{
			printf("%ld\n",ftell(a));
		}
	}
	
	return 0;
}
