#include "myarray.h"

MyArray::MyArray()
{
	this->space=NULL;
	this->len=0;
}

MyArray::MyArray(int len)
{
	if(len<=0)
	{
		this->len=0;
		return;
	}
	else
	{
		this->len=len;
		this->space=new int[this->len];
		cout<<"constructer len"<<endl;
	}
}
bool MyArray::operator==(MyArray &another)
{
	if(this->len!=another.len)
	{
		return false;
	}
	else
	{
		for(int i=0;i<this->len;i++)
		{
			if(this->space[i]!=another.space[i])
			{
				return false;
			}
		}
		return true;
	}
}

bool MyArray::operator!=(MyArray &another)
{
	return !(*this==anther);
}
