#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
	int n_int=INT_MAX;
	short n_short=SHRT_MAX;
	long n_long=LONG_MAX;

	cout<<"int is "<<sizeof(int)<<" bytes."<<endl;
	cout<<"short is "<<sizeof(short)<<" bytes."<<endl;
	cout<<"long is "<<sizeof(long)<<" bytes."<<endl;

	cout<<"Maximum values:"<<endl;
	cout<<"int: :"<<n_int<<endl;
	cout<<"short: "<<n_short<<endl;
	cout<<"long "<<n_long<<endl<<endl;

	cout<<"Minimum int value = "<<INT_MIN<<endl;
	cout<<"Bit per byte = "<<CHAR_BIT<<endl;
	return 0;
}
