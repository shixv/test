#include <stdio.h>
#include <stdarg.h>
double sum(int, ...);
int main(void)
{
	double s,t;
	
	s=sum(3,1.1,2.3,1.4);
	printf("%g\n",s);
	return 0;
}
double sum(int lim, ...)
{
	va_list ap;
	double tot=0;
	int i;
	va_start(ap,lim);
	for(i=0;i<lim;i++)
		tot+=va_arg(ap,double);
	va_end(ap);
	return tot;
}

