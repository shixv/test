#include <iostream>

using namespace std;

void fun(int a=999)
{
	cout<<"func: x= "<<a<<endl;
}
int volume(int len=100,int width=100,int heigh=99)
{
	return len*width*heigh;
}
void func2(int x,int)
{
	cout<<"func2:x="<<x<<endl;
}
int main(void)
{
	int a=10;
	int l=10;
	int w=20;
	int h=20;
	fun(a);
	fun();
	int v=0;
	v=volume();
	cout<<v<<endl;
	func2(2);
	return 0;
}
