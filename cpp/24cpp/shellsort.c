#include "test.h"
void shellsort(int* a,int len){
	int i,j,gap;
	Increament Inc(len,[](int i)->int{return (2<<i)-1;});
	for(;Inc(gap)>0;){
		for(i=gap;i<len;i+=gap){
			int temp=a[i];
			for(j=i;j>=gap&&a[j-gap]>temp;j-=gap)
				a[j]=a[j-gap];
			a[j]=temp;
		}
	}
}
int main(void)
{
	testsort(shellsort,1000);
	return 0;
}
