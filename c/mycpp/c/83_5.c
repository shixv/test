#include <stdio.h>
#define SIZE 5

double max_min(double *ar,int n);
int main(void)
{
	double array[SIZE]={2.33,1.34,1.67,2.34,1.98};
	printf("The value is %1.2lf.\n",max_min(array,SIZE));
	return 0;
}
double max_min(double *ar,int n)
{
	int i;
	double temp1,temp2;
	temp1=ar[0];
	temp2=ar[0];
	for(i=1;i<n;i++)
	{
		if(temp1<ar[i])temp1=ar[i];
		if(temp2>ar[i])temp2=ar[i];
	}
	return temp1-temp2;
}
