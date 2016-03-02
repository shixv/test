#include <iostream>
#include <memory>
#include <cstdlib>
using namespace std;
int* malloc_int(int value)
{
	int* p=(int*)malloc(sizeof(int));
	*p=value;
	cout<<"fuck"<<endl;
	return p;
}
int main(void)
{
	shared_ptr<int> myIntSmartPtr(malloc_int(42),free);
	return 0;
}
