#include "test.h"
#include <string>
inline int leftChild(int i){
	return 2*i+1;
}

void percDown(int* a,int i,int n){
	int child;
	int tmp;
	for(tmp=a[i];leftChild(i)<n;i=child){
		child=leftChild(i);
		if(child!=n-1&&a[child]<a[child+1])
			child++;
		if(tmp<a[child])
			a[i]=a[child];
		else
			break;
	}
	a[i]=tmp;
}

void heapsort(int* a,int len){
	for(int i=len/2;i>=0;i--)
		percDown(a,i,len);
	for(int j=len-1;j>0;j--)
	{
		Swap(a,0,j);
		percDown(a,0,j);
	}
}
int main(int argc,char* argv[]){
	testsort(heapsort,std::stoi(argv[1]));
	std::cout<<Swap.count()<<std::endl;
	return 0;
}
