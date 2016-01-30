#include <cstdlib>
#include "MyArray.h"
MyArray::MyArray()
{
	len=0;
	space=NULL;
}

MyArray::MyArray(int length)
{
	len=length;
	space=new int[len];
}

MyArray::~MyArray()
{
	if(space!=NULL){
		delete[] space;
		space=NULL;
	}
}
MyArray::MyArray(const MyArray &another)
{
	space=new int[another.len];
	for(int i=0;i<another.len;i++)
		space[i]=another.space[i];
}
void MyArray::setData(int index,int value)
{
	space[index]=value;
}
int MyArray::getData(int index)
{
	return space[index];
}
