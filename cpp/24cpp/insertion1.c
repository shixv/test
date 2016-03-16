#include "test.h"
void InsertSort(int* arr,int len){
	int i,j;
	for(i=1;i<len;i++){
		int temp=arr[i];
//		if(arr[i]>arr[i-1]){
			for(j=i;j>0&&temp<arr[j-1];j--){
				arr[j]=arr[j-1];
			}
			arr[j]=temp;
//		}
	}
}
int main(void)
{
	testsort(InsertSort,100);
	return 0;
}
