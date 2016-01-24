#include <stdio.h>
#include <stdlib.h>

int getCountOfSimpleLine(const char *filename,unsigned int *count);
int main(int argc,char *argv[])
{
	unsigned int *count=(unsigned int *)malloc(sizeof(unsigned int)*(argc-1));
	for(int i=1;i<argc;i++)
		getCountOfSimpleLine(argv[i],count+i-1);
	for(int i=0;i<argc-1;i++)
	{
		printf("%s : %d LINE.\n",argv[i+1],count[i]);
	}
	return 0;
}

int getCountOfSimpleLine(const char *filename,unsigned int *count)
{
	FILE *fp=fopen(filename,"r");
	int rc;
	char now,prev=-1;
	while((rc=fread(&now,1,1,fp))!=0)
	{
		if(now=='\n'&&now==prev)
			(*count)++;
		prev=now;
	}
	fclose(fp);
	return 0;
}
