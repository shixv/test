#include <stdio.h>

void smile(int n)
{
	while(n>=1){printf("smile!");n--;}
	printf("\n");
}
int main(void)
{
	int n;
	printf("input a number : ");
	scanf("%d",&n);
	while(n)
	{
		smile(n);
		n--;
	}
	return 0;
}

