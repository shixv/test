#include "test.h"
void insertionSort(int *a,int count){
	int i,j,temp;
	for(i=1;i<count;i++){
		temp=a[i];
		for(j=i;j>0&&a[j-1]>temp;j--){
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
}
int main(void)
{
	testsort(insertionSort,1000);
	return 0;
}
