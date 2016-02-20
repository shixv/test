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
		void print(void)
		{
			cout<<a<<endl;
		}
	private:
		T a;
};

template<class T>
void test(int a, A<T> *b)//b.copy(Ani)
{
	delete b;
	return;
}
int main(void)
{
	A a1(12)
	test<int>(1,new A<int>(13));
	return 0;
}

