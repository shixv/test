#include "test.h"
void bubble(int* arr,int len){
	int flag=1;
	for(int i=0;i<len&&flag==1;i++){
		flag=0;
		for(int j=len-1;j>i;j--){
			if(arr[j]>arr[j-1]){
				Swap(arr,j,j-1);
				flag=1;
			}
		}
	}
}
int main(int argc,char* argv[])
{
	if(argc==1)argv[1]=(char*)"100";
	testsort(bubble,std::stoi(argv[1]));
	return 0;
}
