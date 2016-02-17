#include <stdio.h>

int main(void)
{
	int n=1;
	while(n++)
		if(n%3==2&&n%5==3&&n%7==0)
		{
			printf("%d\n",n);
			return 0;
		}
	return 0;
}
