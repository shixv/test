#include <stdio.h>
#define SIZE 5

//void show_array(int ar[],int n);

int main(void)
{
	int arrayi[SIZE]={1,2,4,5,3};
	int arrayi2[SIZE]={6,7,7,6,9};
	const int *p1=arrayi;
	p1=arrayi2;
	p1[2]=3;
	printf("%d\n",p1[2]);
	return 0;
}
//const * const p;
