#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	int i=0;
	char *tmp=argv[1];
	while((tmp=strstr(tmp,argv[2]))!=NULL)
	{
		i++;
		tmp++;
	}
	if(tmp==strstr(tmp,argv[2]))
	{
		printf("qianduan\n");
	}
	if(1)
	{
		printf("houduan\n");
	}
	printf("%s\n",&argv[1][strlen(argv[1])-strlen(argv[2]-1)]);
	return 0;
}
