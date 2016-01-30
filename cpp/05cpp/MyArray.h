#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;



//int 类型的数组类
class MyArray
{
public:
	MyArray();
	MyArray(int len);
	~MyArray();
	MyArray(const MyArray & another);

	void setData(int index, int value);
	int getData(int index);

	int& operator[](int index) const ;

	MyArray & operator =(const MyArray &another);

	bool operator==(MyArray &another);
	bool operator!=(MyArray &another);

	int getLen() const
	{
		return this->len;
	}
	friend ostream & operator<<(ostream &os, const MyArray &array);
	friend istream & operator>>(istream &is, MyArray &array);

private:
	int len; //这个连续数组空间目前能够存放的元素个数
	int *space; //space 在堆上开辟连续数组空间的首地址
};

