#include <stdio.h>
#include <math.h>

int main(void)
{
	float number;
	double f,i;
	printf("input a number:\n");
	scanf("%f",&number);
	f=modf(number,&i);
	printf("%f=%f+%f\n",number,i,f);
	return 0;
}
