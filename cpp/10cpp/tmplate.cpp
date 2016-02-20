#include <iostream>
using namespace std;
template<class T>
void mySwap(T &a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}
int main(void)
{
	int a=10;
	int b=20;

	cout<<a<<","<<b<<endl;
	mySwap<int>(a,b);
	cout<<a<<","<<b<<endl;
	char x='x';
	char y='y';
	cout<<x<<","<<y<<endl;
	mySwap<char>(x,y);
	cout<<x<<","<<y<<endl;

	return 0;
}
