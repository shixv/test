#include "test.h"
void merge(int* arr,int left,int right,int mid,int* temp){
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
void _mergesort(int* arr,int left,int right,int* temp){
	if(left<right){
		int mid=(left+right)/2;
		_mergesort(arr,left,mid,temp);
		_mergesort(arr,mid+1,right,temp);
		merge(arr,left,right,mid,temp);
	}
}
void mergesort(int* arr,int len){
	int* temp=new int[len];
	_mergesort(arr,0,len-1,temp);
}
int main(int argc,char* argv[])
{
	if(argc==1)argv[1]=(char*)"100";
	testsort(mergesort,std::stoi(argv[1]));
	return 0;
}
