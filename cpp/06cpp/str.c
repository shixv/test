#include <stdio.h>
/*
char *strA()
{
	char *str=malloc(100);
	strcpy(str,"hello world");
	return str;
}*/
int main(void)
{
	int arr[]={1,2,3,4,5,6,7,8};
	int *p=arr;
	*(p++)+=123;
	printf("%d,%d\n",*p,*(++p));
	return 0;
}

