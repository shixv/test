#include <stdio.h>
#include <math.h>

double f(double x)
{
	if(x>10||x<=-7)
		return exp(x)/(2*x);
	if(x>=4&&x<=10)
		return log(x+7);
	if(x==0)
		return 0;
	if(x>-7&&x<4&&x!=0)
		return x*abs(x);
	return 0;
}
int main(void)
{
	printf("f(-7)=%f\n",f(-7));
	printf("f(-1)=%f\n",f(-1));
	printf("f(0)=%f\n",f(0));
	printf("f(7)=%f\n",f(7));
	return 0;
}
