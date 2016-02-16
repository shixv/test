#include <iostream>

using namespace std;

class A
{
  public:
	void funcA()
	{
	  cout<<"funcA()"<<endl;
	}
	int a;
};

class B
{
  public:
	void funcB()
	{
	  a.funcA();
	}
	A a;
};

class C
{
  public:
	void funcC(A *a)
	{
	  a->funcA();
	}
};

class D:public A
{
  public:
	void funcD();
	{
	  funcA();
	  cout<<a<<endl;
	}

	int b;
};

class E:public D
{
};

int main(void)
{

