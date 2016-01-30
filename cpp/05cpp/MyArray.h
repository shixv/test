#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;



//int ���͵�������
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
	int len; //�����������ռ�Ŀǰ�ܹ���ŵ�Ԫ�ظ���
	int *space; //space �ڶ��Ͽ�����������ռ���׵�ַ
};

