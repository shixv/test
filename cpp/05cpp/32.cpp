#include <iostream>

using namespace std;

class Sqr
{
	public:
		Sqr(int a)
		{
			this->a=a;
		}
		int operator()(int value,int value2)
		{
			return this->a*value;
		}
	private:
		int a;
};

int main(void)
{
	Sqr s(10);

	s(10,20);
	return 0;
}
