#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
template <class T>
class A
{
public:
	A(T a)
	{
		this->a = a;
	}
	void print()
	{
		cout << "a = " << a << endl;
	}
private:
	T a;
};
//类B继承类A
//直接继承已经实例化的类A
//类B 此时就是一个 普通类
class B :public A<int>
{
public:
	B(int a, int b) :A<int>(a)
	{
		this->b = b;
	}
	void printB()
	{
		cout << "b = " << b << endl;
	}
private:
	int b;
};
//类C  继承于类A
//如果c类继承的是一个没有实例化的模板类
//此时c也是一个模板类
template <typename T>
class C : public A<T>
{
public:
	C(T a, T b) :A<T>(a)
	{
		this->b = b;
	}
	void printC()
	{
		cout << "c = " << b << endl;
	}
private:
	T b;
};
//将func定义成一个普通函数
//普通函数
void func(A<int> a)
{
}
//此时func是一个模板函数
//模板函数
template<class T>
void func(A<T> a)
{
}
int main(void)
{
	A<int> a(10);
	A<int> *ap = new A<int>(10);
	a.print();
	func(a);
	func<int>(a);
	cout << " -----" << endl;
	B b(100, 200);
	B *bp = new B(100, 200);
	b.printB();
	cout << " ----- " << endl;
	C<int> c(10, 20);
	c.printC();
	C<int> *cp = new C<int>(100, 200);
	cp->printC();
	delete cp;
	return 0;
}
