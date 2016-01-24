#include <iostream>

using namespace std;
int ga=10;

namespace spaceA
{
	int a=10;
	namespace C
	{
		int b=12;
	}
}

int main(void)
{
	cout<<ga<<endl;
	cout<<spaceA::a<<endl;
	cout<<spaceA::C::b<<endl;
	return 0;
}
