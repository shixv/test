#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<stdlib.h>
#include<stdio.h>

//��̬���ݽṹ��
typedef struct _DYNAMICARRAY{
	int* address; //���ݵ�ַ
	int capacity; //����
	int size; //���鳤��
}DynamicArray;


//��ʼ����̬���飬������̬����
DynamicArray* Init_DynamicArray();
//��ö�̬����ĳ���
int Length_DynamicArray(DynamicArray* dArray);
//�ж϶�̬�����Ƿ�Ϊ��
int IsEmpty_DynamicArray(DynamicArray* dArray);
//��ö�̬���������
int Capacity_DynamicArray(DynamicArray* dArray);
//��̬�����������
void Insert_DynamicArray(DynamicArray* dArray,int pos,int data);
//ɾ��ָ��λ�õ�����
void Remove_DynamicArray(DynamicArray* dArray, int pos);
//�������
void Clear_DynamicArray(DynamicArray* dArray);
//���ٶ�̬����
void Destroy_DynamicArray(DynamicArray* dArray);
//��ӡ����
void Print_DynamicArray(DynamicArray* dArray);
//�޸�ָ��λ�õ�ֵ
void Modify_DynamicArray(DynamicArray* dArray,int pos,int newvalue);



#endif