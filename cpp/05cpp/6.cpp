#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

#include <memory>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A().." << endl;
		a = 0;
	}
	A(int a)
	{
		cout << "A(int) ..." << endl;
	}
	~A() {
		cout << "~A()... " << endl;
	}

	void func()
	{
		cout << "func().. a= " << a << endl;
	}
private:
	int a;
};

class MyAutoPtr
{
public:
	MyAutoPtr(A* ptr)
	{
		this->ptr = ptr;
	}
	~MyAutoPtr()
	{
		if (this->ptr != NULL) {
			delete ptr;
		}
	}

	//重载->操作符
	A* operator->()
	{
		return ptr;
	}
	A & operator*()
	{
		return *ptr;
	}
private:
	A *ptr; //ptr = new A;
};

void test1()
{
	//智能指针
	auto_ptr<A>  ptr(new A);

	ptr->func();
	(*ptr).func();

	//A* ap = new A;

	//ap->func();

	//delete ap;
}

void test2()
{
	MyAutoPtr my_p(new A);

	my_p->func(); //ptr->func();

	(*my_p).func();  //A对象本身.func()
}

int main(void)
{

	//test1();
	test2();

	
	return 0;
}
