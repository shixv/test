#include <stdio.h>

int main(void)
{
	int n=1,temp;
	double sum1,sum2;
	while(scanf("%d",&n)&&n>0)
	{
		sum1=0.0,sum2=0.0;
		temp=n;while(temp){sum1+=1.0/temp;temp--;}
		temp=n;while(temp){(temp%2)?(sum2+=1.0/temp):(sum2-=1.0/temp);temp--;}
		printf("sum1 = %f\nsum2 = %f\n",sum1,sum2);
	}
	return 0;
}
	
			
		
