#include <iostream>

using namespace std;

class A
{
	private:
		int m_a;
	public:
		A(int a)
		{
			m_a=a;
		}
};

class B
{
	public:
		B(int b,int a11,int a22):a2(a22),m_b(b),a1(a11){}
	private:
		int m_b;
	public:
		A a1;
		A a2;
};

int main(void)
{
	return 0;
}
