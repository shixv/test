#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	fstream fs("txt");
	string str;
	char ch;
	while(fs.readsome(&ch,1)==1)str+=ch;
	cout<<str;

	regex r(R"(\b([a-zA-Z]+)\s+\1\b)");
	const sregex_token_iterator end;
	vector<int> vec{0,1};	
	for(sregex_token_iterator it(str.begin(),str.end(),r,vec);it!=end;++it){
		cout<<*it<<endl;
	}


	fs.seekp(0,ios_base::beg)<<str;
	return 0;
}
