#include "MyArray.h"


MyArray::MyArray()
{
	this->space = NULL;
	this->len = 0;
}

MyArray::MyArray(int len)
{
	if (len <= 0) {
		this->len = 0;
		return;
	}
	else {
		this->len = len;

		//��space �����ڴ�
		this->space = new int[this->len];

		cout << "�����������вι��캯��MyArray(int len)" << endl;
	}
}

MyArray::MyArray(const MyArray & another)
{
	if (another.len >= 0)
	{
		this->len = another.len;

		//���
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++)
		{
			this->space[i] = another.space[i];
		}

		cout << "ִ���˿������캯��MyArray(const MyArray & another)" << endl;
	}
}

MyArray & MyArray::operator =(const MyArray &another)
{
	//
	if (this->space != NULL) {
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
	}

	if (another.len > 0)
	{
		this->len = another.len;

		//����space�ռ�
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++) {
			this->space[i] = another.space[i];
		}
	}
	
	cout << "������=���ز�����" << endl;
	return *this;
}

MyArray::~MyArray()
{
	//Ŀ�����ͷ� array ���⿪�ٵ�space�ռ�
	if (this->space != NULL)
	{
		delete[] this->space;
		this->len = 0;
		this->space = NULL;
	}
	cout << "�������������������~MyArray()" << endl;
}


void MyArray::setData(int index, int value)
{
	if (this->space != NULL)
	{
		this->space[index] = value;
	}
}

int MyArray::getData(int index)
{
	return this->space[index];
}

int& MyArray::operator[](int index) const
{
	return this->space[index];
}


ostream & operator<<(ostream &os, const MyArray &array)
{
	os << "��������������" << endl;

	for (int i = 0; i < array.getLen(); i++) { //array.getLen() ---> getLen(&const array)   Ĭ�ϵ�this�β� const MyArray * this
		os << array[i] << endl; //array.operator[](const &array), 
	}

	cout << "����array�� <<����" << endl;

	return os;
}

istream & operator>>(istream &is, MyArray &array)
{
	cout << "������ " << array.getLen() << "����" << endl;
	for (int i = 0; i < array.getLen(); i++) {
		cin >> array[i];
	}

	return is;
}

bool MyArray::operator==(MyArray &another)
{
	if (this->len != another.len) {
		return false;
	}
	else {
		for (int i = 0; i < this->len; i++) {
			if (this->space[i] != another.space[i]) {
				return false;
			}
		}

		return true;
	}
}

bool MyArray::operator!=(MyArray &another)
{
	return !(*this == another);
}
