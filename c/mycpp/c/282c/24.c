#include <stdio.h>

void merge(int *r,int *s,int x1,int x2,int x3)
{
	int i,j,k;
	i=x1;
	j=x2+1;
	k=x1;
	while((i<=x2)&&(j<=x3))
		if(r[i]<=r[j])
		{
			s[k]=r[i];
			i++;
			k++;
		}
		else
		{
			s[k]=r[j];
			j++;
			k++;
		}
	while(i<=x2)
		s[k++]=r[i++];
	while(i<=x3)
		s[k++]=r[j++];
}

void merge_sort(int *r,int *s,int m,int n)
{
	int p;
	int t[20];
	if(m==n)
		s[m]=r[m];
	else
	{
		p=(m+n)/2;
		merge_sort(r,t,m,p);
		merge_sort(r,t,p+1,n);
		merge(t,s,m,p,n);
	}
}

int  main(void)
{
	int a[11]={
		2,9,8,7,6,5,4,3,2,1,0
	};
	int i;
	merge_sort(a,a,1,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
}
