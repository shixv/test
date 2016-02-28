#include <iostream>
using namespace std;

class A
{
	public:
	A(){};
	A(int a){};
	A(const A& a){};
	public:
	bool operator()(int a){
		return a>5;
	}
};
	
int main(void)
{
	A a(2);
	a(2);
	cout<<a(2)<<endl;
	return 0;
}
