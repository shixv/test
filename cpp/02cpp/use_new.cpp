#include <iostream>
int main(void)
{
	using namespace std;
	int *pt=new int;
	*pt=1001;

	cout<<"int ";
	cout<<"value = "<<*pt<<": location = "<<pt<<endl;

	double *pd=new double;
	*pd=100000001.0;

	cout<<"double ";
	cout<<"value = "<<*pd<<": location = "<<pd<<endl;
	cout<<"size of *pt = "<<sizeof(pt);
	cout<<": size of *pt = "<<sizeof(*pt)<<endl;
	cout<<"size of pd = "<<sizeof pd;
	cout<<": size of *pd = "<<sizeof(*pd)<<endl;
	return 0;
}
