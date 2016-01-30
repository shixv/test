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

		//给space 开辟内存
		this->space = new int[this->len];

		cout << "调用了数组有参构造函数MyArray(int len)" << endl;
	}
}

MyArray::MyArray(const MyArray & another)
{
	if (another.len >= 0)
	{
		this->len = another.len;

		//深拷贝
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++)
		{
			this->space[i] = another.space[i];
		}

		cout << "执行了拷贝构造函数MyArray(const MyArray & another)" << endl;
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

		//开辟space空间
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++) {
			this->space[i] = another.space[i];
		}
	}
	
	cout << "调用了=重载操作符" << endl;
	return *this;
}

MyArray::~MyArray()
{
	//目的是释放 array 额外开辟的space空间
	if (this->space != NULL)
	{
		delete[] this->space;
		this->len = 0;
		this->space = NULL;
	}
	cout << "调用了数组的析构函数~MyArray()" << endl;
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
	os << "遍历了整个数组" << endl;

	for (int i = 0; i < array.getLen(); i++) { //array.getLen() ---> getLen(&const array)   默认的this形参 const MyArray * this
		os << array[i] << endl; //array.operator[](const &array), 
	}

	cout << "调用array的 <<重载" << endl;

	return os;
}

istream & operator>>(istream &is, MyArray &array)
{
	cout << "请输入 " << array.getLen() << "个数" << endl;
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
