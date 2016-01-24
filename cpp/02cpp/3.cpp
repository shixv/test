#include <iostream>

using namespace std;

void print(int a=10)
{
	cout<<a<<endl;
}
void print(int a,int b)
{
	cout<<a<<","<<b<<endl;
}
int main(void)
{
	print(12,12);
	return 0;
}
