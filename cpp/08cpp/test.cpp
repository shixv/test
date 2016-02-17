#include <iostream>
using namespace std;
class A
{
	class B
	{
		class C
		{
			C(int a):n(a){}
			int n;
		};
		B(int a):C::a(n){}
	};
	A(int a):B(a){}
};
int main(void)
{
	A a;
	cout<<sizeof(a)<<endl;
	return 0;
}
