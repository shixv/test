#include <iostream>

using namespace std;
typedef void(*RET)(int);
RET ret(int a)
{
	cout<<a<<endl;
	return ;
}
int main(void)
{
	ret(6)(7);
	return 0;
}
