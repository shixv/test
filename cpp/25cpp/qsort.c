#include "test.h"
int middle3(int* a,int left,int right){
	int center=(left+right)/2;
	if(a[left]>a[center])Swap(a,left,center);
	if(a[left]>a[right])Swap(a,left,right);
	if(a[center]>a[right])Swap(a,center,right);
	Swap(a,center,left);
	return a[left];
}
void QuickSort(int* arr,int left,int right){
	if(left<right){
//		int temp=middle3(arr,left,right);
		int i=left;
		int j=right;
		int temp=arr[i];
		while(i<j){
			while(i<j&&temp<=arr[j])j--;
			if(i<j)arr[i++]=arr[j];
			while(i<j&&temp>=arr[i])i++;
			if(i<j)arr[j--]=arr[i];
/*
			while(i<j&&temp<arr[j])j--;
			while(i<j&&temp>arr[i])i++;
//			if(arr[i]==arr[j]){i++;j--;continue;}
			if(i<j)Swap(arr,i++,j--);
*/  	}
//		Swap(arr,right,i);	
		arr[i]=temp;
		QuickSort(arr,left,i-1);
		QuickSort(arr,i+1,right);
	}
}
void Qsort(int* arr,int len){
	QuickSort(arr,0,len-1);
}
int main(int argc,char* argv[])
{
	if(argc==1)argv[1]=(char*)"100";
	testsort(Qsort,std::stoi(argv[1]));
	std::cout<<Swap.count()<<std::endl;
	return 0;
}
