#include <stdio.h>

int main(void)
{
	char c;
	int i=0;
	while((c=getchar())!='#')
	{
		if(c=='\n'){putchar(' ');i++;continue;}
		printf("%c / %d\t",c,(int)c);
		i++;
		if(!(i%8))printf("\n");
	}
	printf("\n");
	return 0;
}
