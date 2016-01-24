#include <stdio.h>
#define SIZE 5

int pmarr_max(double *ar,int n);
int main(void)
{
	double array[SIZE]={1.0,2.0,5.0,6.0,7.0};
	printf("The index of max number is %d.\n",pmarr_max(array,SIZE));
	return 0;
}
int pmarr_max(double *ar,int n)
{
	int i;
	double temp;
	temp=ar[0];
	for(i=0;i<n;i++)
	{
		if(temp<ar[i])temp=ar[i];
	}
	return i;
}
