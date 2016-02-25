#include <iostream>
using namespace std;

class A
{
	public:
		int n;
		A(int a):n(a){}
		A():n(0){}
		A(const A& a){}
};
void foo(const int& a)
{
	cout<<a<<endl;
}
int main(void)
{
	const int b=2;
	foo(b);
	return 0;
}
