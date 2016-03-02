#include <iostream>
using namespace std;
int main(void)
{
	char a='e';
	char&& b=char('a');
	a=b;
	cout<<sizeof(b)<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}
