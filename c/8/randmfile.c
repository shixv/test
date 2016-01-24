#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000

int main(void)
{
	srand((unsigned int)time(0));
	FILE *p=fopen("sort.txt","w");
	int *rd=(int *)malloc(sizeof(int)*SIZE);
	for(int i=0;i<SIZE;i++)
		rd[i]=rand()%SIZE;
	for(int i=0;i<SIZE;i++)
	{
		if(i%10==0)
			fprintf(p,"\n");
		fprintf(p,"%d ",rd[i]);
	}
	free(rd);
	fclose(p);
	return 0;
}

