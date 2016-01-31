#include <iostream>
using namespace std;

class A
{
	public:
		int m;
		void print(){cout<<"A\n";}
};
int main(void)
{
	A *pa=0;
	pa->print();
	return 0;
}
