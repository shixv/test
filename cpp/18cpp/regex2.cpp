#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(void)
{
	regex r(R"(^He.*$)");
	string str;
	cin>>str;
	if(regex_match(str,r))
		cout<<"yes."<<endl;
	else
		cout<<"no."<<endl;
	return 0;
}
