#include <iostream>

using namespace std;

void ref(int &x)
{
	x+=1;
}
int main(void)
{
	int a=1;
	ref(a+a);
	return 0;
}
