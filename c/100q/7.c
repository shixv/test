#include <stdio.h>

int main(void)
{
	int count=0;
	for(int i=10000;i<100000;i++)
		if(i%10==6&&i%3==0)
			count++;
	printf("%d\n",count);
	return 0;
}
