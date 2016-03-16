#include "test.h"
void bubble(int *arr,int len){
	int flag=1;
	for(int i=0;i<len&&flag==1;i++){
		flag=0;
		for(int j=len-1;j>i;j--){
			if(arr[j]<arr[j-1]){
				Swap(arr,j,j-1);
				flag=1;
			}
		}
	}
}
void selection(int* arr,int len){
	int flag;
	for(int i=0;i<len;i++){
		flag=i;
		for(int j=i+1;j<len;j++){
			if(arr[j]>arr[flag]){
				flag=j;
			}
		}
		if(flag!=i){
			Swap(arr,flag,i);
		}
	}
}
void insertionsort(int* a,int len){
	int i,j,temp;
	for(i=1;i<len;i++){
		temp=a[i];
		for(j=i;j>0&&a[j-1]>temp;j--){
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
}
void _quicksort(int* arr,int left,int right){
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
		_quicksort(arr,left,i-1);
		_quicksort(arr,i+1,right);
	}
}
void quicksort(int* arr,int len){
	_quicksort(arr,0,len-1);
}
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
void shellsort(int* a,int len){
	int i,j,gap;
	Increament inc(len,[](int a)->int{return a/3+1;});
	for(;inc(gap)>0;){
		for(i=gap;i<len;i+=gap){
			int temp=a[i];
			for(j=i;j>=gap&&a[j-gap]>temp;j-=gap)
				a[j]=a[j-gap];
			a[j]=temp;
		}
	}
}
int main(int argc,char* argv[])
{
	using namespace std;
	int count;
	if(argc==1)
		count=10;
	else
		count=stoi(argv[1]);
	cout<<"对"<<count<<"个数排序："<<endl;
	cout<<"bubble sort: "<<endl;
	testsort(bubble,count);
	cout<<endl;
	cout<<"selection sort: "<<endl;
	testsort(selection,count);
	cout<<endl;
	cout<<"insertion sort: "<<endl;
	testsort(insertionsort,count);
	cout<<endl;
	cout<<"shell sort: "<<endl;
	testsort(shellsort,count);
	cout<<endl;
	cout<<"merge sort: "<<endl;
	testsort(mergesort,count);
	cout<<endl;
	cout<<"quick sort: "<<endl;
	testsort(quicksort,count);
	return 0;
}
