#include <stdio.h>

int is_sxh(int n);
int main(void)
{
	for(i=100;i<1000;i++)
	{
		if(is_sxh(i))printf("%d\t",i);
	}
	return 0;
}
int is_sxh(int n)
{
	int i=100;
	((((i-(i%100))/100)*((i-(i%100))/100)*((i-(i%100))/100)+((i%100-i%10)/10)*((i%100-i%10)/10)*((i%100-i%10)/10)+(i%10)*(i%10)*(i%10))==i)?return 1:return 0;
}
