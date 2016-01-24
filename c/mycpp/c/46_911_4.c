#include <stdio.h>

double Xaver(double a,double b);
int main(void)
{
	double a,b;
	printf("input two number : ");
	scanf("%lf %lf",&a,&b);
	printf("the aver is %lf \n",Xaver(a,b));
	return 0;
}
double Xaver(double a,double b)
{
	return 1.0/((1.0/a+1.0/b)/2.0);
}
