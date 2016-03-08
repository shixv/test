#include <regex>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(void)
{
	string str;
	char ch;
	fstream fs("txt");
	while(fs.readsome(&ch,1)==1)str+=ch;

	regex r(R"(([\w]+)\s*=\s*([\w]+))");
	string format("$1=$2");
	str=regex_replace(str,r,format);


	fs.seekp(0,ios_base::beg)<<str;
	return 0;
}
