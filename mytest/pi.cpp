#include <iostream>
using namespace std;

int main(void)
{
	const char* formula=u8"\u03c0r\u00b2";
	cout<<formula<<endl;
	wcout.imbue(locale(""));
	wcout<<12345<<endl;
	return 0;
}
