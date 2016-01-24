#include <stdio.h>
#include <string.h>
#define FUNC strcspn

int main(int argc,char *argv[])
{
//	char s[100]={0};
//	size_t n;
//	n=strcspn(argv[1],argv[2]);
	int n=strcmp(argv[1],argv[2]);
//	char *s=strchr(argv[1],argv[2][0]);

	printf("%s\n",argv[2]);
	printf("%s\n",argv[1]);
	printf("%d\n",n);
//	printf("%s\n",s);
	return 0;
}
