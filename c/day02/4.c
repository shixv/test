#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	srand((unsigned int)time(0));
	for(int i=0;i<10;i++)
		printf("%d",rand()%10);
	printf("\n");
	return 0;
}

