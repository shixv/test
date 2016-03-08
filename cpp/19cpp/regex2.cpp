#include <regex>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//using namespace regex_constants;
int main(void)
{
	string str;
	fstream fs("txt");
	char ch;
	while(fs.readsome(&ch,1)==1)str+=ch;

	regex r(R"(shixv(.+)shixv)");
	const sregex_iterator end;
	for(sregex_iterator it(str.begin(),str.end(),r);it!=end;++it){
		cout<<(*it)[1]<<endl;
	}


	
	fs.seekp(0,ios_base::beg)<<str;
	return 0;
}
