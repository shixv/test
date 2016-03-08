#include <stdio.h>
#include "darray.h"

void test01(){
	Darray* darray=Init_Darray();
	for(int i=0;i<20;i++){
		Insert_Darray(darray,i,i+1);
	}
	printf("size->%d capacity->%d \n",Length_Darray(darray),Capacity_Darray(darray));
	Print_Darray(darray);
	Destroy_Darray(darray);
}

int main(){
	test01(); 
	return 0;

}
