#include "test.h"
#include <string>
void _qsort(int* a,int left,int right){
	if(left<right){
		int i=left+1;
		int j=right;
		int temp=a[i];
		while(i<j){
//			while(i<j&&a[j]>temp)j--;
//			if(i<j)a[i++]=a[j];
//			while(i<j&&a[i]<temp)i++;
//			if(i<j)a[j--]=a[i];
			while(i<j&&a[i]<temp)i++;
			while(i<j&&a[j]>temp)j--;
			if(i<j)Swap(a,i++,j--);
		}
//		a[i]=temp;
		Swap(a,left,i);
		_qsort(a,left,i-1);
		_qsort(a,i+1,right);
	}
}
void qsort(int* a,int len){
	_qsort(a,0,len-1);
}
int main(int argc,char* argv[]){
	testsort(qsort,std::stoi(argv[1]));
	return 0;
}
