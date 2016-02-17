#include <stdio.h>

int main(void)
{
	int sum=0;
	for(int i=100;i<201;i++)
	{
		if((i%6==0)&&(i%8==0))
		{
			sum+=i;
			printf("%d,",i);
		}
	}
	printf("%d\n",sum);
	return 0;
}
