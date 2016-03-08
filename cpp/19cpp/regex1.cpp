#include <regex>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
using namespace regex_constants;
int main(void)
{
	string str;
	char ch;
	fstream fs("txt");
	while(fs.readsome(&ch,1)==1)str+=ch;

//	regex r(R"((?:\d\d\d\d)-(?:1[1-2]|0[1-9])-(?:0[1-9]|[1-2][1-9]|3[0-2]))");
	regex r(R"(^12\n$)");
	cout<<str;
	if(regex_match(str,r))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	fs.seekp(0,ios_base::beg)<<str;
	return 0;
}
