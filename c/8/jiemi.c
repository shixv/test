#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[])
{
	FILE *p=fopen(argv[1],"r");
	FILE *tmp=fopen(".tmp","w");
	char *ch=(char *)malloc(sizeof(char)*1024);
	srand((unsigned int)atoi(argv[2]));
	int rc;
	while((rc=fread(ch,1,1024,p))!=0)
	{
		for(int i=0;i<rc;i++)
			ch[i]-=rand()%128;
		fwrite(ch,1,rc,tmp);
	}
	free(ch);
	fclose(p);
	fclose(tmp);
	remove(argv[1]);
	rename(".tmp",argv[1]);
}

