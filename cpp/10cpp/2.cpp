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
//��B�̳���A
//ֱ�Ӽ̳��Ѿ�ʵ��������A
//��B ��ʱ����һ�� ��ͨ��
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
//��C  �̳�����A
//���c��̳е���һ��û��ʵ������ģ����
//��ʱcҲ��һ��ģ����
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
//��func�����һ����ͨ����
//��ͨ����
void func(A<int> a)
{
}
//��ʱfunc��һ��ģ�庯��
//ģ�庯��
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
