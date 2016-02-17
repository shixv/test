#include <stdio.h>

int main(void)
{
	int M=123;
	int sum=0;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		{
			if(i==j)
				sum+=M;
			if(i<j)
				sum+=i+j;
			if(i>j)
				sum+=i*j;
		}
	printf("%d\n",sum);
	return 0;
}
