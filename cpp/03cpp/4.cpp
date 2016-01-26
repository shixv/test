#include <iostream>

using namespace std;

class A
{
	public:
		int a;
	    A(int n)
		{
			a=n;
		}
};
int main(void)
{
	A a(3);
	cout<<a.a<<endl;
	return 0;
}
