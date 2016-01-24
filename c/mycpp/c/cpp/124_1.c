#include <stdio.h>

int main(void)
{
	const int MIN=60;
	int m;
	printf("Please input minits: ");
	scanf("%d",&m);
	while(m>0)
	{
		printf("It's %d hours %d minites.\n",m/MIN,m%MIN);
		printf("Please input minites: ");
		scanf("%d",&m);
	}
	return 0;
}
