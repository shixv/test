#include <iostream>

using namespace std;

void ref(int &);
int main(void)
{
	return 0;
}
void ref(int &a)
{
	a=6;
}
