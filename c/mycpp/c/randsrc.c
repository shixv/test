#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp=fopen("src.txt","w");
	srand((unsigned int)time(0));
	for(int i=0;i<10000000;i++)
	{
		fprintf(fp,"%d,",rand()%1000);
	}
	fprintf(fp,"%d;",rand()%1000);
	fclose(fp);
	return 0;
}
