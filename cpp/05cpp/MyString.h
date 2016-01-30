#include <iostream>
using std::ostream;
using std::istream;
class MyString
{
private:

	char *str; //�ڶ��Ͽ���һ���ַ�������Ŀռ䣬 ��strָ������ռ���׵�ַ
	int len; //�ַ����ĳ���

public:
	MyString();
	MyString(int len);
	MyString(const char *str);
	MyString(const MyString& another);

	~MyString();

	//���ز�����[]
	char &operator[](int n);
	//���ز�����=
	MyString &operator=(MyString &);
	//���ز�����<<
	friend ostream &operator<<(ostream &os,const MyString &str);
	//���ز�����>>
	friend istream &operator>>(istream &is,const MyString &str);
	//���ز�����== ��=
	bool operator==(const MyString &);
	bool operator!=(const MyString &);
};

