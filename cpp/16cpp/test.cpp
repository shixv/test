#include <iostream>
using namespace std;
class A
{
	public:
		A(){}
	operator int(){return 12;}
	void operator=(int){}
};
int main(void)
{
	A a;
	a=1;
	cout<<sizeof(A)<<endl;
	cout<<a<<endl;
	return 0;
}
