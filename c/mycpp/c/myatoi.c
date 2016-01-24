#include <stdio.h>

int mysqrt1(int n,int j)
{
	for(int i=0;i<j;i++)
	{
		n=n*10;
	}
	return n;
}

int myatoi1(const char *nptr)
{
	int len=0;
	while(nptr[len]){
		len++;
	}
	int i,j=0,n=0;
	int arr[len];
	for(i=0;i<n;i++)
	{
		switch(nptr[n]){

			case 0:arr[i]=0;continue;
			case 1:arr[i]=1;continue;
			case 2:arr[i]=2;continue;
			case 3:arr[i]=3;continue;
			case 4:arr[i]=4;continue;
			case 5:arr[i]=5;continue;
			case 6:arr[i]=6;continue;
			case 7:arr[i]=7;continue;
			case 8:arr[i]=8;continue;
			case 9:arr[i]=9;continue;
			default:break;
		}
		j++;
	}
	for(i=j-1;i>=0;i--)
	{
		n+=mysqrt1(arr[i],i);
	}
	return n;
}
int main(void)
{
	printf("%d\n",myatoi1("7656"));
	return 0;
}
