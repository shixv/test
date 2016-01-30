#include <iostream>
using std::ostream;
using std::istream;
class MyString
{
private:

	char *str; //在堆上开辟一个字符串数组的空间， 让str指向这个空间的首地址
	int len; //字符串的长度

public:
	MyString();
	MyString(int len);
	MyString(const char *str);
	MyString(const MyString& another);

	~MyString();

	//重载操作符[]
	char &operator[](int n);
	//重载操作符=
	MyString &operator=(MyString &);
	//重载操作符<<
	friend ostream &operator<<(ostream &os,const MyString &str);
	//重载操作符>>
	friend istream &operator>>(istream &is,const MyString &str);
	//重载操作符== ！=
	bool operator==(const MyString &);
	bool operator!=(const MyString &);
};

