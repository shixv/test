#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
//	char *s=strpbrk(argv[1],argv[2]);
	char *s=strtok(argv[1],argv[2]);
	while(s!='\0')
	{
		printf("%s\n",s);
		s=strtok(NULL,argv[2]);
	}
	return 0;
}
