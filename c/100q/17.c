#include <stdio.h>

int main(void)
{
	int count=0;
	int temp;
	for(int i=400;i<500;i++)
	{
		temp=i;
		while(temp)
		{
			if(temp%10==4)
				count++;
			temp/=10;
		}
	}
	if(count==112)
		printf("Yes\n");
	else
		printf("No,%d\n",count);
	return 0;
}
