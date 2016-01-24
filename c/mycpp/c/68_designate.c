#include <stdio.h>
#define MONTH 12

int main(void)
{
	int days[MONTH]={[1]=31,[10]=30};
	int i;
	
	for(i=0;i<MONTH;i++)
		printf("%2d %d\n",i+1,days[i]);
	return 0;
}

