#include <iostream>
int main(void)
{
	using namespace std;
	cout<<"Enter the starting countdown value: ";
	int limit;
	cin>>limit;
	int i=0;
	for(i=limit;i;i--)
		cout<<"i = "<<i<<"\n";
	cout<<"Done now that i = "<<i<<"\n";
	return 0;
}
