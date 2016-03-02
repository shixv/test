#include <iostream>
#include <memory>
using namespace std;
class A
{
	public:
	A(){cout<<"A()"<<endl;}
	~A(){cout<<"~A()"<<endl;}
};
int main(void)
{
	shared_ptr<A> a(new A);
	auto b=make_shared<A>();
	return 0;
}
