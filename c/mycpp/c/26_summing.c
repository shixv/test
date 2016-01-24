#include <stdio.h>

int main(void)
{
	long num;
	long sum=0L;
	int status;
	
	printf("please input a integer to summed.");
	printf("q to quit: ");
	status = scanf("%ld",&num);
	while(status==1)
	{
		sum=sum+num;
		printf("please input the next integer(q to quit): ");
		status=scanf("%ld",&num);
	}
	printf("Those integers sum to %ld\n",sum);
	return 0;
}
