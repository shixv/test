#include "test.h"
void insert(int* a,int len){
	int i,j;
	for(i=1;i<len;i++){
		int temp=a[i];
		for(j=i;j>0&&a[j-1]>temp;j--){
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
}
int main(void)
{
	testsort(insert,100);
	return 0;
}
