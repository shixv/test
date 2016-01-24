#include <stdio.h>

int main(void)
{
	float a,b;
	while(scanf("%f %f",&a,&b))printf("%f\n",((a-b)>0?(a-b):(b-a))/(a*b));
	return 0;
}
	
