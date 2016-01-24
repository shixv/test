#include <iostream>

using namespace std;

int &test(int &a)
{
	a=0;
	return a;
}

int main(void)
{
	int a=12;
	test(a)=10;
	cout<<a<<endl;
	return 0;
}
