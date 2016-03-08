#ifndef DY_H
#define DY_H

typedef struct _Dynamicarray{
	int* address;
	int capacity;
	int size;
}Darray;

Darray* Init_Darray();
int Length_Darray(Darray* darray);
int isEmpty(Darray* darray);
int Capacity_Darray(Darray* darray);
void Insert_Darray(Darray* darray,int pos,int data);
void Remove_Darray(Darray* darray,int pos);
void Clear_Darray(Darray* darray);
void Destroy_Darray(Darray* darray);
void Print_Darray(Darray* darray);
void Modify_Darray(Darray* darray,int pos,int newvalue);

#endif
