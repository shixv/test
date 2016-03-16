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
int main(void)
{
	testsort(bubble,1000);
	return 0;
}
