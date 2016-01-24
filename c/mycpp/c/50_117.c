#include <stdio.h>

int main(void)
{
	char name1[11],name2[11];
	int count;
	
	printf("please input two names:\n");
	count=scanf("%5s %10s",name1,name2);
	printf("I read %d names %s and %s",count,name1,name2);
	return 0;
}
