#include "test.h"
void shellsort(int* a,int len){
	int i,j,gap;
	Increament Inc(len);
	for(;Inc(gap)>0;){
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
	if(argc==1)argv[1]=(char*)"100";
	testsort(shellsort,std::stoi(argv[1]));
	return 0;
}
