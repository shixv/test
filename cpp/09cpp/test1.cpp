#include <iostream>

using namespace std;

void print(int a,int b=0,int c=0)
{
	cout<<a<<","<<b<<","<<c<<endl;
}
int main(void)
{
	print(1,2);
	return 0;
}
