#include "test.h"
void insert(int* arr,int len){
	int i,j;
	for(i=1;i<len;i++){
		int temp=arr[i];
		for(j=i;j>0&&arr[j-1]>temp;j--)
			arr[j]=arr[j-1];
		arr[j]=temp;
	}
}
int main(void)
{
	testsort(insert,100);
	return 0;
}
