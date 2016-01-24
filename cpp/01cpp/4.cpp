#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

void chan(int &a)
{
	a=10;
}
int &ret(int &a)
{
	return a;
}
int main(void)
{
	int a=10;
	int &b=a;
	b=12;
	cout<<a<<endl;
	chan(b);
	cout<<b<<endl;
	ret(a)=2;
	cout<<a<<endl;
	cout<<pow(7.0,8.0)<<endl;
	cout<<rand()<<endl;
	return 0;
}
