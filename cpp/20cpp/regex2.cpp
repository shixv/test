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

	regex r(R"(\$[0-9]+(\.[0-9][0-9])?)");
	const sregex_token_iterator end;
	for(sregex_token_iterator it(str.begin(),str.end(),r);it!=end;++it){
		cout<<*it<<endl;
	}
	
	fs.seekp(0,ios_base::beg)<<str;
	return 0;
}
