#include <iostream>
using namespace std;
void mySwap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void printfAB(int &a,int &b)
{
	cout<<"a="<<a<<",b= "<<b<<endl;
}
int main(void)
{
	int a=10;
	int b=20;
	printfAB(a,b);
	mySwap(a,b);
	printfAB(a,b);
	return 0;
}
