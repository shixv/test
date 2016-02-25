#include <iostream>
using namespace std;
class A
{
	public:
	int a;
	public:
	A():a(1){}
	A(int n):a(n){}
	A(const A &another)
	{
		a=another.a;
	}
	void swap(A &another)
	{
		if(1)
			throw 1;
		a^=(another.a);
		(another.a)^=a;
		a^=(another.a);
	}
};
void swap(A &x,A &y)noexcept(noexcept(x.swap(y)))
{
	x.swap(y);
}
int main(void)
{
	A x(1);
	A y(2);
	try{
	swap(x,y);
	}catch(...)
	{
		cout<<"except!"<<endl;
	}
	cout<<x.a<<","<<y.a<<endl;
	return 0;
}
