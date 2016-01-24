#include <stdio.h>

void copy_arr(double source [],double target [],int n);
void copy_ptr(double *source,double *target,int n);
void show_arr(double *ar,int n);
int main(void)
{
	double source[5] = {1.1,2.2,3.3,4.4,5.5};
	double target1[5];
	double target2[5];
	
	copy_arr(source,target1,5);
	copy_ptr(source,target2,5);
	
	show_arr(target1,5);
	show_arr(target2,5);
	
	return 0;
}
void copy_arr(double source [],double target [],int n)
{
	int i;
	for(i=0;i<n;i++)
		target[i]=source[i];
}
void copy_ptr(double *source,double *target,int n)
{
	int i;
	for(i=0;i<n;i++)
		*(target+i)=*(source+i);
}
void show_arr(double *ar,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%1.1lf\t",ar[i]);
	printf("\n");
}
