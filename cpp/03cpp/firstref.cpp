#include <iostream>
int main(void)
{
	using namespace std;
	int rats=101;
	int &rodents=rats;

	cout<<"rats="<<rats;
	cout<<",rodents="<<rodents<<endl;
	rodents++;
	cout<<"rats="<<rats;
	cout<<",rodents="<<rodents<<endl;

	cout<<"rats address="<<&rats;
	cout<<",rodnets address="<<&rodents<<endl;
	return 0;
}
