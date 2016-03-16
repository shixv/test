#include "test.h"
void SelectSort(int *arr,int len){
	int max;
	for(int i=0;i<len;i++){
		max=i;
		for(int j=i+1;j<len;j++){
			if(arr[j]>arr[max]){
				max=j;
			}
		}
		if(max!=i){
			Swap(arr,max,i);
		}
	}
}
int main(void)
{
	testsort(SelectSort,1000);
	return 0;
}
