#include <stdio.h>

int main(void)
{
	for(int i=0;i<10000;i++)
	{
		if(i%2)
			printf("]");
		else
			printf("[");
	}
	printf("\n");
	return 0;
}
