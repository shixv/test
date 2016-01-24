#include <stdio.h>

int main(void)
{
	FILE *p=fopen("test.txt","w");
	char *str="heheheheh";
	int i=0;
	while(fputc(str[i],p)!=EOF);
		printf("done.\n");
	return 0;
}
			
