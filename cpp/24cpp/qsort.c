#include "test.h"
#include <stdlib.h>
void QuickSort(int* arr,int left,int right){
	if(left<right){
		int i=left;
		int j=right;
		int temp=arr[i];
		while(i<j){
			while(i<j&&temp<=arr[j])j--;
			if(i<j)arr[i++]=arr[j];
			while(i<j&&temp>=arr[i])i++;
			if(i<j)arr[j--]=arr[i];
		}
		arr[i]=temp;	
		QuickSort(arr,left,i-1);
		QuickSort(arr,i+1,right);
	}
}
void Qsort(int* arr,int len){
	QuickSort(arr,0,len-1);
}
int main(void)
{
	testsort(Qsort,100000000);
	return 0;
}
