#include <regex>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc,char* argv[])
{
	fstream fs(argv[1]);
	string str;
	char ch;
	while(fs.read(&ch,1).good())str+=ch;
	regex r(R"(\n\s*\n)");
	cout<<regex_replace(str,r,"");
	return 0;
}
