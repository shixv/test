#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)..." << endl;
		this->a = a;
		print();// 此处 调用的是父类的print 还是 子类的print？
					//调用的是父类的print函数 为什么？
					//原因 只有 此时的子类的vptr指针指向的是父类的虚函数表
	}
	virtual void print()
	{
		cout << "Parent Print()... a = "  <<a << endl;
	}
	virtual ~Parent()
	{
	}
private:
	int a;
};
class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)
	{
		cout << "Child (int ,int )..." << endl;
		this->b = b;
		//在此处， vptr指针已经由指向父类的虚函数表转向了 子类的虚函数表
		print();//调用的是父类的 还是子类的
		//建议 不要在构造函数中 调用虚函数 来发生多态， 也最好不要在构造函数中写业务。
	}
	virtual void print()
	{
		cout << "Child Print().. b =" << b << endl;
	}
	~Child()
	{
	}
private:
	int b;
};
int main(void)
{
	Parent *pp = new Child(10, 20);
	pp->print(); //发生多态 会调用Child 的print函数
	delete pp;
	return 0;
}
