#include <regex>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str;
	fstream fs("txt");
	char ch;
	while(fs.readsome(&ch,1)==1)str+=ch;

	regex r(R"(([\w]+)\s*=\s*([\w]+))");
	const sregex_iterator end;
	for(sregex_iterator it(str.begin(),str.end(),r);it!=end;++it){
		cout<<(*it)[1]<<"="<<(*it)[2]<<endl;
	}



	fs.seekp(0,ios_base::beg)<<str;
	return 0;
}
