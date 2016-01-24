#include <stdio.h>
#define SIZE 4

int main(void)
{
	int ar[SIZE][SIZE]={{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7}};
	printf("ar = %p\n",ar);
	printf("ar[0] = %p\n",ar[0]);
	printf("ar[0][0] = %p\n",&ar[0][0]);
	
	return 0;
}
