#include <iostream>
using namespace std;
int test(int& a)
{
	cout<<"left value"<<endl;
	a=10;
	return a;
}
int  test(int&& a)
{
	cout<<"right value"<<endl;
	a=10;
	return a;
}
int main(void)
{
	int a=1;
	int b=2;
	test(move(a));
	cout<<a<<endl;	
	cout<<test(3)<<endl;
	
	test(1+a);
	test(a+b);
	test(2);
	test(1+2);
	return 0;
}
