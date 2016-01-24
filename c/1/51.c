#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int(int10)[10];

int main(void)
{
	int i=0;
	int j=0;
	int10 p[3]={
		0
	};
	for(i=0;i<3;i++)
	{
		for(j=0;j<10;j++)
			printf("%d ",p[i][j]);
	}
	printf("\n");
	return 0;
}
