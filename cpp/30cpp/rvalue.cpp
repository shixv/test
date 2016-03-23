#include <iostream>
using namespace std;
int main(void)
{
	int &&i=2;
	int a=2;
	int b=3;
	int&& j=a+b;
	cout<<i<<j<<endl;
	j=1;
	cout<<j<<endl;
	i=1;
	cout<<i<<endl;
	return 0;
}
