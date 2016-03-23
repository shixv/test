#include <regex>
#include <fstream>
#include <iostream>
using namespace std;
int main(void)
{
	ifstream ifs("dict.txt");
	string buf;
	char ch;
	while(ifs.readsome(&ch,1)==1)buf+=ch;
	regex r1(R"(Trans:[^\n\r]*\r\n)");	
	regex r2(R"(\r?\n?#[^a-zA-Z][^\r\n]*\r?\n?)");
	regex r3(R"(#)");
	regex r4(R"(\r)");
	const string format("");
	buf=regex_replace(buf,r1,format);
	buf=regex_replace(buf,r2,format);
	buf=regex_replace(buf,r3,format);
	buf=regex_replace(buf,r4,format);
	ifs.close();	
	ofstream ofs("dict.txt");
	ofs<<buf;
	ofs.close();
	return 0;
}
