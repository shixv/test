#include <stdio.h>

int main(void)
{
	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int index;
	
	for(index=0;index<12;index++)
		printf("Month %d has %2d days.\n",index+1,day[index]);
	return 0;
}

