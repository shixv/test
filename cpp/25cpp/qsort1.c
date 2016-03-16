#include "test.h"
#include <string>
void insertionSort(int* arr,int left,int right)
{
	int* a=arr+left;
	int j;
	for(int p=1;p<right-left+1;p++){
		int tmp=a[p];
		for(j=p;j>0&&tmp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}
}
const int& median3(int* arr,int left,int right){
	int center=(left+right)/2;
	if(arr[center]<arr[left])
		Swap(arr,left,center);
	if(arr[right]<arr[left])
		Swap(arr,left,right);
	if(arr[right]<arr[center])
		Swap(arr,center,right);
	Swap(arr,center,right-1);
	return arr[right-1];
}
void quicksort(int* a,int left,int right){
	if(left+10<=right){
		int pivot=median3(a,left,right);
		int i=left,j=right-1;
		for(;;){
			while(a[++i]<pivot);
			while(pivot<a[j--]);
			if(i<j)
				Swap(a,i,j);
			else
				break;
		}
		Swap(a,i,right-1);
		quicksort(a,left,i-1);
		quicksort(a,i+1,right);
	}
	else
		insertionSort(a,left,right);
}
void quicksort(int* arr,int length){
	quicksort(arr,0,length-1);
}

int main(int argc,char* argv[]){
	testsort(quicksort,std::stoi(argv[1]));
	std::cout<<Swap.count()<<std::endl;
	return 0;
}
