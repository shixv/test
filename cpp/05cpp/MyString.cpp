#include "MyString.h"
#include <cstring>



MyString::MyString()
{
	this->str=NULL;
	this->len=0;
}
MyString::MyString(int len)
{
	if(len<1)
		return;
	this->str=new char[len];
	this->len=len;
}
MyString::MyString(const char *str)
{
	if(str==NULL)
		return;
	this->len=strlen(str);
	this->str=new char[this->len];
	strncpy(this->str,str,this->len);
}
MyString::MyString(const MyString &another)
{
	this->len=another.len;
	this->str=new char[another.len];
	strncpy(this->str,another.str,this->len);
	
}
char &MyString::operator[](int n)
{
	if(n>this->len-1)
		return str[len-1];
	return this->str[n];
}
MyString &MyString::operator=(MyString &another)
{
	if(this==&another)
		return *this;
	this->len=another.len;
	char *temp=new char[another.len];
	strncpy(temp,another.str,this->len);
	if(this->str!=NULL)
		delete[] str;
	this->str=temp;
	return *this;
}
ostream &operator<<(ostream &os,const MyString &another)
{
	os<<another.str;
	return os;
}
istream &operator>>(istream &is,const MyString &another)
{
	is>>another.str;
	return is;
}
bool MyString::operator==(const MyString &another)
{
	for(int i=0;i<this->len;i++)
	{
		if(this->str[i]==another.str[i])
			continue;
		else
			return false;
	}
	return true;
}
bool MyString::operator!=(const MyString &another)
{
	return !(*this==another);
}
MyString::~MyString()
{
	if(this->str==NULL)
		return;
	delete[] this->str;
	this->str=NULL;
}
