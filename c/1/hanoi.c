#include <stdio.h>

void hanoi(int n,char A,char B,char C)
{
	if(n==1)
		printf("%d:%c->%c\t",n,A,C);
	else
	{
		hanoi(n-1,A,C,B);
		printf("%d:%c->%c\t",n,A,C);
		hanoi(n-1,B,A,C);
	}
}
int main(void)
{
	int n;
	printf("Please input disc count: ");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}
