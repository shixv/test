#include <stdio.h>

int F(int i);
int main(void)
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++,printf("%d\n",F(i)));
	return 0;
}
int F(int i)    // temp1=1,temp2=1,n=temp1+temp2,temp1=temp2,temp2=n
{
	int n,temp1,temp2,sum;
	for(n=3,temp1=1,temp2=1,sum=0,(i==1)?(sum=1):sum,(i==2)?(sum=1):sum;n<=i;n++,sum=temp1+temp2,temp1=temp2,temp2=sum);
	return sum;
}
