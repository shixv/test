#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main(void)
{
	string str;
	fstream fs("txt");
	char ch;
	while(fs.readsome(&ch,1)==1)str+=ch;
	regex r(R"(.*((?:[01][1-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]).*)");
	const sregex_token_iterator end;
	fs.seekp(0,ios_base::beg);
	vector<int> vec{1};
	for(sregex_token_iterator it(str.begin(),str.end(),r,vec);it!=end;++it){
		cout<<*it<<endl;
	}
	return 0;
}
