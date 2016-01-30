#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

class A
{
	private:
		int a;
	public:
		void *operator new[](size_t n)
		{
			cout<<n<<endl;
			return malloc(n);
		}
		A()
		{
			this->a=0;
		}
		A(int a)
		{
			this->a=a;
		}
};

int main(void)
{
	A a(2);
	A *b=new A[20];
	return 0;
}
auto_ptr<A> ptr(new A);
