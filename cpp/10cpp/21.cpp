#include <iostream>

using namespace std;

template<class T>
class A
{
	public:
		A(T a)
		{
			this->a=a;
		}

		void print()
		{
			cout<<"a="<<a<<endl;
		}
	private:
		T a;
};
int main(void)
{
	A<int> a(10);
	a.print();
	return 0;
}


