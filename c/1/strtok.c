#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char *re=NULL;
	re=strtok(argv[1],argv[2]);
	while(re!=NULL)
	{
		printf("%s\n",re);
		re=strtok(NULL,argv[2]);
	}
	return 0;
}
