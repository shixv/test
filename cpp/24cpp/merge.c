#include "test.h"
void Merge(int* arr,int left,int right,int mid,int* temp){
	int istart=left;
	int iend=mid;
	int jstart=mid+1;
	int jend=right;
	int length=0;
	while(istart<=iend&&jstart<=jend){
		if(arr[istart]<arr[jstart]){
			temp[length]=arr[istart];
			istart++;
		}else{
			temp[length]=arr[jstart];
			jstart++;
		}
		length++;
	}
	while(istart<=iend){
		temp[length]=arr[istart];
		istart++;
		length++;
	}
	while(jstart<=jend){
		temp[length]=arr[jstart];
		jstart++;
		length++;
	}
	for(int i=0;i<length;i++){
		arr[left+i]=temp[i];
	}
}
void MergeSort(int* arr,int left,int right,int* temp){
	if(left<right){
		int mid=(left+right)/2;

		MergeSort(arr,left,mid,temp);
		MergeSort(arr,mid+1,right,temp);
		Merge(arr,left,right,mid,temp);
	}
}
void Mergesort(int* arr,int len){
	int* temp=new int[len];
	MergeSort(arr,0,len-1,temp);
}
int main(void)
{
	testsort(Mergesort,1000000);
	return 0;
}
