#include <iostream>
using namespace std;
#ifndef MyVector
#define MyVector
class Teacher
{
	int id;
	char *name;
	public:
	friend ostream &operator<<(ostream &os,Teacher &t);
};
ostream &operator<<(ostream &os,Teacher &t)
{
	os<<"id="<<t.id<<",name="<<t.name;
	return os;
}
template <class T>
class MyVector
{
	public:
		MyVector();
		MyVector(int len);
		MyVector(const MyVector &another);
		~MyVector();

		MyVector &operator=(const MyVector &another);
		T &operator[](int n);
		friend ostream &operator<<(ostream &os,MyVector &vt);
	private:
		int len;
		T *space;
};
	template<class T>
MyVector<T>::MyVector()
{
	this->len=0;
	this=NULL;
}
	template<class T>
MyVector<T>::MyVector(int len)
{
	this->len=len;
	this->space=(T *)malloc(sizeof(T)*len);
	memset(this->space,0,sizeof(T)*len);
}
	template<class T>
MyVector<T>::MyVector(const MyVector &another)
{
	this->len=another.len;
	this->space=(T *)malloc(sizeof(T)*len);
	memcpy(this->space,another.space,(this->len)*sizeof(T));
}
	template<class T>
MyVector<T>::~MyVector()
{
	free(space);
	space=NULL;
	len=0;
}
	template<class T>
MyVector<T> &MyVector<T>::&operator=(const MyVector<T> &another)
{
	this->len=another.len;
	this->space=(T *)malloc(sizeof(T)*len);
	memcpy(this->space,another.space,(this->len)*sizeof(T));
	return *this;
}
	template<class T>
T &MyVector<T>::operator[](int n)
{
	return *(vt.space+n);
}
	template<class T>
friend ostream &operator<< <T>(ostream &os,MyVector<T> &vt)
{
	for(int i=0;i<vt->len;i++)
		os<<vt->(space+i)<<endl;
}
#endif
