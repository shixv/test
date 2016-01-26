#include <iostream>

using namespace std;

class Test
{
	public:
		int x;
		Test(int n)
		{
			x=n;
			cout<<"Test n"<<endl;
		}
		Test(const Test &t)
		{
			x=t.x;
			cout<<"Test &t"<<endl;
		}
};
int main(void)
{
	Test t1(1);
	Test t2=t1;
	return 0;
}
