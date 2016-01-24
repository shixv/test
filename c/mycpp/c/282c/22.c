#include <stdio.h>

void qusort(int *s,int start,int end)
{
	int i,j;
	i=start;
	j=end;
	s[0]=s[start];
	while(i<j)
	{
		while(i<j&&s[0]<s[j])
			j--;
		if(i<j)
		{
			s[i]=s[j];
			i++;
		}
		while(i<j&&s[i]<=s[0])
			i++;
		if(i<j)
		{
			 s[j]=s[i];
			 j--;
		}
	}
	s[i]=s[0];
	if(start<i)
		qusort(s,start,j-1);
	if(i<end)
		qusort(s,j+1,end);
}

int main(void)
{
	int a[]={
		7,9,8,7,6,5,4,3,2,1,0
	};
	qusort(a,1,10);
	for(int i=1;i<11;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
}
