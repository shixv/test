#include "darray.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Darray* Init_Darray()
{
	Darray* darray=(Darray*)malloc(sizeof(Darray));
	if(darray==NULL){
		return NULL;
	}
	darray->capacity=20;
	darray->size=0;
	darray->address=(int*)malloc(darray->capacity*sizeof(int));
	if(darray->address==NULL){
		free(darray);
		return NULL;
	}
	memset(darray->address,0,sizeof(int)*darray->capacity);
	return darray;
}
int Length_Darray(Darray* darray)
{
	if(darray==NULL)
	return -1;
	return darray->size;
}
int isEmpty(Darray* darray)
{
	if(darray==NULL)
		return -1;
	return darray->size==0;
}
int Capacity_Darray(Darray* darray)
{
	if(darray==NULL)
		return -1;
	return darray->capacity;
}
void Insert_Darray(Darray* darray,int pos,int data)
{
	if(darray==NULL){
	return;
	}
	if(pos<0){
		return;
	}
	if(pos>darray->size){
		pos=darray->size;
	}
	if(darray->size==darray->capacity){
		int* newspace=malloc(darray->capacity*2*sizeof(int));
		if(newspace==NULL)
			return;
		memcpy(newspace,darray->address,sizeof(int)*darray->capacity);
		free(darray->address);
				darray->address=newspace;
		darray->capacity =darray->capacity*2;
	}
	for(int i=darray->size-1;i>=pos;i--){
		darray->address[i+1]=darray->address[i+1];
	}
	darray->address[pos]=data;
	darray->size++;
}
void Remove_Darray(Darray* darray,int pos)
{
	if(darray==NULL){
		return;
	}
	if(pos<0||pos>=darray->size-1){
	return;
	}
	for(int i=pos;i<darray->size-1;i++){
		darray->address[i]=darray->address[i+1];
	}
	darray->size--;
}
void Clear_Darray(Darray* darray)
{
	if(darray==NULL)
		return;
	darray->size=0;
}
void Destroy_Darray(Darray* darray)
{
	if(darray==NULL)
		return;
	if(darray->address!=NULL)
	free(darray->address);
	free(darray);
	darray=NULL;
}
void Print_Darray(Darray* darray)
{
	for(int i=0;i<darray->size;i++){
		printf("%d ",darray->address[i]);
	}
	printf("--------------\n");
}
void Modify_Darray(Darray* darray,int pos,int newvalue)
{
	if(darray==NULL){
		return;
	}
	if(pos<0||pos>darray->size)
		return;
	darray->address[pos]=newvalue;
}
