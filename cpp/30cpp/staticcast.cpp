#include <iostream>
using namespace std;
class Base
{
	public:
		Base(){};
		virtual ~Base(){}
};
class Derived:public Base
{
	public:
		Derived(){}
		virtual ~Derived(){}
};
int main(void)
{
//	Base* b;
//	Derived* d=new Derived();
	Base b;
	Derived d;
//	b=d;
//	d=static_cast<Derived*>(b);
	auto d1=reinterpret_cast<Derived*>(&b);
	Base base;
	Derived derived;
	Base& br=derived;
	Derived& dr=static_cast<Derived&>(br);
	return 0;
}
