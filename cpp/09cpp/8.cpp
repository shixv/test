#include <iostream>
using namespace std;
template<typename T>
void mySwap(T &a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}
template<typename T>
void printAB(T &a,T &b)
{
	cout<<"a= "<<a<<",b="<<b<<endl;
}
int main(void)
{
	int a=10;
	int b=20;
	printAB<int>(a,b);	
	mySwap<int>(a,b);
	printAB<int>(a,b);
	char x='a';
	char y='b';
	printAB<char>(x,y);
	mySwap<char>(x,y);
	printAB<char>(x,y);
	double d1=30.0;
	double d2=40.0;
	printAB<double>(d1,d2);
	mySwap<double>(d1,d2);
	printAB<double>(d1,d2);
	return 0;
}
