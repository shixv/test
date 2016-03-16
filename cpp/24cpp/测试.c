#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NUMBER 100000
void QuickSort(int* arr,int left,int right){
	if(left<right){
		int i=left;
		int j=right;
		int temp=arr[i];
		while(i<j){
			while(i<j&&temp<=arr[j])j--;
			if(i<j)arr[i++]=arr[j];
			while(i<j&&temp>=arr[i])i++;
			if(i<j)arr[j--]=arr[i];
			arr[i]=temp;
			QuickSort(arr,left,i-1);
			QuickSort(arr,i+1,right);
		}
	}
}
void swapA(int* a,int* b){

	int temp = *a;
	*a = *b;
	*b = temp;

}

int main(){


	int arr[NUMBER];
	srand((unsigned)time(NULL));
	for (int i = 0; i < NUMBER; i++){
		arr[i] = rand() % NUMBER;
	}


	//排序之前
	//PrintArray(arr, NUMBER);
//	long t_start = GetSystemTime();
	//BubbleSort(arr,NUMBER); // 905  10000个数据  234 5000数据
	//SelectSort(arr,NUMBER); // 140 10000个数据 31 5000数据
	//InsertSort(arr,NUMBER); //75 10000个数据  16 5000数据   10万 
	//ShellSort(arr,NUMBER);
	QuickSort(arr, 0, NUMBER - 1);
	//O(n^2)
//	long t_end = GetSystemTime();
//	printf("排序所需时间:%ldms",t_end - t_start);

	//InsertSort(arr, NUMBER);
	//排序之后
	//PrintArray(arr, NUMBER);



	system("pause");
	return EXIT_SUCCESS;
}
