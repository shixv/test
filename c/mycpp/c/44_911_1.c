#include <stdio.h>

double min(double x,double y);
int main(void)
{
	double a,b;
	scanf("%lf %lf",&a,&b);
	printf("min is %lf\n",min(a,b));
	return 0;
}
double min(double x,double y)
{
	return x<y?x:y;
}
	
