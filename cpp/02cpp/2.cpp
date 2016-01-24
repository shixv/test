#include <iostream>

using namespace std;

int func1(int,int);
double func1(double,double);
int main(void)
{
	func1(2,3);
	func1(2.1,3.2);
	return 0;
}
int func1(int a,int b)
{
	return a+b;
}
double func1(double a,double b)
{
	return a+b;
}
