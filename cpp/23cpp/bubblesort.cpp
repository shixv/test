#include "test.h"
using namespace std;
void PrintArray(int* arr,int length){
	for(int i=0;i<length;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}

void swap(int* arr,int pos1,int pos2){
	int temp=arr[pos1];
	arr[pos1]=arr[pos2];
	arr[pos2]=temp;
}
void BubbleSort(int* arr,int length){
	int i,j;
	for(i=0;i<length;i++){
		for(j=length-1;j>i;j--){
			if(arr[j-1]<arr[j]){
				swap(arr,i,j);
			}
		}
	}
}
int main(void)
{
	testsort(BubbleSort,100);
	return 0;
}
