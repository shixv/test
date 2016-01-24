#include <stdio.h>

int main(void)
{
	int min=0,max=1,sum=0;
	while(scanf("%d %d",&min,&max)&&(max>min))
		{sum=0;while(max!=(min-1)){sum+=max*max;max--;}printf("%d\n",sum);}
	return 0;
}
