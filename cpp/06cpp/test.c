#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getmemory(char **p,int num)
{
	*p=(char *)malloc(num);
}
			

int main(void)
{
	char *str=NULL;
	getmemory(&str,100);
	strcpy(str,"hello");
	free(str);
	if(str!=NULL)
	{
		strcpy(str,"world");
	}
	printf("str is %s\n",str);

	return 0;
}
