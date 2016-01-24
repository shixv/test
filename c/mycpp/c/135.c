#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char a[100]="10,20,30,40,50,69,9,8,77,656";
	int sum = 0;
	char *i=strtok(a,",");
	while(i)
	{
		sum+=atoi(i);
		i=strtok(NULL,","); 
	}
		
	printf("%d\n",sum);
	return 0;
}
