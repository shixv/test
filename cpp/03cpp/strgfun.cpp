#include <iostream>

int c_in_str(const char *str,char ch);
int main(void)
{
	using namespace std;
	char mmm[15]="minimum";
	char wail[]="ululate";
	char *wail1="ululate";

	int ms=c_in_str(mmm,'m');
	int us=c_in_str(wail,'u');
	cout<<ms<<" m characters in "<<mmm<<endl;
	cout<<us<<" u characters in "<<wail<<endl;
	cout<<wail1<<endl;
	return 0;
}
int c_in_str(const char *str,char ch)
{
	int count=0;

	while(*str)
	{
		if(*str==ch)
			count++;
		str++;
	}
	return count;
}
