#include <regex>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc,char* argv[])
{
	string str;
	fstream fs(argv[1]);
	char ch;
	while(fs.read(&ch,1).good())str+=ch;

	regex r(R"((<)?\w(?(1)>))");
	string match("");
	cout<<regex_replace(str,r,match);
	
	return 0;
}
