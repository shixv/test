#include <stdio.h>

void insort(int *s,int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		s[0]=s[i];
		j=i-1;
		while(s[0]<s[j])
		{
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=s[0];
	}
}
int main(void)
{
	int a[11],i;
	printf("Please input ten number:\n");
	for(i=1;i<11;i++)
		scanf("%d",&a[i]);
	for(i=1;i<11;i++)
		printf("%d ",a[i]);
	putchar('\n');
	insort(a,10);
	for(i=1;i<11;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
}
