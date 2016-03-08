#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<stdlib.h>
#include<stdio.h>

//动态数据结构体
typedef struct _DYNAMICARRAY{
	int* address; //数据地址
	int capacity; //容量
	int size; //数组长度
}DynamicArray;


//初始化动态数组，创建动态数组
DynamicArray* Init_DynamicArray();
//获得动态数组的长度
int Length_DynamicArray(DynamicArray* dArray);
//判断动态数组是否为空
int IsEmpty_DynamicArray(DynamicArray* dArray);
//获得动态数组的容量
int Capacity_DynamicArray(DynamicArray* dArray);
//向动态数组插入数据
void Insert_DynamicArray(DynamicArray* dArray,int pos,int data);
//删除指定位置的数据
void Remove_DynamicArray(DynamicArray* dArray, int pos);
//清空数组
void Clear_DynamicArray(DynamicArray* dArray);
//销毁动态数组
void Destroy_DynamicArray(DynamicArray* dArray);
//打印函数
void Print_DynamicArray(DynamicArray* dArray);
//修改指定位置的值
void Modify_DynamicArray(DynamicArray* dArray,int pos,int newvalue);



#endif